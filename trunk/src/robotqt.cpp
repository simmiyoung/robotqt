/*
 * robotqt.cpp
 * RobotQt - Robot Simulation
 *
 * Created by Felipe Tonello on 2008-12-10.
 * Copyright 2008-2009 Felipe Ferreri Tonello. All rights reserved.
 * http://robotqt.googlecode.com/
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

#include "robotqt.h"
#include "config.h" // for debugging
#include "robotcore/pluginbase.h"
#include "robotcore/robotinterface.h"
#include "robotcore/sensorinterface.h"

// GUI's
#include "sourceeditor.h"

#include "statusitem.h"

#include <QtGui>
#include <QSettings>
#include <QPluginLoader>

RobotQt::RobotQt(QWidget *parent) :
    QMainWindow(parent)
{
    qDebug() << "Setting up RobotQt Window and Widgets";
    setupUi(this);

    sourceEditor = new SourceEditor;

    timer = new QTimer(this);

    splitter->setStretchFactor(1,1);

    scene = new QGraphicsScene(-200, -250, 400, 500);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    simulatorGraphicsView->setScene(scene);
    simulatorGraphicsView->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    simulatorGraphicsView->setCacheMode(QGraphicsView::CacheBackground);
    simulatorGraphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    simulatorGraphicsView->setDragMode(QGraphicsView::ScrollHandDrag);


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

void RobotQt::openFile()
{
    if (okToContinue()) {
        QString fileName = QFileDialog::getOpenFileName(this,
                                tr("Open a Robot source code"), ".",
                                tr("Robot source files (*.robot)"));
       if (!fileName.isEmpty()) {
           loadRobot(fileName);
        }
    }
}

void RobotQt::openAbout()
{
    QMessageBox::about(this, tr("About RobotQt"),
        tr("<h2>RobotQt %1</h2>"
        "<p>Copyright &copy; 2008-2009 Felipe Ferreri Tonello</p>"
        "<p>RobotQt is a robot simulator for academic proposes.</p>").arg(ROBOTQT_VERSION));
}

void RobotQt::startOrStopSimulation()
{
    if (currentRobot != NULL) {
        if (timer->isActive()) {
            timer->stop();
            simulatorButton->setText(tr("&Turn On"));
            simulatorButton->setToolTip(tr("Turn On the simulator"));
            simulatorButton->setStatusTip(tr("Turn On the simulator"));
            simulatorButton->setWhatsThis(tr("Turn On the simulator"));
        } else {
            timer->start(1000 / 33);
            simulatorButton->setText(tr("&Turn Off"));
            simulatorButton->setToolTip(tr("Turn Off the simulator"));
            simulatorButton->setStatusTip(tr("Turn Off the simulator"));
            simulatorButton->setWhatsThis(tr("Turn Off the simulator"));
        }
    }
}


/*-----------------------------------------------------------------------------
 *  Private Methods
 *-----------------------------------------------------------------------------*/

void RobotQt::createActions()
{
    actionOpen->setShortcut(QKeySequence::Open);

    connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(actionAboutRobotQt, SIGNAL(triggered()), this, SLOT(openAbout()));
    connect(actionSourceEditor, SIGNAL(triggered()), this, SLOT(openSourceEdit()));
    connect(sourceButton, SIGNAL(clicked()), this, SLOT(openSourceEdit()));
    connect(simulatorButton, SIGNAL(clicked()), this, SLOT(startOrStopSimulation()));
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance())); // for simulation
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

bool RobotQt::loadRobot(const QString &fileName) {
    if (fileName.endsWith(".robot", Qt::CaseInsensitive)) {
        QPluginLoader loader(fileName);
        if (RobotInterface *plugin = qobject_cast<RobotInterface *>(loader.instance())) {
            int r = QMessageBox::warning(this, tr("RobotQt"),
                                         tr("Are you sure do you want to open the robot called \"%1\"?").arg(plugin->getName()),
                                         QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            if (r == QMessageBox::Yes) {

//                QTableWidgetItem *item = new QTableWidgetItem(tr("ADFASDFASDFASD"));

                // FIXME: QTableWidgetItem it's not been displayed in tableWidget
                QTableWidgetItem *item = new StatusItem(plugin);
                if (tableWidget->rowCount() == 0)
                    tableWidget->setRowCount(1);
                tableWidget->setItem(1, 1, item);

                // If a past robot was open, deletes it
                if (currentRobot == NULL)
                    delete currentRobot;
                currentRobot = plugin;
                currentRobot->setPos(200.0, 200.0);
                scene->addItem(currentRobot);
                simulatorButton->setEnabled(true);
                return true;
            }
            delete plugin;
        }
    }
    QMessageBox::warning(this, tr("RobotQt"),
                         tr("Ocurred an Error: it seems that the file %1 is corrupted.").arg(fileName));
    return false;
}
