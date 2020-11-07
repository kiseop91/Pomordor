#include "pompch.h"

#include "Titlebar.h"

TitleBar::TitleBar(QWidget * parent)
	: QFrame(parent), m_ParentWidget(nullptr)
{
}

TitleBar::~TitleBar()
{

}

void TitleBar::SetParentWidget(QWidget * _widget)
{
	m_ParentWidget = _widget;
}

void TitleBar::mouseMoveEvent(QMouseEvent * event)
{
	if (this->isMaximized() == true)
		return;

	if (event->button() == Qt::RightButton)
		return;

	mouseX = QCursor::pos().x();
	mouseY = QCursor::pos().y();
	
	if (inFirst)
	{
		absX = event->pos().x();
		absY = event->pos().y();
		inFirst = false;
	}

	
	if(m_ParentWidget == nullptr ) {
		m_ParentWidget = this->parentWidget();
		m_Offset = 0;
	}

	m_ParentWidget->move(mouseX - absX - m_Offset, mouseY - absY);
}

void TitleBar::mouseReleaseEvent(QMouseEvent* event)
{
	inFirst = true;
}


