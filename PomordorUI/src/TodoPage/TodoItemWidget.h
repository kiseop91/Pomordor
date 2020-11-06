#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class TodoItemWidget; }

class TodoItemWidget : public QWidget
{
	Q_OBJECT

public:
	TodoItemWidget(QWidget* parent = nullptr);
	~TodoItemWidget();

public:
	static const uint32_t GetHeight() { return ItemWidgetWidth; }

	void SetDescription(const QString& str);
	void SetTodo(const QString& str);
	void SetIndex(uint32_t idx);
	void AdjustOffsetPos(uint32_t offset);

protected:
	void enterEvent(QEvent* event) override;
	void leaveEvent(QEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;

private:
	Ui::TodoItemWidget* ui;
	class TodoItemList* m_MyList;

	static const uint32_t ItemWidgetWidth = 50;
	uint32_t Index;

	QRect OriginalRect;
	QRect OffsetedRect;

	QMenu* m_Menu;
	QAction* m_DeleteAction;
	QAction* m_EditAction;

	bool selected = false;
};