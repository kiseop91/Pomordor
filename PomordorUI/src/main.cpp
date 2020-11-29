#include "pompch.h"
#include "TimerPage/TimerPage.h"
#include "SplashWidget/splashwidget.h"
#include "MainWindow/mainwindow.h"

#include <Windows.h>

//To DO : Set CMakeList.txt Debug Mode PreProcessor Define.
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	SetProcessDPIAware();

    QApplication a(argc, argv);
				
	QFontDatabase::addApplicationFont(":/font/fonts/segoeui.ttf");
	QFontDatabase::addApplicationFont(":/font/fonts/D2Coding.ttf");

	MainWindow mainWindow;
	SplashWidget s(&mainWindow);

    return a.exec();
}
