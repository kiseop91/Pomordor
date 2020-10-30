#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class ScheduleDialog; }
QT_END_NAMESPACE

class ScheduleDialog : public QWidget
{
	Q_OBJECT

public:
	using Data = std::tuple<int, int, int>; //pomordor, break, set

public:
	ScheduleDialog(class TimerPage* page, QWidget* parent = nullptr);
	~ScheduleDialog();

	Data GetData();

private slots:
	void OnClose();
	void onScheduleValueChanged();

	void applyScheduleValue();

private:
	Ui::ScheduleDialog* ui;
	TimerPage* m_MyPage;

	friend class TimerPage;
};