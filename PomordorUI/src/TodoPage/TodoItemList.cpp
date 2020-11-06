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
		UpdateScrollbar();
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
	item->SetTodo(QString::number(m_Items.size() + 1));
	item->SetDescription(description);

	item->SetIndex(m_Items.size());
	item->AdjustOffsetPos(Offset);
	m_Items.emplace_back(item);

	if (m_Items.size() == 8)
	{
		OffsetMax += m_Items.size() * TodoItemWidget::GetHeight() - this->height();
	}
	else if(m_Items.size() > 8)
	{
		OffsetMax += TodoItemWidget::GetHeight();
	}

	UpdateScrollbar();
}

void TodoItemList::EraseItem(uint32_t idx)
{
	auto item = m_Items.begin() + idx;
	if (m_Items.size() == 8)
	{
		OffsetMax -= m_Items.size() * TodoItemWidget::GetHeight() - this->height();
	}
	else if (m_Items.size() > 8)
	{
		OffsetMax -= TodoItemWidget::GetHeight();
	}

	if (Offset > OffsetMax)
	{
		Offset = OffsetMax;
	}

	delete *item;
	m_Items.erase(item);

	for (size_t i = 0; i < m_Items.size(); ++i)
	{
		m_Items[i]->SetIndex(i);
		m_Items[i]->AdjustOffsetPos(Offset);
	}

	UpdateScrollbar();
}

void TodoItemList::UpdateScrollbar()
{
	if (m_Items.size() < 8)
	{
		m_ScrollBar->hide();
		return;
	}

	m_ScrollBar->show();
	
	ScrollBarHeight = 7.2f / (float)m_Items.size() * ScrollBarMaxHeight;
	uint32_t scrollBarMaxY = ScrollBarMaxHeight - ScrollBarHeight;
	ScrollBarY = (Offset / (float)OffsetMax) * scrollBarMaxY;

	m_ScrollBar->setGeometry(346, ScrollBarY, 2, ScrollBarHeight);
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
