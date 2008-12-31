/*
 * Motor.cpp
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

#include "Motor.h"

Motor::Motor(const QString _name, quint8 _id, Motor::Direction _direction) :
    id(_id), name(_name), direction(_direction)
{

}

Motor::~Motor()
{

}

quint8 Motor::getId() const
{
    return id;
}

QString Motor::getName() const
{
    return name;
}

quint16 Motor::getRpm() const
{
    return rpm;
}

void Motor::setRpm(quint16 _rpm)
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
