/*
 * robotqt.cpp
 * RobotQt - Robot Simulation
 *
 * Created by Felipe Tonello on 2008-12-10.
 * Copyright 2008-2010 Felipe Ferreri Tonello. All rights reserved.
 * http://robotqt.googlecode.com/
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

#include <QtGui/QMessageBox>
#include <QtGui/QFileDialog>
#include <QtGui/QGraphicsScene>
#include <QSettings>
#include <QPluginLoader>

#include "robotqt.h"
#include "config.h" // for debugging
#include "robotcore/pluginbase.h"
#include "robotcore/robotinterface.h"
#include "robotcore/sensorinterface.h"
#include "robotcore/scenariointerface.h"
#include "robotcore/simulatorengine.h"

// GUI's
#include "sourceeditor.h"
#include "statusitem.h"

static const int ThreadTime = 1000 / 33;

RobotQt::RobotQt(QWidget *parent) :
    QMainWindow(parent)
{
    qDebug() << "Setting up RobotQt Window and Widgets";
    setupUi(this);

    // setting NULL to easy manipulate various plugins opening
    currentRobot = NULL;
    currentScenario = NULL;

    sourceEditor = new SourceEditor;

    splitter->setStretchFactor(1,1);

    tableWidget->setItemPrototype(new StatusItem);

    qDebug() << "Setting up Simulator Stat Machine";

    // State Machine for the simulator
    QState *simulatorIsOn = new QState();
    simulatorIsOn->assignProperty(simulatorOnOffButton, "text", "&Turn Off");
    simulatorIsOn->assignProperty(simulatorOnOffButton, "toolTip", "Turn Off the simulator");
    simulatorIsOn->assignProperty(simulatorOnOffButton, "statusTip", "Turn Off the simulator");
    simulatorIsOn->assignProperty(simulatorOnOffButton, "whatsThis", "Turn Off the simulator");
    simulatorIsOn->assignProperty(sensorAddButton, "enabled", false);
    simulatorIsOn->assignProperty(configureButton, "enabled", false);
    simulatorIsOn->setObjectName("simulatorIsOn");

    QState *simulatorIsOff = new QState();
    simulatorIsOff->assignProperty(simulatorOnOffButton, "text", "&Turn On");
    simulatorIsOff->assignProperty(simulatorOnOffButton, "toolTip", "Turn On the simulator");
    simulatorIsOff->assignProperty(simulatorOnOffButton, "statusTip", "Turn On the simulator");
    simulatorIsOff->assignProperty(simulatorOnOffButton, "whatsThis", "Turn On the simulator");
    simulatorIsOff->assignProperty(sensorAddButton, "enabled", true);
    simulatorIsOff->assignProperty(configureButton, "enabled", true);
    simulatorIsOff->setObjectName("simulatorIsOff");

    simulatorIsOn->addTransition(simulatorOnOffButton, SIGNAL(clicked()), simulatorIsOff);
    simulatorIsOff->addTransition(simulatorOnOffButton, SIGNAL(clicked()), simulatorIsOn);

    simulatorStateMachine.addState(simulatorIsOn);
    simulatorStateMachine.addState(simulatorIsOff);
    simulatorStateMachine.setInitialState(simulatorIsOff);
    // End of State Machine for the simulator

    qDebug() << "Setting up 2D graphics engine";

    // 2D graphics propeties
    scene.setSceneRect(simulatorGraphicsView->geometry());
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    simulatorGraphicsView->setScene(&scene);
    simulatorGraphicsView->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    simulatorGraphicsView->setCacheMode(QGraphicsView::CacheBackground);
    simulatorGraphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    simulatorGraphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    // End of 2D graphics propeties

    createActions();
    readSettings();
}

RobotQt::~RobotQt()
{
    // we know that it will not have any effect,
    // but still a good practice
    if (isRobotLoaded()) {
        delete currentRobot;
        currentRobot = NULL;
    }
    if (isScenarioLoaded()) {
        delete currentScenario;
        currentScenario = NULL;
    }

    // FIXME: still having issues with memory management
    qDeleteAll(sensorsList.begin(), sensorsList.end());
    sensorsList.clear();
}

/*-----------------------------------------------------------------------------
 *  Private slots
 *-----------------------------------------------------------------------------*/

void RobotQt::openSourceEdit()
{
    sourceEditor->setVisible(!sourceEditor->isVisible());
}

// FIXME: make it possible to open a sensor in this function
void RobotQt::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open a RobotQt plugin file"), ".",
                                                    tr("RobotQt (*.robot *.sensor *.scenario)"));
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, tr("RobotQt"),
                             tr("Ocurred an Error: you didn't selected any file.").arg(fileName));
        return;
    } else if (fileName.endsWith(".robot", Qt::CaseInsensitive)) {
        loadRobot(fileName);
    } else if (fileName.endsWith(".scenario", Qt::CaseInsensitive)) {
        loadScenario(fileName);
    } else if (fileName.endsWith(".sensor", Qt::CaseInsensitive)) {
        loadSensor(fileName);
    }
}

void RobotQt::openAbout()
{
    QMessageBox::about(this, tr("About RobotQt"),
        tr("<h2>RobotQt %1</h2>"
        "<p>Copyright &copy; 2008-2010 Felipe Ferreri Tonello</p>"
        "<p>RobotQt is a robot simulator for academic proposes.</p>").arg(String_Version));
}

void RobotQt::startOrStopSimulation()
{
    // do not change the status if there is no loaded Robot
    if (isRobotLoaded() && isScenarioLoaded()) {
        if (timer.isActive()) {
            timer.stop();
        } else {
            timer.start(ThreadTime);
        }
    } else {
        QMessageBox::warning(this, tr("RobotQt"),
                             tr("You need to load a robot <strong>and</strong> "
                                "a scenario to run the simulation"));
    }
}

/*-----------------------------------------------------------------------------
 *  Private Methods
 *-----------------------------------------------------------------------------*/

void RobotQt::createActions()
{
    actionPreferences->setShortcut(QKeySequence::Preferences);

    connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(actionAboutRobotQt, SIGNAL(triggered()), this, SLOT(openAbout()));
    connect(actionSourceEditor, SIGNAL(triggered()), this, SLOT(openSourceEdit()));
    connect(sourceButton, SIGNAL(clicked()), this, SLOT(openSourceEdit()));
    connect(simulatorOnOffButton, SIGNAL(clicked()), this, SLOT(startOrStopSimulation()));
    connect(sensorAddButton, SIGNAL(clicked()), this, SLOT(openFile()));
    connect(&timer, SIGNAL(timeout()), &simulatorControl, SLOT(doStep())); // for simulation
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
    QPluginLoader loader(fileName);
    if (RobotInterface *plugin = qobject_cast<RobotInterface *>(loader.instance())) {
        // If a past robot was open, deletes it
        if (currentRobot != NULL) {
            // StatusItem destructor deletes currentRobot
            tableWidget->removeCellWidget(1, 0);
            delete currentRobot;
            currentRobot = NULL;
        }
        // if this statement fails, it means that probably there is no map loaded
        if (tableWidget->rowCount() <= 1)
            tableWidget->setRowCount(2);


        // robot will be always displayed as the second row
        tableWidget->setItem(1, 0, new StatusItem(plugin));

        plugin->setPos(plugin->startingPoint);
        // TODO: only loads a robot if a scenario is already loaded
        plugin->setParentItem(currentScenario);
        scene.addItem(plugin);

        currentRobot = plugin;

        // now it's possible to run the simulator
        simulatorOnOffButton->setEnabled(true);
        simulatorStateMachine.start();
        simulatorControl.append(new SimulatorEngine(currentRobot));

        return true;
    } else {
        QMessageBox::warning(this, tr("RobotQt"),
                             tr("Ocurred an Error: it seems that the file %1 is corrupted.").arg(fileName));
        return false;
    }
}

bool RobotQt::loadSensor(const QString &fileName) {
    QPluginLoader loader(fileName);
    if (SensorInterface *plugin = qobject_cast<SensorInterface *>(loader.instance())) {
        tableWidget->setRowCount(tableWidget->rowCount() + 1);

        tableWidget->setItem(tableWidget->rowCount() - 1, 0, new StatusItem(plugin));

        sensorsList.append(plugin);
        plugin->setParentItem(currentRobot);
        scene.addItem(plugin);

        return true;
    } else {
        QMessageBox::warning(this, tr("RobotQt"),
                             tr("Ocurred an Error: it seems that the file %1 is corrupted.").arg(fileName));
        return false;
    }
}

bool RobotQt::loadScenario(const QString &fileName) {
    QPluginLoader loader(fileName);
    if (ScenarioInterface *plugin = qobject_cast<ScenarioInterface *>(loader.instance())) {
        if (isScenarioLoaded()) {
            // StatusItem destructor deletes currentScenario
            tableWidget->takeItem(0, 0);
            delete currentScenario;
            currentScenario = NULL;
        }

        if (tableWidget->rowCount() == 0)
            tableWidget->setRowCount(1); // just remembering that columnCount() == 1 from the Designer

        // scenario will be always displayed as the first row
        tableWidget->setItem(0, 0, new StatusItem(plugin));

        // centralize it
        plugin->setPos(0.0, 0.0);
        scene.setSceneRect(plugin->scenarioRect);
        scene.addItem(plugin);

        currentScenario = plugin;

        return true;
    } else {
        QMessageBox::warning(this, tr("RobotQt"),
                             tr("Ocurred an Error: it seems that the file %1 is corrupted.").arg(fileName));
        return false;
    }
}

// TODO loadScene!!!

bool inline RobotQt::isRobotLoaded() const
{
    return (currentRobot != NULL);
}

bool inline RobotQt::isScenarioLoaded() const
{
    return (currentScenario != NULL);
}
