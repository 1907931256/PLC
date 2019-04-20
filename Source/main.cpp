#include "mainwindow.h"
#include <QApplication>
#include <QString>
QString px1="";
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    px1=a.applicationDirPath();
    MainWindow w;
    w.show();

    return a.exec();
}

