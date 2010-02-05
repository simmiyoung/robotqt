/*
 * simulatorcontrol.h
 * RobotQt - Robot Simulation
 *
 * Created by Felipe Tonello on 2010-05-02.
 * Copyright 2010 Felipe Ferreri Tonello. All rights reserved.
 * http://robotqt.googlecode.com/
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

#ifndef SIMULATORCONTROL_H
#define SIMULATORCONTROL_H

#include <QObject>
#include <QList>

class SimulatorEngine;

class SimulatorControl : public QObject
{
Q_OBJECT
public:
    explicit SimulatorControl(QObject *parent = 0);
    ~SimulatorControl();

    void append(SimulatorEngine *engine);

//    inline SimulatorEngine * operator <<(SimulatorEngine *engine);

public slots:
    void doStep();

private:
    QList<SimulatorEngine *> engineList;
};

#endif // SIMULATORCONTROL_H
