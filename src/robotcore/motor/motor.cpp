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

/*
 * It sets direction(default FORWARD) and sets status to OFF
 */
Motor::Motor(const QString &_name, quint8 _id, Motor::Direction _direction)
    : Core(_name, _id), direction(_direction), status(OFF)
{

}

Motor::~Motor()
{
    if (motorStatus != OFF)
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

//inline Motor::Direction Motor::getDirection() const
//{
//    return direction;
//}
//
//inline void Motor::setDirection(Motor::Direction _direction)
//{
//    direction = _direction;
//}

/*
 * implementing pure virtual function Core::init()
 */
bool Motor::init()
{
    motorStatus = ON;
    turnOn();
    return true;
}
