#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPropertyAnimation>

static int value = 0;
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	
	//setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint |  Qt::FramelessWindowHint);
	//QObject::connect(, SIGNAL(clicked()), this, SLOT(onClickPushButton()));
	QObject::connect(ui->Btn_Toggle, SIGNAL(clicked()), this, SLOT(onClickToggleButton()));
}

void MainWindow::onClickPushButton()
{
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::onClickToggleButton()
{
	//DEFAULT SETTING VALUES
	size_t width = ui->frame_left_menu->width();
	size_t height = ui->frame_left_menu->height();
	size_t maxExtend = 180;
	size_t standard = 0;
	size_t widthExtended = 0;

	if (width == 0)
		widthExtended = maxExtend;
	else
		widthExtended = standard;

	//ANIMATION
	QPropertyAnimation* animation = new QPropertyAnimation(ui->frame_left_menu, "size");
	animation->setDuration(400);
	animation->setStartValue(QSize(width, height));
	animation->setEndValue(QSize(widthExtended, height));
	animation->setEasingCurve(QEasingCurve::InOutSine);
	animation->start();

	int start, end;
	if (widthExtended  != maxExtend)
	{
		start = 70 + maxExtend; // 70은 오프셋 ( 맨왼쪽 아이콘 넓이 )
		end = 70;
	}
	else
	{
		start = 70;
		end = 70 + maxExtend;
	}

	
	QPropertyAnimation* animation2 = new QPropertyAnimation(ui->frame_pages, "geometry");
	animation2->setDuration(400);
	animation2->setStartValue(QRect(start, 0, 1000, 1000));
	animation2->setEndValue(QRect( end, 0, 1000, 1000));
	animation2->setEasingCurve(QEasingCurve::InOutSine);
	animation2->start();
}

