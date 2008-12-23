/*
 * Motor.h
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

Motor::Motor(const QString _name, uint8 _id, MotorDirection _direction)
    : id(_id), name(_name), Motor::Direction(_direction)
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

void Motor::setRpm(quint16 _rpm)
{
    rpm = _rpm;
}

void setDirection(Motor::MotorDirection _direction)
{
    Motor::Direction = _direction;
}
