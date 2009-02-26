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
    void openSourceEdit(bool open = false);

private:
    SourceEditor *sourceEditor;
};

#endif // ROBOTQT_H
