/*
 * sensor.cpp
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

#include "sensor.h"

Sensor::Sensor(const QString &_name, quint8 _id)
    : Core(_name, _id)
{

}

Sensor::~Sensor()
{
    turnOff();
}

/*
 * implementing pure virtual function Core::init()
 */
bool Sensor::turnOn()
{
    start();
    status = Core::ON;
    return true;
}

bool Sensor::turnOff()
{
    if (status != Core::OFF) {
        stop();
        status = Core::OFF;
        return true;
    } else
        return false;
}
