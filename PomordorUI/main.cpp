#include "pompch.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
	Pome::EngineInit();

    w.show();
    return a.exec();
}
