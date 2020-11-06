#include "pompch.h"

#include "TodoPage.h"
#include "ui_TodoPage.h"

TodoPage::TodoPage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::TodoPage)
{
    ui->setupUi(this);
	ui->ItemList->SetScrollbar(ui->ScrollBar);
	ui->ItemList->PushItem("todo", "desc");

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(AddItem()));
}

void TodoPage::AddItem()
{
	ui->ItemList->PushItem("todo", "desc");
}

TodoPage::~TodoPage()
{
    delete ui;
}