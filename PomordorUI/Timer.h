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
	//void Start();

public:
	bool isRunning = false;
	QString styleSheet;

private:
	Ui::Timer *ui;

	float progress = 0.99f;
	float stop = 0.991f;
};
