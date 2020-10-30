#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class Timer; }
QT_END_NAMESPACE

class Timer : public QWidget
{
	Q_OBJECT

public:
	enum class RunningState
	{
		Porm,
		Break,
		None,
	};

public:
	Timer(QWidget *parent = nullptr);
	~Timer();

private slots:
	void OnStart();
	void OnStop();
	void OnRunning();
	void OnProp();

private:
	void UpdateTimerData();
	void UpdateSetCount();
	void FillProgress(float percentage, RunningState state);
	void SetRunningStateUi(RunningState state);

private:
	Ui::Timer* ui;

private:
	//component
	QTimer* m_Timer;
	class Prop* m_PropDialog;
	class TrayIcon* m_TrayIcon;

private:
	//Timer
	Pome::Clock m_EngineClock;
	RunningState m_CurState;
	QMetaObject::Connection m_PlayButtonConn;

	uint32_t m_SetTotal = 0;
	std::list<std::pair<RunningState, uint32_t>> m_ScheduleQue;

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
	QString SSProgress;

	QString SSRunningState_Porm = "QWidget{ background-color : none; } QLabel{ color: rgb(255, 135, 135); font-size : 30px }";
	QString SSRunningState_Break = "QWidget{ background-color : none; } QLabel{ color: rgb(158, 184, 154); font-size : 30px }";

	friend class Prop;
};