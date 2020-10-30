#pragma once

class TrayIcon : public QSystemTrayIcon
{
	Q_OBJECT

public:
	TrayIcon(const QIcon& icon, class TimerPage* myTimer, QWidget* parent = nullptr);
	~TrayIcon();

private slots:
	void OnClick(QSystemTrayIcon::ActivationReason Rw);

public:
	TimerPage* m_MyTimer;

	QMenu* m_Menu;
	QAction* m_Close;
	QAction* m_Show;
};