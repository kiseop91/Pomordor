#include "pompch.h"
#include "Timer/Timer.h"
#include <Windows.h>

int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	SetProcessDPIAware();

    QApplication a(argc, argv);
				
	QFontDatabase::addApplicationFont(":/font/fonts/segoeui.ttf");
	QFontDatabase::addApplicationFont(":/font/fonts/D2Coding.ttf");

    Timer t;
    t.show();

    return a.exec();
}
