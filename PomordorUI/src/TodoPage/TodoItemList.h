#pragma once

class TodoItemList : public QWidget
{
public:
	TodoItemList(QWidget* parent = nullptr);
	~TodoItemList();

public:
	void PushItem(class TodoItemWidget* item);

private:
	std::vector<TodoItemWidget*> m_Widgets;

};
