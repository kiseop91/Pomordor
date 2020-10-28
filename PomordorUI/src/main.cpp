#include "pompch.h"
#include "MainWindow/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QFontDatabase::addApplicationFont(":/font/fonts/segoeui.ttf");

    MainWindow w;
    w.show();

    return a.exec();
}
