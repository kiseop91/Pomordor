#include "mainwindow.h"
#include "ui_mainwindow.h"
static int value = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onClickPushButton()));
}

void MainWindow::onClickPushButton()
{
	ui->progressBar->setValue(value++);
}

MainWindow::~MainWindow()
{
    delete ui;
}

