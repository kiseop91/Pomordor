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
	void OnStart();
	void OnRunning();
	void OnProp();

private:
	void UpdateTimerData();

private:
	Ui::Timer* ui;

private:
	//component
	QTimer* m_Timer;
	class Prop* m_PropDialog;
	class TrayIcon* m_TrayIcon;

private:
	//Timer
	Pome::Clock EngineClock;
	bool isTimerRunning = false;

	QString SSProgress_Porm =
		"QWidget{\n"
		"   border-radius: 135px;\n"
		"   background-color: qconicalgradient(cx:0.5, cy:0.5, angle:90, stop:{GradPoint_1} rgba(255, 255, 255, 0), stop:{GradPoint_2} rgba(255, 135, 135, 255));\n"
		"}";
	QString SSProgress_Break = 
		"QWidget{\n"
		"   border-radius: 135px;\n"
		"   background-color: qconicalgradient(cx:0.5, cy:0.5, angle:90, stop:{GradPoint_1} rgba(255, 255, 255, 0), stop:{GradPoint_2} rgba(255, 135, 135, 255));\n"
		"}";
	QString SSProgress;

	friend class Prop;
};
