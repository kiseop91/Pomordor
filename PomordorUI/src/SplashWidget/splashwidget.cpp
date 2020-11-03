#include "splashwidget.h"
#include "TimerPage/TimerPage.h"
#include "./ui_splashwidget.h"

#include <QGraphicsDropShadowEffect>
#include <QTimer>

SplashWidget::SplashWidget(QWidget *parent)
    : QWidget(nullptr)
    , ui(new Ui::SplashWidget)
{
    m_PomodorTimer = parent;
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

   QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect( );
   effect->setBlurRadius(20);
   effect->setXOffset(0);
   effect->setYOffset(0);
   effect->setColor(QColor(0,0,0,60));
   ui->dropShadowFrame->setGraphicsEffect(effect);

    m_Timer = new QTimer(this);
    connect(m_Timer, &QTimer::timeout, this, &SplashWidget::progress );
    m_Timer->start(35);

    ui->label_description->setText("<strong>WELCOME</strong> TO MY APPLICATION");

    QTimer::singleShot(1500, this, [&]{ui->label_description->setText("<strong>LOADING</strong> DATABASE"); });
    QTimer::singleShot(3000, this, [&]{ui->label_description->setText("<strong>LOADING</strong> USER INTERFACE"); });

    this->show();
}

void SplashWidget::progress()
{
    static int counter = 0;
    ui->progressBar->setValue(counter);

    if(counter > 100)
    {
        m_Timer->stop();

        m_PomodorTimer->show();

        this->close();
    }
    counter++;
}

SplashWidget::~SplashWidget()
{
    delete ui;
}

