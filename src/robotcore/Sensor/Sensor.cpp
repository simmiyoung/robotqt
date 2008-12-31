/*
 * Sensor.cpp
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

#include "Sensor.h"

Sensor::Sensor(const QString _name, quint8 _id)
    : name(_name), id(_id)
{

}

Sensor::~Sensor()
{

}

quint8 Sensor::getId() const
{
    return id;
}

QString Sensor::getName() const
{
    return name;
}
