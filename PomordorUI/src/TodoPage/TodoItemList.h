#pragma once
#include <Windows.h>
#include <winnt.h>

class TodoItemList : public QWidget
{
	Q_OBJECT

public:
	class ScrollBar : public QWidget
	{
	public:
		ScrollBar(QWidget* parent = nullptr)
			: QWidget(parent)
		{
			m_Height = height();

		}

	private:
		void UpdatePosition();

	private:
		TodoItemList* m_LinkedList = nullptr; //not means 'linked-list' as a data structure but current representative list

		uint32_t m_Top;
		uint32_t m_TopMax;
		uint32_t m_Height;
		uint32_t m_HeightMax = 440;

		friend class TodoItemList;
	};

private:
	//Property of listView
	struct ListDisplayProp
	{
		int Offset = 0;			
		int OffsetMax = 0;      

		uint32_t MaxItemCount;    
		float MaxItem;
	};

public:
	TodoItemList(QWidget* parent = nullptr);
	~TodoItemList();

public:
	void PushItem(const QString& todoStr, const QString& description);
	void EraseItem(uint32_t idx);

	inline void LinkScrollbar(ScrollBar* scrollBar) { m_ScrollBar = scrollBar;  m_ScrollBar->m_LinkedList = this;}

private slots:
	void onWheelAdjust();

protected:
	void wheelEvent(QWheelEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;

private:
	void updateSelectedWidget(uint32_t idx);
	void moveSelectedWidget(uint32_t idx);
	void calcPresentCount();

private:
	std::vector<class TodoItemWidget*> m_Items;
	
	ScrollBar* m_ScrollBar = nullptr;
	ListDisplayProp m_DisplayProp;

	QTimer* m_WheelLoop;
	uint32_t m_WheelAdjustCount = 0;
	bool m_OnWheelUp;

	friend class TodoItemWidget;
};
