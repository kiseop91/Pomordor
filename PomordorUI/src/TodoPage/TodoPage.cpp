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
}

void TodoPage::AddItem()
{

}

TodoPage::~TodoPage()
{
    delete ui;
}