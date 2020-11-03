#include "pompch.h"
#include "TimerPage/TimerPage.h"
#include "SplashWidget/splashwidget.h"

#include <Windows.h>

int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	SetProcessDPIAware();

	Pome::printJson();

    QApplication a(argc, argv);
				
	QFontDatabase::addApplicationFont(":/font/fonts/segoeui.ttf");
	QFontDatabase::addApplicationFont(":/font/fonts/D2Coding.ttf");

	TimerPage t;
	SplashWidget s(&t);


    return a.exec();
}
