#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class TodoItemWidget; }

class TodoItemWidget : QWidget
{
	Q_OBJECT

public:
	TodoItemWidget(QWidget* parent = nullptr);
	~TodoItemWidget();


private:
	Ui::TodoItemWidget* ui;

};