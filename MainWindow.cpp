#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->setWindowTitle("GolGol");
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButtonPlay_clicked()
{
	ui->fieldwidget->play();
}

void MainWindow::on_pushButtonPause_clicked()
{
	ui->fieldwidget->pause();
}

void MainWindow::on_pushButtonStep_clicked()
{
	ui->fieldwidget->step();
}

void MainWindow::on_pushButtonReset_clicked()
{
	ui->fieldwidget->reset();
}
