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
	uint32_t GetHeight() const { return ItemWidgetWidth; }

	void SetDescription(const QString& str);
	void SetTodo(const QString& str);
	void SetIndex(uint32_t idx);
	void AdjustOffsetPos(uint32_t offset);

protected:
	void enterEvent(QEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;

private:
	Ui::TodoItemWidget* ui;
	class TodoItemList* m_MyList;

	const uint32_t ItemWidgetWidth = 50;
	uint32_t Index;

	QRect OriginalRect;
	QRect OffsetedRect;
};