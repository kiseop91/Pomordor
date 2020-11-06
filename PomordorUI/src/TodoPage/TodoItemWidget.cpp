#include "pompch.h"

#include "TodoItemWidget.h"
#include "ui_TodoItemWidget.h"
#include "TodoItemList.h"

TodoItemWidget::TodoItemWidget(QWidget* parent)
	: QWidget(parent)
	, m_MyList(static_cast<TodoItemList*>(parent))
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
	ui->label_2->setText(str);
}

void TodoItemWidget::SetTodo(const QString & str)
{
	ui->label->setText(str);
}

void TodoItemWidget::SetIndex(uint32_t idx) 
{ 
	Index = idx; 
	OriginalRect.setCoords(0, idx * ItemWidgetWidth, 330, (idx + 1) * ItemWidgetWidth);
}

void TodoItemWidget::AdjustOffsetPos(uint32_t offset)
{
	OffsetedRect = OriginalRect;
	OffsetedRect.adjust(0, -offset, 0, -offset);
	setGeometry(OffsetedRect);
}

void TodoItemWidget::enterEvent(QEvent * event)
{
	//qDebug() << "is Mouse Hove";
}

void TodoItemWidget::mousePressEvent(QMouseEvent * event)
{

	//if (event->button() == Qt::RightButton)
	//{
		m_MyList->EraseItem(Index);
		event->accept();
	//}
}
