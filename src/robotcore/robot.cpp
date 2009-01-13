/*
 * robot.cpp
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

#include "robot.h"

#include "motor/motor.h"
#include "sensor/sensor.h"
#include "robotposition.h"

Robot::Robot(const QString &_name, quint8 _id)
    : Core(_name, _id), status(OFF)
{
    //we're not initialization lists because this function can be overwrited
    setWheelSize(100); // 100 cm = 1 m
}

Robot::~Robot()
{
    // deleting motor and sensor lists(STL style) and clearing them
    qDeleteAll(motorList.begin(), motorList.end());
    motorList.clear();

    qDeleteAll(sensorList.begin(), sensorList.end());
    sensorList.clear();

    //turn off the robot after turning off all Sensors and Motors
    if (status != OFF)
        turnOff();
}

void Robot::setWheelSize(quint32 cm)
{
    wheelSize = cm;
}

quint32 Robot::getWheelSize() const
{
    return wheelSize;
}

void Robot::setMotor(Motor *newMotor)
{
    motorList.push_back(newMotor);
}

void Robot::setSensor(Sensor *newSensor)
{
    sensorList.push_back(newSensor);
}

Motor * Robot::getMotor(quint8 _id) const
{
    QList<Motor *>::const_iterator i;
    for(i = motorList.begin(); i != motorList.end(); ++i)
        if (i->getId() == _id)
            return *i;
    return NULL;

//    for (int i = 0; i < motorList.size(); ++i) {
//        if (motorList[i]->getId() == _id) {
//            return motorList[i];
//        }
//    }
//    return NULL;
}

Sensor * Robot::getSensor(quint8 _id) const
{
    QList<Sensor *>::const_iterator i;
    for(i = sensorList.begin(); i != sensorList.end(); ++i)
        if (i->getId() == _id)
            return *i;
    return NULL;

//    for (int i = 0; i < sensorList.size(); ++i) {
//        if (sensorList[i]->getId() == _id) {
//            return sensorList[i];
//        }
//    }
//    return NULL;
}

/*
 * implementing pure virtual function Core::init()
 */
bool Robot::init()
{
    status = ON;
    turnOn();
    return true;
}
