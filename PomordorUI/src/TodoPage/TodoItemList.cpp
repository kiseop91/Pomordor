#include "pompch.h"

#include "TodoItemList.h"
#include "TodoItemWidget.h"

TodoItemList::TodoItemList(QWidget* parent)
	: QWidget(parent)
	, m_WheelLoop(new QTimer)
{
	connect(m_WheelLoop, SIGNAL(timeout()), this, SLOT(onWheelAdjust()));
	setFocusPolicy(Qt::StrongFocus);
}


TodoItemList::~TodoItemList()
{
	for (auto item : m_Items)
		delete item;

	m_Items.clear();
}

void TodoItemList::ScrollBar::UpdatePosition()
{
	size_t itemCount = m_LinkedList->m_Items.size();
	uint32_t displayMaxCount = m_LinkedList->m_DisplayProp.MaxItemCount;
	float displayMax = m_LinkedList->m_DisplayProp.MaxItem;
	int displayOffset = m_LinkedList->m_DisplayProp.Offset;
	int displayOffsetMax = m_LinkedList->m_DisplayProp.OffsetMax;

	if (itemCount <= displayMaxCount)
	{
		this->hide();
		return;
	}

	m_Height = (displayMax / (float)itemCount) * m_HeightMax;
	m_TopMax = m_HeightMax - m_Height;
	m_Top = (displayOffset / (float)displayOffsetMax) * m_TopMax;

	setGeometry(this->x(), m_Top, this->width(), m_Height);
	show();
}

void TodoItemList::onWheelAdjust()
{
	if (
		!(0 <= m_DisplayProp.Offset && m_DisplayProp.Offset <= m_DisplayProp.OffsetMax)
		|| (m_DisplayProp.Offset == 0 && m_OnWheelUp)
		|| (m_DisplayProp.Offset == m_DisplayProp.OffsetMax && !m_OnWheelUp)
		)
	{
		m_WheelLoop->stop();
		return;
	}

	auto dir = m_OnWheelUp ? 1 : -1;
	m_DisplayProp.Offset -= 5 * dir;
	for (auto& item : m_Items)
	{
		item->AdjustOffsetPos(m_DisplayProp.Offset);
	}

	if (m_WheelAdjustCount > 10)
	{
		m_WheelLoop->stop();
	}

	m_ScrollBar->UpdatePosition();
}

void TodoItemList::PushItem(const QString & todoStr, const QString & description)
{
	calcPresentCount();

	TodoItemWidget* item = new TodoItemWidget(this);
	item->SetTodo(QString::number(m_Items.size() + 1));
	item->SetDescription(description);

	item->SetIndex(m_Items.size());
	item->AdjustOffsetPos(m_DisplayProp.Offset);
	m_Items.emplace_back(item);

	if (m_Items.size() == m_DisplayProp.MaxItemCount)
	{
		m_DisplayProp.OffsetMax += m_Items.size() * TodoItemWidget::GetHeight() - this->height();
	}
	else if (m_Items.size() > m_DisplayProp.MaxItemCount)
	{
		m_DisplayProp.OffsetMax += TodoItemWidget::GetHeight();
	}

	m_ScrollBar->UpdatePosition();
}

void TodoItemList::EraseItem(uint32_t idx)
{
	auto item = m_Items.begin() + idx;
	if (m_Items.size() == m_DisplayProp.MaxItemCount + 1)
	{
		m_DisplayProp.OffsetMax -= m_Items.size() * TodoItemWidget::GetHeight() - this->height();
	}
	else if (m_Items.size() > m_DisplayProp.MaxItemCount + 1)
	{
		m_DisplayProp.OffsetMax -= TodoItemWidget::GetHeight();
	}

	if (m_DisplayProp.Offset > m_DisplayProp.OffsetMax)
	{
		m_DisplayProp.Offset = m_DisplayProp.OffsetMax;
	}

	delete *item;
	m_Items.erase(item);

	for (size_t i = 0; i < m_Items.size(); ++i)
	{
		m_Items[i]->SetIndex(i);
		m_Items[i]->AdjustOffsetPos(m_DisplayProp.Offset);
	}

	m_ScrollBar->UpdatePosition();
}

void TodoItemList::updateSelectedWidget(uint32_t idx)
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

void TodoItemList::calcPresentCount()
{
	m_DisplayProp.MaxItem = this->height() / (float)TodoItemWidget::GetHeight();
	m_DisplayProp.MaxItemCount = (int)m_DisplayProp.MaxItem;
}


void TodoItemList::moveSelectedWidget(uint32_t idx)
{
	updateSelectedWidget(idx);

	int left, top, right, bottom;
	m_Items[idx]->OriginalRect.getCoords(&left, &top, &right, &bottom);

	int curTopPoint = top - m_DisplayProp.Offset;
	int curBottomPoint = bottom - m_DisplayProp.Offset;

	if (curTopPoint < 0)
	{
		m_DisplayProp.Offset += curTopPoint;
	}
	if (curBottomPoint > this->height())
	{
		m_DisplayProp.Offset += curBottomPoint - this->height();
	}
	for (auto& item : m_Items)
	{
		item->AdjustOffsetPos(m_DisplayProp.Offset);
	}
	m_ScrollBar->UpdatePosition();
}

void TodoItemList::wheelEvent(QWheelEvent * event)
{
	float presentLimit = this->height() / (float)TodoItemWidget::GetHeight();
	if (m_Items.size() < presentLimit)
		return;
	m_WheelLoop->stop();

	m_WheelAdjustCount = 0;
	m_OnWheelUp = event->angleDelta().ry() > 0 ? true : false;
	
	m_WheelLoop->start(10);

	event->accept();
}

void TodoItemList::keyPressEvent(QKeyEvent * event)
{
	for (int i = 0; i < m_Items.size(); ++i)
	{
		if (m_Items[i]->onSelected == true)
		{
			if (event->key() == Qt::Key_Up && i != 0)
			{
				moveSelectedWidget(i - 1);
				break;
			}

			if (event->key() == Qt::Key_Down && i != m_Items.size() - 1)
			{
				moveSelectedWidget(i + 1);
				break;
			}
		}
	}
}

