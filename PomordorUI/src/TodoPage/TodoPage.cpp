#include "pompch.h"

#include "TodoPage.h"
#include "ui_TodoPage.h"

TodoPage::TodoPage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::TodoPage)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(AddItem()));
}

void TodoPage::AddItem()
{
    auto item = new QListWidgetItem;
    auto itemStr = ui->lineEdit->text();
    item->setText(itemStr);

    ui->lineEdit->setText("");
    ui->listWidget->addItem(item);
}

void TodoPage::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Enter) 
		return;

    if(ui->lineEdit->text() != "") 
    {
        AddItem();
    }
}

TodoPage::~TodoPage()
{
    delete ui;
}