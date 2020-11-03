#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SplashWidget; }
QT_END_NAMESPACE

class SplashWidget : public QWidget
{
    Q_OBJECT

public:
    SplashWidget(QWidget *parent = nullptr);
    ~SplashWidget();
private:
    void progress();
private:
    Ui::SplashWidget *ui;
    QTimer *m_Timer;
    QWidget* m_PomodorTimer;
};
