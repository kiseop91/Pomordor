#include "pompch.h"

#include "TimerPage.h"
#include "ui_TimerPage.h"

#include "ScheduleDialog.h"
#include "TrayIcon.h"

TimerPage::TimerPage(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::TimerPage)
	, m_Loop(new QTimer)
	, m_ScheduleDialog(new ScheduleDialog(this))
	, m_TrayIcon(new TrayIcon(QIcon(":/icon/Tomato"), this))
	, m_CurState(TimerState::None)
{
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setAutoFillBackground(true);

	QFont d2code("D2Coding");
	QFont segoe("Segoe UI");
	ui->TimerButton->setFont(d2code);
	ui->TimerStateLabel->setFont(segoe);
	ui->SetCountLabel->setFont(segoe);
	setTimerStateUi(m_CurState);

	updateTimerData();
	fillProgress(0.999f, m_CurState);
	
	m_PlayButtonConn = connect(ui->PlayButton, SIGNAL(clicked()), SLOT(onStart()));
	connect(ui->TimerButton, SIGNAL(clicked()), this, SLOT(onProp()));
	connect(ui->Title_Close, &QPushButton::clicked, [this]() { hide(); m_ScheduleDialog->hide(); });
	
	connect(m_Loop, SIGNAL(timeout()), this, SLOT(onRunning()));
}

void TimerPage::updateTimerData()
{
	auto[pormTime, breakTime, NumSets] = m_ScheduleDialog->GetData();
	m_ScheduleQueue.clear();
	for (auto i = 0; i < NumSets; ++i)
	{
		m_ScheduleQueue.emplace_back(TimerState::Porm, pormTime);
		m_ScheduleQueue.emplace_back(TimerState::Break, breakTime);
	}
	m_SetTotal = NumSets;

	QString timeText;
	if (pormTime < 10)
	{
		timeText += '0';
	}
	timeText += QString::number(pormTime) + ":00";
	ui->TimerButton->setText(timeText);
	updateSetCount();
}

void TimerPage::updateSetCount()
{
	uint32_t setCount = m_SetTotal - (m_ScheduleQueue.size() + 1) / 2 + 1;
	if (m_CurState == TimerState::None)
		setCount = 0;
	QString setStr = "Set Count : " + QString::number(setCount) + " / " + QString::number(m_SetTotal);
	ui->SetCountLabel->setText(setStr);
}

void TimerPage::fillProgress(float percentage, TimerState state)
{
	switch (state)
	{
	case TimerPage::TimerState::Porm: SSProgress = SSProgress_Porm; break;
	case TimerPage::TimerState::Break: SSProgress = SSProgress_Break; break;
	case TimerPage::TimerState::None: SSProgress = SSProgress_Porm; break;
	}

	SSProgress.replace(QString("{GradPoint_1}"), QString::number(percentage));
	SSProgress.replace(QString("{GradPoint_2}"), QString::number(percentage + 0.0001f));
	ui->Progress_Front->setStyleSheet(SSProgress);
}

void TimerPage::setTimerStateUi(TimerState state)
{
	switch (state)
	{
	case TimerPage::TimerState::Break:
		ui->TimerStateLabel->setText("Break");
		ui->TimerStateLabel->setStyleSheet(SSTimerState_Break);
		ui->TimerButton->setStyleSheet(SSTimerButton_Break);
		ui->Progress_Back->setStyleSheet(SSProgress_Break_bg);
		break;
	case TimerPage::TimerState::Porm:
		ui->TimerStateLabel->setText("Running");
		ui->TimerStateLabel->setStyleSheet(SSTimerState_Porm);
		ui->TimerButton->setStyleSheet(SSTimerButton_Porm);
		ui->Progress_Back->setStyleSheet(SSProgress_Porm_bg);
		break;
	case TimerPage::TimerState::None:
		ui->TimerStateLabel->setText("Pomordor");
		ui->TimerStateLabel->setStyleSheet(SSTimerState_Porm);
		ui->TimerButton->setStyleSheet(SSTimerButton_Porm);
		ui->Progress_Back->setStyleSheet(SSProgress_Porm_bg);
		break;
	}
}

void TimerPage::onProp()
{
	if (m_ScheduleDialog->isHidden())
	{
		if (m_CurState != TimerState::None)
			return;
		m_ScheduleDialog->move(geometry().right() + 1, geometry().top() + 30);
		m_ScheduleDialog->show();
	}
	else
	{
		m_ScheduleDialog->hide();
	}
	updateTimerData();
}

void TimerPage::onStart()
{
	m_CurState = TimerState::Porm;
	onProp();

	setTimerStateUi(TimerState::Porm);
	ui->PlayButton->setIcon(QIcon(":/20x20/icons/20x20/cil-media-stop.png"));
	m_EngineClock.Start(ui->TimerButton->text().toStdString());
	m_Loop->start(16);

	disconnect(m_PlayButtonConn);
	m_PlayButtonConn = connect(ui->PlayButton, SIGNAL(clicked()), SLOT(onStop()));
}

void TimerPage::onStop()
{
	m_CurState = TimerState::None;
	updateTimerData();
	fillProgress(0.999f, TimerState::None);

	setTimerStateUi(TimerState::None);
	ui->PlayButton->setIcon(QIcon(":/20x20/icons/20x20/cil-media-play.png"));
	m_EngineClock.Stop();
	m_Loop->stop();

	disconnect(m_PlayButtonConn);
	m_PlayButtonConn = connect(ui->PlayButton, SIGNAL(clicked()), SLOT(onStart()));
}

void TimerPage::onRunning()
{
	m_EngineClock.Update();

	float percentage = m_EngineClock.GetRemainRatio();
	ui->TimerButton->setText(QString::fromStdString(m_EngineClock.GetStrRemainTime()));
	fillProgress(percentage, m_ScheduleQueue.begin()->first);

	if (!m_EngineClock.isRunning())
	{
		//Popup Toast-message
		if (m_ScheduleQueue.begin()->first == TimerState::Porm)
		{
			m_TrayIcon->showMessage("Just one Pormodor done!", "Take a break", QIcon(":/icon/Tomato"), 3000);
		}
		else
		{
			if (m_ScheduleQueue.size() == 1)
			{
				m_TrayIcon->showMessage("The break Time done!", "Your Pomordor schedule is done!", QIcon(":/icon/Tomato"), 3000);
			}
			else
			{
				m_TrayIcon->showMessage("The break Time done!", "Next Pormordor time start now!", QIcon(":/icon/Tomato"), 3000);
			}
		}
		m_ScheduleQueue.pop_front();
		updateSetCount();

		//Check schedule and Set progress
		if (m_ScheduleQueue.empty())
		{			
			onStop();
		}
		else
		{
			m_EngineClock.Start(0, m_ScheduleQueue.begin()->second, 0);
			setTimerStateUi(m_ScheduleQueue.begin()->first);
		}
	}
}

TimerPage::~TimerPage()
{
	delete m_TrayIcon;
	delete m_ScheduleDialog;
	delete m_Loop;
	delete ui;
}