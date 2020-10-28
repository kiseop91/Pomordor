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
	
	//TitleBar
	connect(ui->Btn_close, &QPushButton::clicked, [this]() {this->close(); });

	//clock text
	QFont font("Segoe UI");
	ui->label->setText(defaultTime);
	ui->label->setFont(font);

	//CircularProgressBar
	CircularProgressBarSS_ING = CircularProgressBarSS;
	CircularProgressBarSS_ING.replace(QString("{GradPoint_1}"), QString::number(0.999f));
	CircularProgressBarSS_ING.replace(QString("{GradPoint_2}"), QString::number(0.9991f));
	ui->CircularProgress->setStyleSheet(CircularProgressBarSS_ING);

	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(OnClick()));
	connect(timer, SIGNAL(timeout()), this, SLOT(OnRunning()));
}

void Timer::OnClick()
{
	if (isRunning)
	{
		isRunning = false;
	}
	else
	{
		isRunning = true;
		clock.Start(ui->label->text().toStdString());
	}
	timer->start(16);
}

void Timer::OnRunning()
{
	clock.Update();

	auto GradPoint1 = clock.GetRemainRatio();
	auto GradPoint2 = GradPoint1 + 0.0001f;
	ui->label->setText(QString::fromStdString(clock.GetStrRemainTime()));

	if (!clock.isRunning() || !isRunning)
	{
		isRunning = false;
		GradPoint1 = 0.999f;
		GradPoint2 = 0.9991f;
		timer->stop();
		clock.Stop();
		ui->label->setText(defaultTime);
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
}
