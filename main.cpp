#include <QApplication>
#include "MainWindow.h"

int main (int argc, char** argv)
{
    QApplication app (argc, argv);

    MainWindow window;
    window.setFixedSize(640, 480);
    window.show();

    return app.exec();
}
