#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class TimerPage; }
QT_END_NAMESPACE

class TimerPage : public QWidget
{
	Q_OBJECT

public:
	enum class TimerState
	{
		Porm,
		Break,
		None,
	};

public:
	TimerPage(QWidget *parent = nullptr);
	~TimerPage();

private slots:
	void onStart();
	void onStop();
	void onRunning();
	void onProp();

private:
	void updateTimerData();
	void updateSetCount();
	void fillProgress(float percentage, TimerState state);
	void setTimerStateUi(TimerState state);

private:
	Ui::TimerPage* ui;

private:
	//component
	QTimer* m_Loop;
	class ScheduleDialog* m_ScheduleDialog;
	class TrayIcon* m_TrayIcon;

private:
	//Timer
	Pome::Clock m_EngineClock;
	TimerState m_CurState;
	QMetaObject::Connection m_PlayButtonConn;

	uint32_t m_SetTotal = 0;
	std::list<std::pair<TimerState, uint32_t>> m_ScheduleQueue;

	QString SSProgress_Porm =
		"QWidget{\n"
		"   border-radius: 135px;\n"
		"   background-color: qconicalgradient(cx:0.5, cy:0.5, angle:90, stop:{GradPoint_1} rgba(255, 255, 255, 0), stop:{GradPoint_2} rgba(255, 135, 135, 255));\n"
		"}";
	QString SSProgress_Break =
		"QWidget{\n"
		"   border-radius: 135px;\n"
		"   background-color: qconicalgradient(cx:0.5, cy:0.5, angle:90, stop:{GradPoint_1} rgba(255, 255, 255, 0), stop:{GradPoint_2} rgba(158, 184, 154, 255));\n"
		"}";

	QString SSProgress_Porm_bg =
		"QWidget{\n"
		"border-radius: 134px;\n"
		"background-color: qconicalgradient(cx : 0.5, cy : 0.5, angle : 90, stop : 0.0 rgba(255, 255, 255, 0), stop : 0.0 rgba(217, 10, 20, 30));\n"
		"}";
	QString SSProgress_Break_bg =
		"QWidget{\n"
		"border-radius: 134px;\n"
		"background-color: qconicalgradient(cx : 0.5, cy : 0.5, angle : 90, stop : 0.0 rgba(255, 255, 255, 0), stop : 0.0 rgba(158, 184, 154, 30));\n"
		"}";

	QString SSProgress;

	QString SSTimerState_Porm = "QWidget{ background-color : none; } QLabel{ color: rgb(255, 135, 135); font-size : 30px }";
	QString SSTimerState_Break = "QWidget{ background-color : none; } QLabel{ color: rgb(158, 184, 154); font-size : 30px }";

	QString SSTimerButton_Porm = "QPushButton{border:none; border-radius: 130px; background-color : rgb(240, 240, 240); color: rgb(255, 100, 100); font-size : 60px; font-weight : 100; }";
	QString SSTimerButton_Break = "QPushButton{border:none; border-radius: 130px; background-color : rgb(240, 240, 240); color: rgb(158, 204, 154); font-size : 60px; font-weight : 100; }";

	friend class ScheduleDialog;
};