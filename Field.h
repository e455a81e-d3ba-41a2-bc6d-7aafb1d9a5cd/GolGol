#ifndef FIELD_H
#define FIELD_H

#include <QWidget>

class QPixmap;
class QResizeEvent;

class Field : public QWidget
{
	Q_OBJECT
	QPixmap *mArea;
	std::vector<bool> mField;
	unsigned mFieldWidth;
	unsigned mFieldHeight;
	const unsigned cmPixelSize;
	bool mMouseDown;

public:
	explicit Field(QWidget *parent = 0);
	virtual ~Field();

	enum State {
		NONE,
		PLAY,
		PAUSE,
		STEP,
		RESET
	};

	State getState() const;

protected:
	void resizeEvent (QResizeEvent *event);
	void paintEvent (QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private:
	State mState;

signals:
    
public slots:
	void play();
	void pause();
	void step();
	void reset();
    
};

#endif // FIELD_H
