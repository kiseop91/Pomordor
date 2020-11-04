#pragma once

QT_BEGIN_NAMESPACE
namespace Ui{ class TodoPage; }
QT_END_NAMESPACE

class TodoPage : public QWidget
{
    Q_OBJECT

public:
    TodoPage(QWidget* parent = nullptr);
    ~TodoPage();

private slots:
    void AddItem();

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    Ui::TodoPage* ui;
};