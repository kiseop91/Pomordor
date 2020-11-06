#pragma once

class TitleBar : public QFrame
{
public:
	TitleBar(QWidget* parent = nullptr);
	~TitleBar();
	void SetParentWidget(QWidget * _widget);
protected:
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

private:
	uint32_t mouseX;
	uint32_t mouseY;
	uint32_t absX;
	uint32_t absY;

	QWidget* m_ParentWidget;
	bool inFirst = true;

	int m_Offset = 75; // ToDO : 임시처리, MainWindow의 경우 사이드바 때문에 75만큼 밀어줘야한다. 나중에 수정할 것.(offset삭제)
};