/*
 * Robot.cpp
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

#include "Robot.h"


Robot::Robot(QString _name, quint8 _id) :
    name(_name), id(_id)
{
    setWheelSize(100); // 100 cm = 1 m
}

Robot::~Robot()
{
    //TODO: Delete all Motor and Sensor
}

QString Robot::getName() const
{
    return name;
}

quint8 Robot::getId() const
{
    return id;
}

quint8 Robot::getWheelSize() const
{
    return wheelSize;
}

void Robot::setWheelSize(quint8 cm)
{
    wheelSize = cm;
}

void Robot::set(Motor *newMotor)
{
    motorList.append(newMotor);
}

void Robot::set(Sensor *newSensor)
{
    sensorList.append(newSensor);
}

Motor * Robot::getMotor(quint8 _id) const
{
    for (int i = 0; i < motorList.size(); i++) {
        if (motorList[i].getId() == _id) {
            return motorList[i];
        }
    }
    return NULL;
}

Sensor * Robot::getSensor(quint8 _id) const
{
    for (int i = 0; i < sensorList.size(); i++) {
        if (sensorList[i].getId() == _id) {
            return sensorList[i];
        }
    }
    return NULL;
}
