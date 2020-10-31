#include "pompch.h"

#include "TimerPage.h"
#include "ui_TimerPage.h"

//modules
#include "Timer.h"
#include "ScheduleDialog.h"
#include "TrayIcon.h"

TimerPage::TimerPage(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::TimerPage)
	, m_Loop(new QTimer)
	, m_ScheduleDialog(new ScheduleDialog(this))
	, m_TrayIcon(new TrayIcon(QIcon(":/icon/Tomato"), this))
	, m_Timer(new Timer(this))
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
	
	m_Timer->fillProgress(0.999f);
	m_Timer->setTimerStateUi();
	m_ScheduleDialog->applyScheduleValue();

	connect(ui->Title_Close, &QPushButton::clicked, [this]() { hide(); m_ScheduleDialog->hide(); });

	m_PlayButtonConn = connect(ui->PlayButton, SIGNAL(clicked()), SLOT(onTimerStart()));
	connect(m_Loop, SIGNAL(timeout()), this, SLOT(onTimerLoop()));
	connect(ui->TimerButton, SIGNAL(clicked()), this, SLOT(onToggleSchduleDialog()));
}

TimerPage::~TimerPage()
{
	delete m_TrayIcon;
	delete m_ScheduleDialog;
	delete m_Loop;
	delete m_Timer;
	delete ui;
}

void TimerPage::onToggleSchduleDialog()
{
	if (m_ScheduleDialog->isHidden())
	{
		if (m_Timer->m_CurState != Timer::TimerState::None)
			return;
		m_ScheduleDialog->move(geometry().right() + 1, geometry().top() + 30);
		m_ScheduleDialog->show();
	}
	else
	{
		m_ScheduleDialog->hide();
	}
}

void TimerPage::onTimerStart()
{
	m_Timer->Start();
	m_Loop->start(16);
	onToggleSchduleDialog();	

	disconnect(m_PlayButtonConn);
	m_PlayButtonConn = connect(ui->PlayButton, SIGNAL(clicked()), SLOT(onTimerStop()));

	ui->PlayButton->setIcon(QIcon(":/20x20/icons/20x20/cil-media-stop.png"));
}

void TimerPage::onTimerStop()
{
	timerFinish();
}

void TimerPage::timerFinish()
{
	m_Timer->Stop();
	m_Loop->stop();
	m_ScheduleDialog->applyScheduleValue();

	disconnect(m_PlayButtonConn);
	m_PlayButtonConn = connect(ui->PlayButton, SIGNAL(clicked()), SLOT(onTimerStart()));

	ui->PlayButton->setIcon(QIcon(":/20x20/icons/20x20/cil-media-play.png"));
}

void TimerPage::onTimerLoop()
{
	m_Timer->Update();
}

void TimerPage::ToastMessage(const QString & title, const QString & msg, int duration_ms)
{
	m_TrayIcon->showMessage(title, msg, QIcon(":/icon/Tomato"), duration_ms);
}
