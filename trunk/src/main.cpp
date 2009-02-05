#include <QApplication>

#include "robotqt.h"
#include "config.h"

int main(int argc, char *argv[])
{
    qInstallMsgHandler(handleRobotQtMessages);
    QApplication a(argc, argv);
    RobotQt w;
    w.show();
    return a.exec();
}
