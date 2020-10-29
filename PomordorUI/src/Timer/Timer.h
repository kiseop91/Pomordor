#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class Timer; }
QT_END_NAMESPACE

#include "Prop.h"

class Timer : public QWidget
{
	Q_OBJECT

public:
	Timer(QWidget *parent = nullptr);
	~Timer();

private slots:
	void OnClick();
	void OnRunning();
	void OnProp();

private:
	void UpdateData();

private:
	Ui::Timer* ui;
	QTimer* timer;
	Prop* prop;
	Prop::Data propData;			//pormodor, break, sets
	Pome::Clock EngineClock;

	QString CircularProgressBarSS =
		"QWidget{\n"
		"   border-radius: 135px;\n"
		"   background-color: qconicalgradient(cx:0.5, cy:0.5, angle:90, stop:{GradPoint_1} rgba(255, 255, 255, 0), stop:{GradPoint_2} rgba(255, 135, 135, 255));\n"
		"}";
	QString CircularProgressBarSS_ING;
	QString defaultTime = "00 : 00";

private:
	bool isRunning = false;

	friend class Prop;
};
