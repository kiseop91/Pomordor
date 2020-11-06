#include "pompch.h"

#include "TodoItemList.h"
#include "TodoItemWidget.h"

TodoItemList::TodoItemList(QWidget* parent)
	: QWidget(parent)
	, m_WheelLoop(new QTimer)
{
	connect(m_WheelLoop, &QTimer::timeout, [this]() {
		++callCount;
		if (   
			!(0 <= Offset && Offset <= OffsetMax)
			|| (Offset == 0 && dir == 1)
			|| (Offset == OffsetMax && dir == -1)
		)
		{
			callCount = 0;
			m_WheelLoop->stop();
			return;
		}
		
		Offset -= 5 * dir;
		qDebug() << Offset;
		for (auto& item : m_Items)
		{
			item->AdjustOffsetPos(Offset);
		}

		if (callCount > 10)
		{
			callCount = 0;
			m_WheelLoop->stop();
		}
	});
}


TodoItemList::~TodoItemList()
{
	for (auto item : m_Items)
		delete item;

	m_Items.clear();
}


void TodoItemList::PushItem(const QString & todoStr, const QString & description)
{
	TodoItemWidget* item = new TodoItemWidget(this);
	item->SetTodo(todoStr);
	item->SetDescription(description);

	item->SetIndex(m_Items.size());
	item->AdjustOffsetPos(Offset);
	m_Items.emplace_back(item);

	if (m_Items.size() == 8)
	{
		OffsetMax += m_Items.size() * item->GetHeight() - this->height();
	}
	else if(m_Items.size() > 8)
	{
		OffsetMax += item->GetHeight();
	}
}


void TodoItemList::wheelEvent(QWheelEvent * event)
{
	if (m_Items.size() < 8)
		return;
	m_WheelLoop->stop();

	callCount = 0;
	dir = event->angleDelta().ry() > 0 ? 1 : -1;

	m_WheelLoop->start(10);

	event->accept();
}
