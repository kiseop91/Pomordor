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
{
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setAutoFillBackground(true);

	//TODO : Change Font
	QFont font("D2Coding");
	ui->TimerButton->setFont(font);

	connect(ui->PlayButton, SIGNAL(clicked()), this, SLOT(OnStart()));
	connect(ui->TimerButton, SIGNAL(clicked()), this, SLOT(OnProp()));
	connect(ui->Title_Close, &QPushButton::clicked, [this]() { hide(); m_PropDialog->hide(); });

	connect(m_Timer, SIGNAL(timeout()), this, SLOT(OnRunning()));
}

void Timer::UpdateTimerData()
{
	auto[pormTime, breakTime, NumSets] = m_PropDialog->GetData();
	QString str;
	if (pormTime < 10)
	{
		str += '0';
	}
	str += QString::number(pormTime) + ":00";
	ui->TimerButton->setText(str);
}

void Timer::OnProp()
{
	if (m_PropDialog->isHidden())
	{		
		if (isTimerRunning)
			return;
		UpdateTimerData();
		m_PropDialog->move(geometry().right() + 1, geometry().top() + 30);
		m_PropDialog->show();
	}
	else
	{
		UpdateTimerData();
		m_PropDialog->hide();
	}
}

void Timer::OnStart()
{
	if (isTimerRunning)
	{
		isTimerRunning = false;
		ui->PlayButton->setIcon(QIcon(":/20x20/icons/20x20/cil-media-play.png"));
	}
	else
	{
		isTimerRunning = true;
		OnProp();
		ui->PlayButton->setIcon(QIcon(":/20x20/icons/20x20/cil-media-stop.png"));
		EngineClock.Start(ui->TimerButton->text().toStdString());
	}
	m_Timer->start(16);
}

void Timer::OnRunning()
{
	EngineClock.Update();

	auto GradPoint1 = EngineClock.GetRemainRatio();
	auto GradPoint2 = GradPoint1 + 0.0001f;
	ui->TimerButton->setText(QString::fromStdString(EngineClock.GetStrRemainTime()));

	if (!EngineClock.isRunning() || !isTimerRunning)
	{
		if (isTimerRunning)
		{
			if (isHidden()) show();
			m_TrayIcon->showMessage("Just one Pormodor done!", "Take a break", QIcon(":/icon/Tomato"));
		}
		isTimerRunning = false;
		GradPoint1 = 0.999f;
		GradPoint2 = 0.9991f;
		m_Timer->stop();
		EngineClock.Stop();
		ui->TimerButton->setText("00:00");
		ui->PlayButton->setIcon(QIcon(":/20x20/icons/20x20/cil-media-play.png"));
	}

	SSProgress = SSProgress_Porm;
	SSProgress.replace(QString("{GradPoint_1}"), QString::number(GradPoint1));
	SSProgress.replace(QString("{GradPoint_2}"), QString::number(GradPoint2));
	ui->Progress_Front->setStyleSheet(SSProgress);
}

Timer::~Timer()
{
	delete m_TrayIcon;
	delete m_PropDialog;
	delete m_Timer;
	delete ui;
}
