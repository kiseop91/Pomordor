#include "pompch.h"

#include "TrayIcon.h"
#include "Timer.h"

TrayIcon::TrayIcon(const QIcon& icon, Timer * myTimer, QWidget * parent)
	: QSystemTrayIcon(icon, parent)
	, m_MyTimer(myTimer)
	, m_Menu(new QMenu)
	, m_Close(new QAction("Close"))
	, m_Show(new QAction("Show"))
{
	m_Menu->addActions({ m_Close, m_Show });
	setContextMenu(m_Menu);

	connect(m_Close, &QAction::triggered, [this]() { m_MyTimer->close(); });
	connect(m_Show, &QAction::triggered, [this]() { if (m_MyTimer->isHidden()) m_MyTimer->show(); });
	connect(this, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), SLOT(OnClick(QSystemTrayIcon::ActivationReason)));
	show();
}

void TrayIcon::OnClick(QSystemTrayIcon::ActivationReason Rw)
{
	if (Rw != QSystemTrayIcon::DoubleClick)
		return;
	if (m_MyTimer->isHidden())
		m_MyTimer->show();
}

TrayIcon::~TrayIcon()
{
	delete m_Close;
	delete m_Show;
	delete m_Menu;
}
