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

class QWidget;
class SourceEditor;

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
    /*
     * Opens the source editor widget
     */
    void openSourceEdit();
    /*
     * Open a new robot for simulation
     */
    void newFile();
    /*
     * Open about page
     */
    void openAbout();

private:
    /*
     * Modify and create actions, and create connections
     */
    void createActions();
    /*
     * Check if it's ok to continue
     */
    bool okToContinue();
    /*
     * return if current robot was modified
     * Ex.: Added new sensor
     */
    bool isRobotModified() const;

    SourceEditor *sourceEditor;
};

#endif // ROBOTQT_H
