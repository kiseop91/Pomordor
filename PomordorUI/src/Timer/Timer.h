#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class Timer; }
QT_END_NAMESPACE

class Timer : public QWidget
{
	Q_OBJECT

public:
	Timer(QWidget *parent = nullptr);
	~Timer();

private slots:
	void OnClick();
	void OnRunning();
	
private:
	Ui::Timer* ui;
	QTimer* timer;

	QString CircularProgressBarSS =
		"QWidget{\n"
		"   border-radius: 135px;\n"
		"   background-color: qconicalgradient(cx:0.5, cy:0.5, angle:90, stop:{STOP_1} rgba(255, 255, 255, 0), stop:{STOP_2} rgba(227, 183, 177, 255));\n"
		"}";
	QString CircularProgressBarSS_ING;

private:
	bool isRunning = false;
	float progress = 0.999f;
	float stop = 0.9991f;
};
