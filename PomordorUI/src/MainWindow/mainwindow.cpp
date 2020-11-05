#include "pompch.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TimerPage/TimerPage.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->titleBar->SetParentWidget(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setAutoFillBackground(true);	

	TimerPage* timerPage = new TimerPage;
	ui->stackedWidget->insertWidget(0, timerPage);
	ui->stackedWidget->setCurrentIndex(0);
	timerPage->show();
}


MainWindow::~MainWindow()
{
	delete ui;
}
