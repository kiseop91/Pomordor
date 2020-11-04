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
};