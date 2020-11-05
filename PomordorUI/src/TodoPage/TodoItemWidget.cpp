#include "pompch.h"

#include "TodoItemWidget.h"
#include "ui_TodoItemWidget.h"

TodoItemWidget::TodoItemWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::TodoItemWidget)
{
	ui->setupUi(this);
}

TodoItemWidget::~TodoItemWidget()
{
}
