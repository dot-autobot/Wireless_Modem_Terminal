#include <QApplication>
#include "mainwindow.h"

#include <stdio.h>
#include <QtNetwork/QUdpSocket>

int main(int argc, char *argv[])
{
QApplication a(argc, argv);

   MainWindow::getInstance()->show();



   return a.exec();
}

