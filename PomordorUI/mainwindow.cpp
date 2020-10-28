#include "pompch.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPropertyAnimation>
#include <QMouseEvent>

#include "Timer.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QObject::connect(ui->Btn_Toggle, SIGNAL(clicked()), this, SLOT(onClickToggleButton()));
	QObject::connect(ui->Btn_close, SIGNAL(clicked()), this, SLOT(onClickCloseButton()));
	QObject::connect(ui->Btn_maximaize, SIGNAL(clicked()), this, SLOT(onClickMaximizeButton()));
	QObject::connect(ui->Btn_minimaize, SIGNAL(clicked()), this, SLOT(onClickMinimizeButton()));
	QObject::connect(ui->Btn_Menu_3, SIGNAL(clicked()), this, SLOT(tt()));

	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);

	justOneCount = 0; 
	
	mouseX = this->geometry().x();
	mouseY = this->geometry().y();
	absY = this->geometry().y();
	absX = this->geometry().x();
}

void MainWindow::tt()
{
	Timer* timer = new Timer;
	timer->show();
	/*QWidget* widget=  new QWidget;

	widget->setGeometry(QRect(300, 300, 500, 500));

	std::cout << "Timer";

	QProgressBar* progress = new QProgressBar(widget);
	progress->setGeometry(QRect(100, 150, 200, 50));

	QTimer* timer = new QTimer;
	connect(timer, &QTimer::timeout, [progress]() {
		static int v = 0;

		if (v < 100)
		{
			v++;
		}
		else
		{
			v = 0;
		}
		progress->setValue(v);
	});
	timer->start(100);

	widget->show();*/

}

void MainWindow::pormTimer()
{
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
	if (widthExtended != maxExtend)
	{
		start = 70 + maxExtend; 
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
	animation2->setEndValue(QRect(end, 0, 1000, 1000));
	animation2->setEasingCurve(QEasingCurve::InOutSine);
	animation2->start();
}

void MainWindow::onClickCloseButton()
{
	this->close();
}

void MainWindow::onClickMaximizeButton()
{
	if (this->isMaximized())
		this->showNormal();
	else
		this->showMaximized();
}

void MainWindow::onClickMinimizeButton()
{
	this->showMinimized();
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

void MainWindow::paintEvent(QPaintEvent * e)
{
	QPainter painter(this);
	QRect rect(10, 10, 200, 200);

	QLinearGradient grad(25, 100, 150, 175);
	grad.setColorAt(0.0, Qt::black);

	painter.fillRect(rect, Qt::GlobalColor::black);
	//painter.drawLine(QLine(10, 10, 50, 50));
}

