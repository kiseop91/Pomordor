#include "pompch.h"

#include "TodoPage.h"
#include "ui_TodoPage.h"

TodoPage::TodoPage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::TodoPage)
{
    ui->setupUi(this);
	ui->ItemList->SetScrollbar(ui->ScrollBar);
	ui->PageTitle->setFont(QFont("Segoe UI", 20, 100));

	ui->Label->setFont(QFont("Segoe UI", 10, 50));

	ui->Line->hide();
	connect(ui->Label, SIGNAL(clicked()), SLOT(WriteTodo()));
	connect(this, SIGNAL(clickedEnter()), SLOT(AddItem()));
	connect(ui->AddTodoButton, SIGNAL(clicked()), SLOT(AddItem()));
}

void TodoPage::WriteTodo()
{
	ui->Label->hide();
	ui->Line->show();
	ui->Line->setFocus();
}

void TodoPage::keyPressEvent(QKeyEvent * event)
{
	event->accept();
	

	if (event->key() == Qt::Key_Return)
	{
		emit clickedEnter();
	}
}

void TodoPage::AddItem()
{
	if (ui->Line->isHidden()) return;
	ui->Label->show();
	ui->Line->hide();

	auto text = ui->Line->text();
	if (text.isEmpty()) return;
	
	ui->Line->setText("");
	
	ui->ItemList->CalcPresentCount();
	ui->ItemList->PushItem(text, "Todo");
}


TodoPage::~TodoPage()
{
    delete ui;
}


