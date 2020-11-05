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
	void SetDescription(const QString& str);
	void SetTodo(const QString& str);

protected:
	void enterEvent(QEvent* event);

private:
	Ui::TodoItemWidget* ui;

};