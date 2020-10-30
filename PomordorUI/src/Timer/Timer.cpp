#include "pompch.h"

#include "Timer.h"
#include "ui_Timer.h"

#include "Prop.h"
#include "TrayIcon.h"

Timer::Timer(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Timer)
	, m_Timer(new QTimer)
	, m_PropDialog(new Prop(this))
	, m_TrayIcon(new TrayIcon(QIcon(":/icon/Tomato"), this))
	, m_CurState(RunningState::None)
{
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setAutoFillBackground(true);

	QFont d2code("D2Coding");
	QFont segoe("Segoe UI");
	ui->TimerButton->setFont(d2code);
	ui->RunningStateLabel->setFont(segoe);
	ui->SetCountLabel->setFont(segoe);
	SetRunningStateUi(RunningState::None);

	UpdateTimerData();
	FillProgress(0.999f, RunningState::None);

	m_PlayButtonConn = connect(ui->PlayButton, SIGNAL(clicked()), SLOT(OnStart()));
	connect(ui->TimerButton, SIGNAL(clicked()), this, SLOT(OnProp()));
	connect(ui->Title_Close, &QPushButton::clicked, [this]() { hide(); m_PropDialog->hide(); });

	connect(m_Timer, SIGNAL(timeout()), this, SLOT(OnRunning()));
}

void Timer::UpdateTimerData()
{
	auto[pormTime, breakTime, NumSets] = m_PropDialog->GetData();
	m_ScheduleQue.clear();
	for (auto i = 0; i < NumSets; ++i)
	{
		m_ScheduleQue.emplace_back(RunningState::Porm, pormTime);
		m_ScheduleQue.emplace_back(RunningState::Break, breakTime);
	}
	m_SetTotal = NumSets;

	QString timeText;
	if (pormTime < 10)
	{
		timeText += '0';
	}
	timeText += QString::number(pormTime) + ":00";
	ui->TimerButton->setText(timeText);
	UpdateSetCount();
}

void Timer::UpdateSetCount()
{
	uint32_t setCount = m_SetTotal - (m_ScheduleQue.size() + 1) / 2 + 1;
	if (m_CurState == RunningState::None)
		setCount = 0;
	QString setStr = "Set Count : " + QString::number(setCount) + " / " + QString::number(m_SetTotal);
	ui->SetCountLabel->setText(setStr);
}

void Timer::FillProgress(float percentage, RunningState state)
{
	switch (state)
	{
	case Timer::RunningState::Porm: SSProgress = SSProgress_Porm; break;
	case Timer::RunningState::Break: SSProgress = SSProgress_Break; break;
	case Timer::RunningState::None: SSProgress = SSProgress_Porm; break;
	}

	SSProgress.replace(QString("{GradPoint_1}"), QString::number(percentage));
	SSProgress.replace(QString("{GradPoint_2}"), QString::number(percentage + 0.0001f));
	ui->Progress_Front->setStyleSheet(SSProgress);
}

void Timer::SetRunningStateUi(RunningState state)
{
	switch (state)
	{
	case Timer::RunningState::Porm:
		ui->RunningStateLabel->show();
		ui->RunningStateLabel->setText("Pomordor");
		ui->RunningStateLabel->setStyleSheet(SSRunningState_Porm);
		ui->TimerButton->setStyleSheet(SSTimerButton_Porm);
		ui->Progress_Back->setStyleSheet(SSProgress_Porm_bg);
		break;
	case Timer::RunningState::Break:
		ui->RunningStateLabel->show();
		ui->RunningStateLabel->setText("Break");
		ui->RunningStateLabel->setStyleSheet(SSRunningState_Break);
		ui->TimerButton->setStyleSheet(SSTimerButton_Break);
		ui->Progress_Back->setStyleSheet(SSProgress_Break_bg);
		break;
	case Timer::RunningState::None:
		ui->RunningStateLabel->hide();
		ui->TimerButton->setStyleSheet(SSTimerButton_Porm);
		ui->Progress_Back->setStyleSheet(SSProgress_Porm_bg);
		break;
	}
}

void Timer::OnProp()
{
	if (m_PropDialog->isHidden())
	{
		if (m_CurState != RunningState::None)
			return;
		m_PropDialog->move(geometry().right() + 1, geometry().top() + 30);
		m_PropDialog->show();
	}
	else
	{
		m_PropDialog->hide();
	}
	UpdateTimerData();
}

void Timer::OnStart()
{
	m_CurState = RunningState::Porm;
	OnProp();

	SetRunningStateUi(RunningState::Porm);
	ui->PlayButton->setIcon(QIcon(":/20x20/icons/20x20/cil-media-stop.png"));
	m_EngineClock.Start(ui->TimerButton->text().toStdString());
	m_Timer->start(16);

	disconnect(m_PlayButtonConn);
	m_PlayButtonConn = connect(ui->PlayButton, SIGNAL(clicked()), SLOT(OnStop()));
}

void Timer::OnStop()
{
	m_CurState = RunningState::None;
	UpdateTimerData();
	FillProgress(0.999f, RunningState::None);

	SetRunningStateUi(RunningState::None);
	ui->PlayButton->setIcon(QIcon(":/20x20/icons/20x20/cil-media-play.png"));
	m_EngineClock.Stop();
	m_Timer->stop();

	disconnect(m_PlayButtonConn);
	m_PlayButtonConn = connect(ui->PlayButton, SIGNAL(clicked()), SLOT(OnStart()));
}

void Timer::OnRunning()
{
	m_EngineClock.Update();

	float percentage = m_EngineClock.GetRemainRatio();
	ui->TimerButton->setText(QString::fromStdString(m_EngineClock.GetStrRemainTime()));
	FillProgress(percentage, m_ScheduleQue.begin()->first);

	if (!m_EngineClock.isRunning())
	{
		//Popup Toast-message
		if (m_ScheduleQue.begin()->first == RunningState::Porm)
		{
			m_TrayIcon->showMessage("Just one Pormodor done!", "Take a break", QIcon(":/icon/Tomato"), 3000);
		}
		else
		{
			if (m_ScheduleQue.size() == 1)
			{
				m_TrayIcon->showMessage("The break Time done!", "Your Pomordor schedule is done!", QIcon(":/icon/Tomato"), 3000);
			}
			else
			{
				m_TrayIcon->showMessage("The break Time done!", "Next Pormordor time start now!", QIcon(":/icon/Tomato"), 3000);
			}
		}
		m_ScheduleQue.pop_front();
		UpdateSetCount();

		//Check schedule and Set progress
		if (m_ScheduleQue.empty())
		{			
			OnStop();
		}
		else
		{
			m_EngineClock.Start(0, m_ScheduleQue.begin()->second, 0);
			SetRunningStateUi(m_ScheduleQue.begin()->first);
		}
	}
}

Timer::~Timer()
{
	delete m_TrayIcon;
	delete m_PropDialog;
	delete m_Timer;
	delete ui;
}