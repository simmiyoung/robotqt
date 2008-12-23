/*
 * Sensor.h
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

Sensor::Sensor(const QString _name, uint8 _id)
    : id(_id), name(_name)
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
