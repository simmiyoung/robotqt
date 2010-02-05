/*
 * simulatorcontrol.cpp
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

#include "simulatorengine.h"
#include "simulatorcontrol.h"

SimulatorControl::SimulatorControl(QObject *parent) :
    QObject(parent)
{
}

SimulatorControl::~SimulatorControl()
{
    qDeleteAll(engineList.begin(), engineList.end());
    engineList.clear();
}

void SimulatorControl::append(SimulatorEngine *engine)
{
    engine->setParent(this);
    engineList.append(engine);
}

//inline SimulatorControl * SimulatorControl::operator<<(SimulatorEngine *engine)
//{
//    append(engine);
//    return this;
//}

void SimulatorControl::doStep()
{
    // const_iterator for fast iterating
    QList<SimulatorEngine *>::const_iterator i;
    for (i = engineList.constBegin(); i != engineList.constEnd(); ++i)
        (*i)->doStep();
}
