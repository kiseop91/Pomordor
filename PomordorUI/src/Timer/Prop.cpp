#include "pompch.h"

#include "Prop.h"
#include "ui_Prop.h"
#include "Timer.h"

Prop::Prop(Timer* timer, QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Prop)
	, myTimer(timer)
{
	setWindowFlags(Qt::FramelessWindowHint);
	ui->setupUi(this);

	ui->spinBox->setMaximum(60);
	ui->spinBox_2->setMaximum(60);
	ui->spinBox_3->setMaximum(5);

	connect(ui->Btn_close, SIGNAL(clicked()), SLOT(OnClose()));
	ui->spinBox->setValue(25);
	ui->spinBox_2->setValue(5);
	ui->spinBox_3->setValue(1);

	QFont font("Segoe UI");
	ui->label->setFont(font);
	ui->label_2->setFont(font);
	ui->label_3->setFont(font);
	ui->label_4->setFont(font);

}

void Prop::OnClose()
{
	myTimer->UpdateData();
	this->hide();
}

Prop::~Prop()
{
	delete ui;
}

Prop::Data Prop::GetData()
{
	return {ui->spinBox->value(), ui->spinBox_2->value(), ui->spinBox_3->value()};
}
