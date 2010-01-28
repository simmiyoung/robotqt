/*
 * robotqt.h
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


//TODO: method loadRobot()
//      method save()
//      read settings at readSettings()

#ifndef ROBOTQT_H
#define ROBOTQT_H

#include "ui_robotqt.h"

#include <QList>
#include <QStateMachine>

class QWidget;
class QGraphicsScene;
class QStateMachine;
class SourceEditor;
class RobotInterface;
class SensorInterface;
class ScenarioInterface;

class RobotQt : public QMainWindow, private Ui::RobotQt {
    Q_OBJECT

public:
    RobotQt(QWidget *parent = 0);
    ~RobotQt();

    /*
     * Read settings that was previously saved
     */
    void readSettings();

private slots:
    void openSourceEdit();
    void openFile(); // Opens a new robot for simulation
    void openAbout();
    void startOrStopSimulation();

private:
    /*
     * Modify and create actions, and create connections
     */
    void createActions();

    /*
     * Return true if the robot plugin is ok
     */
    bool loadRobot(const QString &fileName);

    /*
     * Return true if the sensor plugin is ok
     */
    bool loadSensor(const QString &fileName);

    /*
     * Return true if the map plugin is ok
     */
    bool loadScenario(const QString &fileName);

    /*
     * Check if any robot was already loaded
     */
    bool inline isRobotLoaded() const;

    /*
     * Check if any scenario was already loaded
     */
    bool inline isScenarioLoaded() const;

    /*
     * Plugin variables
     */
    RobotInterface *currentRobot;
    QList<SensorInterface *> sensorsList;
    ScenarioInterface *currentScenario;

    SourceEditor *sourceEditor;
    QGraphicsScene scene;

    /*
     * State Machine for the simulator
     */
    QStateMachine simulatorStateMachine;
};

#endif // ROBOTQT_H
