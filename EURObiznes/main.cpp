#include "mainwindow.h"

#include <QApplication>

double CRysPionek::parA_ = 0.03;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
