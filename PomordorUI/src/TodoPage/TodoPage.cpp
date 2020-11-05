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
	ui->frame_2->PushItem("todo", "desc");
}

void TodoPage::AddItem()
{
	ui->frame_2->PushItem("todo", "desc");
}

TodoPage::~TodoPage()
{
    delete ui;
}