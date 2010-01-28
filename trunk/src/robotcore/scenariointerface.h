/*
 * scenariointerface.h
 * RobotQt - Robot Simulation
 *
 * Created by Felipe Tonello on 2010-28-01.
 * Copyright 2010 Felipe Ferreri Tonello. All rights reserved.
 * http://robotqt.googlecode.com/
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

#ifndef SCENARIOINTERFACE_H
#define SCENARIOINTERFACE_H

#include <QtPlugin>
#include <QGraphicsItem>
#include "pluginbase.h"

class ScenarioInterface : public QGraphicsItem, public PluginBase {
public:
    /*
     * virtual destructor to silence the compiler, which might
     * otherwise complain about the lack of a virtual destructor
     * in a class that has vitual functions
     */
    virtual ~ScenarioInterface() {}

    QRectF scenarioSize;
};

Q_DECLARE_INTERFACE(ScenarioInterface, "org.robotqt.RobotQt.ScenarioInterface/0.1")

#endif // SCENARIOINTERFACE_H


