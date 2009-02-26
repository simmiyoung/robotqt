/*
 * robotqt.cpp
 * RobotQt - Robot Simulation
 *
 * Created by Felipe Tonello on 2008-12-10.
 * Copyright 2008 Felipe Ferreri Tonello. All rights reserved.
 * http://robotqt.googlecode.com/
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

#include "robotqt.h"
#include "config.h" // for debugging

// GUI's
#include "sourceeditor.h"

#include <QSettings>

RobotQt::RobotQt(QWidget *parent) :
    QMainWindow(parent)
{
    qDebug() << "Setting up the MainWindow";
    setupUi(this);
    splitter->setStretchFactor(1,1);
    sourceEditor = NULL;

    qDebug() << "Creating Actions and Connections";

    connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(actionSourceEditor, SIGNAL(triggered()), this, SLOT(openSourceEdit()));
    connect(sourceButton, SIGNAL(clicked()), this, SLOT(openSourceEdit()));

    qDebug() << "Done! RobotQt Main Window created";

    readSettings();
}

RobotQt::~RobotQt()
{

}

void RobotQt::openSourceEdit(bool open)
{
    if (sourceEditor == NULL) {
        sourceEditor = new SourceEditor;
        sourceEditor->show();
    } else {
        sourceEditor->hide();
        delete sourceEditor;
        sourceEditor = NULL;
    }
}

//TODO: read settings
void RobotQt::readSettings()
{
    QSettings settings("RobotQt.org", "RobotQt");

//    qDebug() << "Reading settings for RobotQt Main Window";

    settings.beginGroup("RobotQtMainWindow");
    // do stuff
    settings.endGroup();
}
