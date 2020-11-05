#include "pompch.h"

#include "TodoItemList.h"
#include "TodoItemWidget.h"

TodoItemList::TodoItemList(QWidget* parent)
	: QWidget(parent)
{
}

void TodoItemList::PushItem(TodoItemWidget* item)
{
	m_Widgets.push_back(item);
}

TodoItemList::~TodoItemList()
{

}