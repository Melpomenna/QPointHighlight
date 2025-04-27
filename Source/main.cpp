#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QIcon icon(":/favicon.ico");
    w.setWindowIcon(icon);
    w.show();
    return a.exec();
}
