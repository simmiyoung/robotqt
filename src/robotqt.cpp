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

#include <QtGui/QMessageBox>
#include <QtGui/QFileDialog>
#include <QSettings>

RobotQt::RobotQt(QWidget *parent) :
    QMainWindow(parent)
{
    qDebug() << "Setting up RobotQt Window and Widgets";
    setupUi(this);

    sourceEditor = new SourceEditor;

    splitter->setStretchFactor(1,1);


    qDebug() << "Creating Actions and Connections";

    createActions();

    qDebug() << "Done! RobotQt Main Window created";

    readSettings();
}

RobotQt::~RobotQt()
{

}

/*-----------------------------------------------------------------------------
 *  Private slots
 *-----------------------------------------------------------------------------*/

void RobotQt::openSourceEdit()
{
    sourceEditor->setVisible(!sourceEditor->isVisible());
}

void RobotQt::newFile()
{
    if (okToContinue()) {
        QString fileName = QFileDialog::getOpenFileName(this,
                                tr("Open a Robot source code"), ".",
                                tr("Robot source files (*.cpp *.py)"));
//        if (!fileName.isEmpty())
//            loadRobot(fileName);
    }
}

void RobotQt::openAbout()
{
    QMessageBox::about(this, tr("About RobotQt"),
        tr("<h2>RobotQt %1</h2>"
        "<p>Copyright &copy; 2009 Felipe Ferreri Tonello</p>"
        "<p>RobotQt is a robot simulator for academic proposes.</p>").arg(ROBOTQT_VERSION));
}


/*-----------------------------------------------------------------------------
 *  Private Methods
 *-----------------------------------------------------------------------------*/

void RobotQt::createActions()
{
    actionNew->setShortcut(QKeySequence::New);
    actionOpen->setShortcut(QKeySequence::Open);

    connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(actionAboutRobotQt, SIGNAL(triggered()), this, SLOT(openAbout()));
    connect(actionSourceEditor, SIGNAL(triggered()), this, SLOT(openSourceEdit()));
    connect(sourceButton, SIGNAL(clicked()), this, SLOT(openSourceEdit()));
}

bool RobotQt::okToContinue()
{
    if (isRobotModified()) {
        int r = QMessageBox::warning(this, tr("RobotQt"),
                    tr("This robot has been modified.\n"
                    "Do you want to save your changes?"),
                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (r == QMessageBox::Yes) {
//            save();
            return true;
        } else if (r == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}

bool RobotQt::isRobotModified() const
{
    return false;
}

void RobotQt::readSettings()
{
    QSettings settings("RobotQt.org", "RobotQt");

    qDebug() << "Reading settings for RobotQt Main Window";

    settings.beginGroup("RobotQtMainWindow");
    // do stuff
    settings.endGroup();
}
