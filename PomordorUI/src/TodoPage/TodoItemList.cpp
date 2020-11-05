#include "pompch.h"

#include "TodoItemList.h"
#include "TodoItemWidget.h"

TodoItemList::TodoItemList(QWidget* parent)
	: QWidget(parent)
	, m_WheelLoop(new QTimer)
{
	connect(m_WheelLoop, &QTimer::timeout, [this]() {
		++callCount;
		for (auto& item : m_Items)
		{
			item->setGeometry(0, item->y() + 5 * dir, 330, 50);
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

	item->setGeometry(0, m_Items.size() * 50, 330, 50);
	m_Items.emplace_back(item);
}


void TodoItemList::wheelEvent(QWheelEvent * event)
{
	m_WheelLoop->stop();
	callCount = 0;
	QPoint numPixels = event->pixelDelta();
	auto deg = event->angleDelta();
	
	qDebug() << "On Mouse Wheel" << numPixels.y() << deg.ry();
	scroll(0, numPixels.ry());

	dir = -1;
	if (deg.ry() > 0) dir = 1;
	m_WheelLoop->start(10);

	event->accept();
}
