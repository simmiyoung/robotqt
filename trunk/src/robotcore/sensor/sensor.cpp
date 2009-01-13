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
    : Core(_name, _id), status(OFF)
{

}

Sensor::~Sensor()
{
    stop();
}

/*
 * implementing pure virtual function Core::init()
 */
bool Sensor::init()
{
    status = ON;
    turnOn();
    return true;
}

bool Sensor::stop()
{
    //turn off the robot after turning off all Sensors and Motors
    if (status != OFF)
        turnOff();
    else
        return false;
    return true;
}
