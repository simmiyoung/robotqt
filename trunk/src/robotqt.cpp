#include <QtGui>

#include "robotqt.h"
#include "config.h" // for debugging

RobotQt::RobotQt()
{
    QTabWidget *leftTab = new QTabWidget;
    QListWidget *listStatus = new QListWidget;
    QTextEdit *editSource = new QTextEdit;

    leftTab->addTab(listStatus, tr("&Status"));
    leftTab->addTab(editSource, tr("S&ource"));

    right2DGraph = new QWidget;

    mainSplitter = new QSplitter(Qt::Horizontal);
    mainSplitter->addWidget(leftTab);
    mainSplitter->addWidget(right2DGraph);
    mainSplitter->setStretchFactor(1,1);

    setCentralWidget(mainSplitter);

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
