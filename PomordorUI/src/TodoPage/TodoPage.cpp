#include "pompch.h"

#include "TodoPage.h"
#include "ui_TodoPage.h"

TodoPage::TodoPage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::TodoPage)
{
    ui->setupUi(this);

	ui->ItemList->LinkScrollbar(ui->ScrollBar);
	ui->PageTitle->setFont(QFont("Segoe UI", 20, 100));
	ui->AddDescript->setFont(QFont("Segoe UI", 10, 50));

	connect(ui->AddTodoButton, SIGNAL(clicked()), SLOT(AddItem()));
}

void TodoPage::AddItem()
{
	ui->ItemList->PushItem("todo", "desc");
}


TodoPage::~TodoPage()
{
    delete ui;
}