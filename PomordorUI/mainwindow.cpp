#include "pompch.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPropertyAnimation>
#include <QMouseEvent>


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	
	QObject::connect(this , SIGNAL(clicked()), this, SLOT(onClickPushButton()));
	QObject::connect(ui->Btn_Toggle, SIGNAL(clicked()), this, SLOT(onClickToggleButton()));


	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);

	justOneCount = 0; //���� �ʱ�ȭ

	mouseX = this->geometry().x(); //���� ���콺 ��ǥ�� �ʱ�ȭ
	mouseY = this->geometry().y();
	absY = this->geometry().y();
	absX = this->geometry().x();
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
		start = 70 + maxExtend; // 70�� ������ ( �ǿ��� ������ ���� )
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

void MainWindow::mouseMoveEvent(QMouseEvent *mouse)
{
	if (this->isMaximized() == true) 
		return;

	if (mouse->button() == Qt::RightButton) 
		return;

	mouseX = QCursor::pos().x(); 
	mouseY = QCursor::pos().y();

	if (justOneCount == 0)
	{
		absX = mouse->pos().x() + 7; 
		absY = mouse->pos().y() + 7;
		justOneCount++; 
	}

	this->move(mouseX - absX, mouseY - absY); 
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
	justOneCount = 0; 
}
