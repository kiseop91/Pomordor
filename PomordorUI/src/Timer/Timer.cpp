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

	//CircularProgressBar
	CircularProgressBarSS_ING = CircularProgressBarSS;
	CircularProgressBarSS_ING.replace(QString("{STOP_1}"), QString::number(progress));
	CircularProgressBarSS_ING.replace(QString("{STOP_2}"), QString::number(stop));
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
		progress = 1.0f;
	}
	timer->start(8);
}

void Timer::OnRunning()
{
	progress -= 0.001f;
	stop = progress + 0.0001f;

	if (progress < 0.0f)
	{
		this->isRunning = false;
	}

	if (!isRunning)
	{
		progress = 0.999f;
		stop = 0.9991f;
		timer->stop();
	}

	CircularProgressBarSS_ING = CircularProgressBarSS;
	CircularProgressBarSS_ING.replace(QString("{STOP_1}"), QString::number(progress));
	CircularProgressBarSS_ING.replace(QString("{STOP_2}"), QString::number(stop));
	ui->CircularProgress->setStyleSheet(CircularProgressBarSS_ING);
}

void mouseMove()
{
	//if (this->isMaximized() == true)
	//	return;
	//
	//if (mouse->button() == Qt::RightButton)
	//	return;
	//
	//mouseX = QCursor::pos().x();
	//mouseY = QCursor::pos().y();
	//
	//if (justOneCount == 0)
	//{
	//	absX = mouse->pos().x() + 7;
	//	absY = mouse->pos().y() + 7;
	//	justOneCount++;
	//}
	//
	//this->move(mouseX - absX, mouseY - absY);
}

Timer::~Timer()
{
	delete timer;
	delete ui;
}
