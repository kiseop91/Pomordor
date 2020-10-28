#include "pompch.h"

#include "Timer.h"
#include "ui_Timer.h"

Timer::Timer(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Timer)
{
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	
	styleSheet = "QWidget{\n"
		"   border-radius: 100px;\n"
		"   background-color: qconicalgradient(cx:0.5, cy:0.5, angle:90, stop:{STOP_1} rgba(255, 255, 255, 0), stop:{STOP_2} rgba(85, 170, 255, 255));\n"
		"}";
	QString temp = styleSheet;
	temp.replace(QString("{STOP_1}"), QString::number(progress));
	temp.replace(QString("{STOP_2}"), QString::number(stop));

	ui->CircularProgress->setStyleSheet(temp);

	QTimer* timer = new QTimer(this);

	connect(ui->pushButton, &QPushButton::clicked, [this, timer]() {
		if (isRunning)
		{
			isRunning = false;
		}
		else
		{
			progress = 1.0f;
			isRunning = true;
		}
		timer->start(8);
	});

	connect(timer, &QTimer::timeout, [this, timer]() {
		progress -= 0.001f;
		stop = progress + 0.0001f;

		if (progress < 0.0f)
		{
			this->isRunning = false;
		}

		if (!isRunning)
		{
			progress = 0.0f;
			stop = 0.0f;
			timer->stop();
		}

		QString temp = styleSheet;
		temp.replace(QString("{STOP_1}"), QString::number(progress));
		temp.replace(QString("{STOP_2}"), QString::number(stop));

		ui->CircularProgress->setStyleSheet(temp);
	});

	connect(ui->Btn_close, &QPushButton::clicked, [this]() {this->close(); });
}


Timer::~Timer()
{
}
