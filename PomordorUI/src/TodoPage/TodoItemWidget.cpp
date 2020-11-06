#include "pompch.h"

#include "TodoItemWidget.h"
#include "ui_TodoItemWidget.h"
#include "TodoItemList.h"

TodoItemWidget::TodoItemWidget(QWidget* parent)
	: QWidget(parent)
	, m_MyList(static_cast<TodoItemList*>(parent))
	, ui(new Ui::TodoItemWidget)
	, m_Menu(new QMenu)
	, m_DeleteAction(new QAction("delete"))
	, m_EditAction(new QAction("edit"))
{
	ui->setupUi(this);
	show();
	this->setAttribute(Qt::WA_Hover, true);

	m_Menu->addActions({ m_DeleteAction, m_EditAction });

	connect(m_DeleteAction, &QAction::triggered, [this]() {m_MyList->EraseItem(Index); });
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
	setStyleSheet("QWidget{ background-color : rgb(233, 233, 233); }");
}

void TodoItemWidget::leaveEvent(QEvent * event)
{
	setStyleSheet("QWidget{ background-color : rgb(255, 255, 255); }");
}

void TodoItemWidget::mousePressEvent(QMouseEvent * event)
{
	if(event->button() == Qt::RightButton)
	{
		qDebug() << "hi";

		m_Menu->move(QCursor::pos().x(), QCursor::pos().y());
		m_Menu->show();
	}
	
	
}
