/*
 * robotcore.cpp
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

#include "robotcore.h"

RobotCore::RobotCore(const QString &_name) :
    status(OFF), name(_name)
{
    qDebug() << "RobotCore() name(" << _name << "), status(" << OFF << ")";
}

RobotCore::~RobotCore()
{
    qDebug() << "~RobotCore()";
}

QString RobotCore::getName() const
{
    qDebug() << "QString RobotCore::getName() const returning (" << name << ")";
    return name;
}
