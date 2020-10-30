#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class TimerPage; }
QT_END_NAMESPACE

class TimerPage : public QWidget
{
	Q_OBJECT

public:
	TimerPage(QWidget *parent = nullptr);
	~TimerPage();

public:
	void ToastMessage(const QString& title, const QString& text, int duration_ms);

private slots:
	void onTimerStart();
	void onTimerStop();
	void onTimerLoop();

	void onToggleSchduleDialog();

private:
	//component
	Ui::TimerPage* ui;
	QTimer* m_Loop;
	
	QMetaObject::Connection m_PlayButtonConn;
	class Timer* m_Timer;
	class ScheduleDialog* m_ScheduleDialog;
	class TrayIcon* m_TrayIcon;

	friend class ScheduleDialog;
	friend class Timer;
};