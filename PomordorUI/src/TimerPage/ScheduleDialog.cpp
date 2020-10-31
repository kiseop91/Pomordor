#include "pompch.h"

#include "ScheduleDialog.h"
#include "ui_ScheduleDialog.h"
#include "TimerPage.h"
#include "Timer.h"
#include "ui_TimerPage.h"

ScheduleDialog::ScheduleDialog(TimerPage* page, QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::ScheduleDialog)
	, m_MyPage(page)
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

	ui->spinBox->setValue(25);
	ui->spinBox_2->setValue(5);
	ui->spinBox_3->setValue(3);

	QFont font("Segoe UI");
	ui->label->setFont(font);
	ui->label_2->setFont(font);
	ui->label_3->setFont(font);
	ui->label_4->setFont(font);

	connect(ui->Btn_close, SIGNAL(clicked()), SLOT(OnClose()));
	connect(ui->spinBox, SIGNAL(valueChanged(QString)), SLOT(onScheduleValueChanged()));
	connect(ui->spinBox_2, SIGNAL(valueChanged(QString)), SLOT(onScheduleValueChanged()));
	connect(ui->spinBox_3, SIGNAL(valueChanged(QString)), SLOT(onScheduleValueChanged()));
}

void ScheduleDialog::onScheduleValueChanged()
{
	applyScheduleValue();
}

void ScheduleDialog::applyScheduleValue()
{
	auto[pormTime, breakTime, NumSets] = GetData();
	m_MyPage->m_Timer->m_ScheduleQueue.clear();
	for (auto i = 0; i < NumSets; ++i)
	{
		m_MyPage->m_Timer->m_ScheduleQueue.emplace_back(Timer::TimerState::Porm, pormTime);
		m_MyPage->m_Timer->m_ScheduleQueue.emplace_back(Timer::TimerState::Break, breakTime);
	}
	m_MyPage->m_Timer->m_SetTotal = NumSets;
	m_MyPage->m_Timer->updateSetCount();

	QString timeText;
	if (pormTime < 10)
	{
		timeText += '0';
	}
	timeText += QString::number(pormTime) + ":00";
	m_MyPage->ui->TimerButton->setText(timeText);
}


void ScheduleDialog::OnClose()
{
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