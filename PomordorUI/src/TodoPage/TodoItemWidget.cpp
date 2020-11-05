#include "pompch.h"

#include "TodoItemWidget.h"
#include "ui_TodoItemWidget.h"

TodoItemWidget::TodoItemWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::TodoItemWidget)
{
	ui->setupUi(this);
	show();
	this->setAttribute(Qt::WA_Hover, true);
}

TodoItemWidget::~TodoItemWidget()
{
}

void TodoItemWidget::SetDescription(const QString & str)
{
}

void TodoItemWidget::SetTodo(const QString & str)
{
}

void TodoItemWidget::enterEvent(QEvent * event)
{
	qDebug() << "is Mouse Hove";
}
