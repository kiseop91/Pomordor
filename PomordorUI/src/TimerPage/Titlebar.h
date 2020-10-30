#pragma once

class TitleBar : public QFrame
{
public:
	TitleBar(QWidget* parent = nullptr);
	~TitleBar();

protected:
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

private:
	uint32_t mouseX;
	uint32_t mouseY;
	uint32_t absX;
	uint32_t absY;

	QWidget* parent;
	bool inFirst = true;
};