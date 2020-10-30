#include "pompch.h"
#include "Timer/Timer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QFontDatabase::addApplicationFont(":/font/fonts/segoeui.ttf");
	QFontDatabase::addApplicationFont(":/font/fonts/D2Coding.ttf");

    Timer t;
    t.show();

    return a.exec();
}
