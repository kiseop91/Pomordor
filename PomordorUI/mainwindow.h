#pragma once

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
	void onClickPushButton();
	void onClickToggleButton();
private:
    Ui::MainWindow *ui;

	int mouseX; 
	int mouseY; 
	int absX;
	int absY; 
	int justOneCount;

	void mouseMoveEvent(QMouseEvent *mouse);
	void mouseReleaseEvent(QMouseEvent *); 

};

