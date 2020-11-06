#include "pompch.h"

#include "TodoPage.h"
#include "ui_TodoPage.h"

TodoPage::TodoPage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::TodoPage)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::FramelessWindowHint);

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(AddItem()));
	ui->ItemList->PushItem("todo", "desc");
}

void TodoPage::AddItem()
{
	ui->ItemList->PushItem("todo", "desc");
}

TodoPage::~TodoPage()
{
    delete ui;
}