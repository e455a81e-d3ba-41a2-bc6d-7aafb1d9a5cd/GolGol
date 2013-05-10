#include "Field.h"
#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QResizeEvent>
#include <QMouseEvent>
#include <cstdio>
#include <cstdlib>

Field::Field(QWidget *parent) :
	QWidget(parent), mArea(0), mField(std::vector<bool>(0)), mFieldWidth(0), mFieldHeight(0), cmPixelSize(8), mMouseDown(false), mState(NONE)
{
	int height = size().height();
	int width = size().width();

	try {
		mArea = new QPixmap(width, height);
		mArea->fill(Qt::white);
		mField = std::vector<bool>((width * height) / (cmPixelSize * cmPixelSize), false);
		mFieldWidth = width / cmPixelSize;
		mFieldHeight = height / cmPixelSize;
	} catch (std::bad_alloc e) {
		FILE* f = fopen("error.log", "w");

		if (!f) {
			exit(EXIT_FAILURE);
		}
		fprintf(f, "\n%s\nFailed to allocate memory\n\tFile: %s\n\tLine: %d\n\tDate:%s %s\n", e.what(), __FILE__, __LINE__, __DATE__, __TIME__);
		fclose(f);
		exit(EXIT_FAILURE);
	} catch (...) {
		FILE* f = fopen("error.log", "w");

		if (!f) {
			exit(EXIT_FAILURE);
		}
		fprintf(f, "\nUnknown exception encountered\n\tFile: %s\n\tLine: %d\n\tDate:%s %s\n", __FILE__, __LINE__, __DATE__, __TIME__);
		fclose(f);
		exit(EXIT_FAILURE);
	}

	if (!mArea) {
		FILE* f = fopen("error.log", "w");

		if (!f) {
			exit(EXIT_FAILURE);
		}
		fprintf(f, "\nNull pointer encountered\n\tFile: %s\n\tLine: %d\n\tDate:%s\n", __FILE__, __LINE__, __DATE__);
		fclose(f);
		exit(EXIT_FAILURE);
	}
}

Field::~Field()
{
	delete mArea;
}

Field::State Field::getState() const
{
	return mState;
}

void Field::resizeEvent(QResizeEvent *event)
{
	qDebug() << "resizeEvent";
	int height = event->size().height();
	int width = event->size().width();
	QPixmap tmp = this->mArea->copy();
	qDebug() << "Width: " << width;
	qDebug() << "Height: " << height;

	try {
		delete mArea;
		mArea = new QPixmap(width, height);
		*mArea = tmp.scaled(width, height);
		mField = std::vector<bool>((width * height) / (cmPixelSize * cmPixelSize), false);
		mFieldWidth = width / cmPixelSize;
		mFieldHeight = height / cmPixelSize;

		qDebug() << "mField.size(): " << (width * height) / (cmPixelSize * cmPixelSize);
	} catch (std::bad_alloc) {
		FILE* f = fopen("error.log", "w");

		if (!f) {
			exit(EXIT_FAILURE);
		}
		fprintf(f, "Failed to allocate memory\n\tFile: %s\n\tLine: %d\n", __FILE__, __LINE__);
		fclose(f);
		exit(EXIT_FAILURE);
	} catch (...) {
		FILE* f = fopen("error.log", "w");

		if (!f) {
			exit(EXIT_FAILURE);
		}
		fprintf(f, "Unknown exception encountered\n\tFile: %s\n\tLine: %d\n", __FILE__, __LINE__);
		fclose(f);
		exit(EXIT_FAILURE);
	}
	if (!mArea) {
		FILE* f = fopen("error.log", "w");

		if (!f) {
			exit(EXIT_FAILURE);
		}
		fprintf(f, "Null pointer encountered\n\tFile: %s\n\tLine: %d\n", __FILE__, __LINE__);
		fclose(f);
		exit(EXIT_FAILURE);
	}
}

void Field::paintEvent(QPaintEvent *event)
{
	qDebug() << "paintEvent";
	QPainter painter(this);
	if (mArea) {
		painter.drawPixmap(0, 0, *mArea);
	}
}

void Field::mousePressEvent(QMouseEvent *event)
{
	qDebug() << "mousePressEvent";
	mMouseDown = true;
}

void Field::mouseReleaseEvent(QMouseEvent *event)
{
	qDebug() << "mouseReleaseEvent";
	mMouseDown = false;
}

void Field::mouseMoveEvent(QMouseEvent *event)
{
	qDebug() << "X: " << event->x();
	qDebug() << "Y: " << event->y();
	if (mMouseDown) {
		QPainter painter(mArea);
		int x = event->x();
		int y = event->y();
		int adjX = x / cmPixelSize;
		int adjY = y / cmPixelSize;
		QRect rect(adjX * cmPixelSize, adjY * cmPixelSize, cmPixelSize, cmPixelSize);
		mField[adjY * mFieldWidth + adjY] = true;
		painter.fillRect(rect, Qt::black);
		painter.drawRect(rect);

		qDebug() << "adjX: " << adjX;
		qDebug() << "ajdY: " << adjY;
	}
}

void Field::play()
{
	qDebug() << "play";
	mState = PLAY;
}

void Field::pause()
{
	qDebug() << "pause";
	mState = PAUSE;
}

void Field::step()
{
	qDebug() << "step";
	mState = STEP;
}

void Field::reset()
{
	qDebug() << "reset";
	mState = RESET;
}