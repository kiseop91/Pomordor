#pragma once

class TodoItemList : public QWidget
{
public:
	TodoItemList(QWidget* parent = nullptr);

	~TodoItemList();

public:
	void PushItem(const QString& todoStr, const QString& description);
	void EraseItem(uint32_t idx);

	void UpdateScrollbar();
	void UpdateSelectedWidget(uint32_t idx);
	inline void SetScrollbar(QWidget* scrollBar) { m_ScrollBar = scrollBar; }

	void CalcPresentCount();

protected:
	void wheelEvent(QWheelEvent* event) override;

private:
	std::vector<class TodoItemWidget*> m_Items;
	int dir;
	int Offset = 0;
	int OffsetMax = 0;
	int callCount = 0;
	QTimer* m_WheelLoop;

	QWidget* m_ScrollBar;
	uint32_t ScrollBarHeight;
	const uint32_t ScrollBarMaxHeight = 440;
	uint32_t ScrollBarY;

	float presentLimit;
	uint32_t presentMax;

};
