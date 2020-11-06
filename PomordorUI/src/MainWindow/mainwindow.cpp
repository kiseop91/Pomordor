#include "pompch.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "TimerPage/TimerPage.h"
#include "TodoPage/TodoPage.h"

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
	//timerPage->show();

	TodoPage* todoPage = new TodoPage;
	ui->stackedWidget->insertWidget(1, todoPage);
	ui->stackedWidget->setCurrentIndex(1);
	todoPage->show();
	timerPage->show();

	//Todo : index Enum�̳� ������ �ְ� �����ϵ��� ������ ��. 2020/11/06 Kiseop Kim.
	connect(ui->timerButton, &QPushButton::clicked, [this]() { ui->stackedWidget->setCurrentIndex(0); });
	connect(ui->todoButton, &QPushButton::clicked, [this]() { ui->stackedWidget->setCurrentIndex(1); });
	connect(ui->statisticsButton, &QPushButton::clicked, [this]() { ui->stackedWidget->setCurrentIndex(2); });
	connect(ui->settingButton, &QPushButton::clicked, [this]() { ui->stackedWidget->setCurrentIndex(3); });
}


MainWindow::~MainWindow()
{
	delete ui;
}
