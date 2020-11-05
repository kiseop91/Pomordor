#pragma once

class TodoItemList : public QWidget
{
public:
	TodoItemList(QWidget* parent = nullptr);

	~TodoItemList();

public:
	void PushItem(const QString& todoStr, const QString& description);

protected:
	void wheelEvent(QWheelEvent* event) override;

private:
	std::vector<class TodoItemWidget*> m_Items;
	int dir;
	int callCount = 0;
	QTimer* m_WheelLoop;
};
