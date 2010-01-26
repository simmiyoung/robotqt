#include <QApplication>

#include <QTime>
#include "robotqt.h"
#include "config.h"

int main(int argc, char *argv[])
{
    qInstallMsgHandler(handleRobotQtMessages);
    QApplication a(argc, argv);

    // setting random values
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    RobotQt w;
    w.show();
    return a.exec();
}
