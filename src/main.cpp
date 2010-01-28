#include <QApplication>
#include <QTime>

#include "robotqt.h"
#include "config.h"

// TODO: minimum Qt version requirement.

#if QT_VERSION < 0x040600 // needs Qt 4.6.0 or better
#error "Please use Qt 4.6 or a more recent version"
#endif

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
