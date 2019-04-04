#include "mainwindow.h"
#include <QApplication>
#include"sensor.h"
#include"communication.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    sensor::GetInstance()->InitAll();
    Communication::getInstance()->Open();
    w.show();
    return a.exec();
}
