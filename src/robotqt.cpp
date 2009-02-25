#include <QtGui>

#include "ui_robotqt.h"
#include "config.h" // for debugging

Ui_RobotQt::Ui_RobotQt()
{
    Ui::RobotQt::setupUi()
    splitter->setStretchFactor(1,1);

    qDebug() << "RobotQt Main Window created";

    readSettings();
}

RobotQt::~RobotQt()
{

}

void RobotQt::readSettings()
{
    QSettings settings("RobotQt.org", "RobotQt");

    qDebug() << "Reading settings for RobotQt Main Window";

    settings.beginGroup("RobotQtWindow");
    //do stuff
    settings.endGroup();
}
