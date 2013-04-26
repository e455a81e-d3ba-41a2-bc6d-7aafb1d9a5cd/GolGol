#include "Field.h"
#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QResizeEvent>
#include <cstdio>
#include <cstdlib>

Field::Field(QWidget *parent) :
	QWidget(parent), mArea(0), mState(NONE)
{
	int height = size().height();
	int width = size().width();

	try {
		mArea = new QPixmap(width, height);
		mArea->fill(Qt::white);
	} catch (...) {
		FILE* f = fopen("error.log", "w");

		if (!f) {
			exit(EXIT_FAILURE);
		}
		fprintf(f, "Failed to allocate memory\n\tFile: %s\n\tLine: %d\n", __FILE__, __LINE__);
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

	try {
		delete mArea;
		mArea = new QPixmap(width, height);
		*mArea = tmp.scaled(width, height);
	} catch (...) {
		FILE* f = fopen("error.log", "w");

		if (!f) {
			exit(EXIT_FAILURE);
		}
		fprintf(f, "Failed to allocate memory\n\tFile: %s\n\tLine: %d\n", __FILE__, __LINE__);
		fclose(f);
		exit(EXIT_FAILURE);
	}
}

void Field::paintEvent(QPaintEvent *event)
{
	qDebug() << "paintEvent";
	QPainter painter(this);
	painter.drawPixmap(0, 0, *mArea);
}

void Field::mousePressEvent(QMouseEvent *event)
{
	qDebug() << "mousePressEvent";
}

void Field::mouseReleaseEvent(QMouseEvent *event)
{
	qDebug() << "mouseReleaseEvent";
}

void Field::play()
{
	qDebug() << "play";
}

void Field::pause()
{
	qDebug() << "pause";
}

void Field::step()
{
	qDebug() << "step";
}

void Field::reset()
{
	qDebug() << "reset";
}
