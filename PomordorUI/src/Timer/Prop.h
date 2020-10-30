#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class Prop; }
QT_END_NAMESPACE

class Prop : public QWidget
{
	Q_OBJECT

public:
	using Data = std::tuple<int, int, int>; //pomordor, break, set

public:
	Prop(class TimerPage* timer, QWidget* parent = nullptr);
	~Prop();

	Data GetData();

private slots:
	void OnClose();

private:
	Ui::Prop* ui;
	TimerPage* m_MyTimer;
};