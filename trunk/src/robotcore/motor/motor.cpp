/*
 * motor.cpp
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

#include "motor.h"

Motor::Motor(const QString &_name, quint8 _id, quint32 _rpm,
             Motor::Direction _direction)
    : Core(_name, _id), rpm(_rpm), direction(_direction)
{

}

Motor::~Motor()
{
    turnOff();
}

quint32 Motor::getRpm() const
{
    return rpm;
}

void Motor::setRpm(quint32 _rpm)
{
    rpm = _rpm;
}

Motor::Direction Motor::getDirection() const
{
    return direction;
}

void Motor::setDirection(Motor::Direction _direction)
{
    direction = _direction;
}

/*
 * implementing pure virtual function Core::init()
 */
bool Motor::turnOn()
{
    start(); //starts Motor's child
    status = Core::ON;
    return true;
}

bool Motor::turnOff()
{
    if (status != Core::OFF) {
        stop();
        status = Core::OFF;
        return true;
    } else
        return false;
}
