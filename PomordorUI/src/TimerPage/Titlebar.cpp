#include "pompch.h"

#include "Titlebar.h"

TitleBar::TitleBar(QWidget * parent)
	: QFrame(parent)
	, parent(parent)
{
}

TitleBar::~TitleBar()
{

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
	//parent->move(mouseX - absX, mouseY - absY);
	this->parentWidget()->move(mouseX - absX, mouseY - absY);
}

void TitleBar::mouseReleaseEvent(QMouseEvent* event)
{
	inFirst = true;
}


