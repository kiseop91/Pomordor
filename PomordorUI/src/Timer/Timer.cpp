#include "pompch.h"

#include "Timer.h"
#include "ui_Timer.h"

Timer::Timer(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Timer)
	, timer(new QTimer(this))
{
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	
	//clock text
	QFont font("Segoe UI");
	ui->pushButton_2->setFont(font);

	//CircularProgressBar
	CircularProgressBarSS_ING = CircularProgressBarSS;
	CircularProgressBarSS_ING.replace(QString("{GradPoint_1}"), QString::number(0.999f));
	CircularProgressBarSS_ING.replace(QString("{GradPoint_2}"), QString::number(0.9991f));
	ui->CircularProgress->setStyleSheet(CircularProgressBarSS_ING);

	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(OnClick()));
	connect(timer, SIGNAL(timeout()), this, SLOT(OnRunning()));
	connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(OnProp()));

	//Prop
	prop = new Prop(this);
	connect(ui->Btn_close, &QPushButton::clicked, [this]() { hide(); prop->hide(); });

	//Tray Icon
	TrayIcon = new QSystemTrayIcon(QIcon(":/icon/icons/icon/tomato_tray.png"), this);
	TrayIcon->show();

	tray_close = new QAction("close");
	tray_show = new QAction("show");
	trayMenu = new QMenu(this);
	trayMenu->addActions({ tray_close, tray_show});

	TrayIcon->setContextMenu(trayMenu);
	connect(tray_close, &QAction::triggered, [this]() { this->close(); });
	connect(tray_show, &QAction::triggered, [this]() { if(this->isHidden()) this->show(); });
	connect(TrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(TrayIconSlot(QSystemTrayIcon::ActivationReason)));
}

void Timer::TrayIconSlot(QSystemTrayIcon::ActivationReason Rw)
{
	if (Rw != QSystemTrayIcon::DoubleClick)
		return;
	if (this->isHidden()) 
		this->show();
}

void Timer::UpdateData()
{
	propData = prop->GetData();
	QString str;
	int minute = std::get<0>(propData);
	if (minute < 10)
	{
		str += '0';
	}
	str += QString::number(minute) + " : 00";
	ui->pushButton_2->setText(str);
}

void Timer::OnProp()
{
	if (prop->isHidden())
	{		
		if (isRunning)
			return;
		UpdateData();
		prop->move(geometry().right() + 1, geometry().top() + 30);
		prop->show();
	}
	else
	{
		UpdateData();
		prop->hide();
	}
}

void Timer::OnClick()
{
	if (isRunning)
	{
		isRunning = false;
		ui->pushButton->setIcon(QIcon(":/20x20/icons/20x20/cil-media-play.png"));
	}
	else
	{
		isRunning = true;
		OnProp();
		ui->pushButton->setIcon(QIcon(":/20x20/icons/20x20/cil-media-stop.png"));
		EngineClock.Start(ui->pushButton_2->text().toStdString());
	}
	timer->start(16);
}

void Timer::OnRunning()
{
	EngineClock.Update();

	auto GradPoint1 = EngineClock.GetRemainRatio();
	auto GradPoint2 = GradPoint1 + 0.0001f;
	ui->pushButton_2->setText(QString::fromStdString(EngineClock.GetStrRemainTime()));

	if (!EngineClock.isRunning() || !isRunning)
	{
		if (isRunning)
		{
			if (isHidden()) show();
			TrayIcon->showMessage("Just one Pormodor done!", "Take a break", QIcon(":/icon/icons/icon/tomato_tray.png"));
		}
		isRunning = false;
		GradPoint1 = 0.999f;
		GradPoint2 = 0.9991f;
		timer->stop();
		EngineClock.Stop();
		ui->pushButton_2->setText(defaultTime);
		ui->pushButton->setIcon(QIcon(":/20x20/icons/20x20/cil-media-play.png"));
	}

	CircularProgressBarSS_ING = CircularProgressBarSS;
	CircularProgressBarSS_ING.replace(QString("{GradPoint_1}"), QString::number(GradPoint1));
	CircularProgressBarSS_ING.replace(QString("{GradPoint_2}"), QString::number(GradPoint2));
	ui->CircularProgress->setStyleSheet(CircularProgressBarSS_ING);
}

Timer::~Timer()
{
	delete timer;
	delete ui;
	delete prop;
}
