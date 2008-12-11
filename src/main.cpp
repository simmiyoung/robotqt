#include "robotqt.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RobotQt w;
    w.show();
    return a.exec();
}
