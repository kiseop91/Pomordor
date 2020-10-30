#include "pompch.h"

#include "ScheduleDialog.h"
#include "ui_ScheduleDialog.h"
#include "TimerPage.h"

ScheduleDialog::ScheduleDialog(TimerPage* timer, QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::ScheduleDialog)
	, m_MyTimer(timer)
{
	setWindowFlags(Qt::FramelessWindowHint);
	ui->setupUi(this);

	ui->spinBox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
	ui->spinBox_2->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
	ui->spinBox_3->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);

	ui->spinBox->setMaximum(60);
	ui->spinBox_2->setMaximum(60);
	ui->spinBox_3->setMaximum(100);

	ui->spinBox->setMinimum(1);
	ui->spinBox_2->setMinimum(1);
	ui->spinBox_3->setMinimum(1);

	connect(ui->Btn_close, SIGNAL(clicked()), SLOT(OnClose()));
	ui->spinBox->setValue(25);
	ui->spinBox_2->setValue(5);
	ui->spinBox_3->setValue(3);

	QFont font("Segoe UI");
	ui->label->setFont(font);
	ui->label_2->setFont(font);
	ui->label_3->setFont(font);
	ui->label_4->setFont(font);

}

void ScheduleDialog::OnClose()
{
	m_MyTimer->updateTimerData();
	this->hide();
}

ScheduleDialog::~ScheduleDialog()
{
	delete ui;
}

ScheduleDialog::Data ScheduleDialog::GetData()
{
	return { ui->spinBox->value(), ui->spinBox_2->value(), ui->spinBox_3->value() };
}