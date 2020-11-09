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

	setFocusPolicy(Qt::StrongFocus);
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

	if (m_Items.size() == presentMax)
	{
		OffsetMax += m_Items.size() * TodoItemWidget::GetHeight() - this->height();
	}
	else if (m_Items.size() > presentMax)
	{
		OffsetMax += TodoItemWidget::GetHeight();
	}

	UpdateScrollbar();
}

void TodoItemList::EraseItem(uint32_t idx)
{
	auto item = m_Items.begin() + idx;
	if (m_Items.size() == presentMax + 1)
	{
		OffsetMax -= m_Items.size() * TodoItemWidget::GetHeight() - this->height();
	}
	else if (m_Items.size() > presentMax + 1)
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
	if (m_Items.size() <= presentMax)
	{
		m_ScrollBar->hide();
		return;
	}
	m_ScrollBar->show();

	ScrollBarHeight = (presentLimit / (float)m_Items.size()) * ScrollBarMaxHeight;
	uint32_t scrollBarMaxY = ScrollBarMaxHeight - ScrollBarHeight;
	ScrollBarY = (Offset / (float)OffsetMax) * scrollBarMaxY;

	m_ScrollBar->setGeometry(346, ScrollBarY, 2, ScrollBarHeight);
}

void TodoItemList::UpdateSelectedWidget(uint32_t idx)
{
	for (size_t i = 0; i < m_Items.size(); ++i)
	{
		if (idx == i)
		{
			m_Items[i]->onSelected = true;
			m_Items[i]->setStyleSheet("background-color : rgb(233, 233, 233);");
		}
		else
		{
			m_Items[i]->onSelected = false;
			if (m_Items[i]->onHover == false)
			{
				m_Items[i]->setStyleSheet("background-color : rgb(255, 255, 255);");
			}
		}
	}
}

void TodoItemList::CalcPresentCount()
{
	presentLimit = this->height() / (float)TodoItemWidget::GetHeight();
	presentMax = (int)presentLimit;
}

void TodoItemList::wheelEvent(QWheelEvent * event)
{
	float presentLimit = this->height() / (float)TodoItemWidget::GetHeight();
	if (m_Items.size() < presentLimit)
		return;
	m_WheelLoop->stop();

	callCount = 0;
	dir = event->angleDelta().ry() > 0 ? 1 : -1;

	m_WheelLoop->start(10);

	event->accept();
}

void TodoItemList::MoveSelectedWidget(uint32_t idx)
{
	UpdateSelectedWidget(idx);

	int left, top, right, bottom;
	m_Items[idx]->OriginalRect.getCoords(&left, &top, &right, &bottom);


	int curTopPoint = top - Offset;
	int curBottomPoint = bottom - Offset;

	if (curTopPoint < 0)
	{
		Offset += curTopPoint;
	}
	if (curBottomPoint > this->height())
	{
		Offset += curBottomPoint - this->height();
	}
	for (auto& item : m_Items)
	{
		item->AdjustOffsetPos(Offset);
	}
	UpdateScrollbar();

}


void TodoItemList::keyPressEvent(QKeyEvent * event)
{
	for (int i = 0; i < m_Items.size(); ++i)
	{
		if (m_Items[i]->onSelected == true)
		{
			if (event->key() == Qt::Key_Up && i != 0)
			{
				MoveSelectedWidget(i - 1);
				break;
			}

			if (event->key() == Qt::Key_Down && i != m_Items.size() - 1)
			{
				MoveSelectedWidget(i + 1);
				break;
			}
		}
	}
}
