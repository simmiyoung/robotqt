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
#include "RobotPosition.h"

Robot::Robot(QString _name, qint8 _id) :
	name(_name), id(_id)
{
	setWheelSize(100); //1 meter == 100 cm
}

Robot::~Robot()
{
	//TODO: Delete all Motor and Sensor
}

QString Robot::getName()
{
        return name;
}

qint8 Robot::getId()
{
        return id;
}

qint8 Robot::getWheelSize()
{
        return wheelSize;
}

void Robot::setWheelSize(qint8 cm)
{
        wheelSize = cm;
}

void Robot::setMotor(Motor *newMotor)
{
        motorList.append(newMotor);
}

Motor *Robot::getMotor(qint8 _id)
{
        //TODO implementation for the Id search
        return motorList[0];
}

void Robot::setSensor(Sensor *newSensor)
{
        sensorList.append(newSensor);
}

Sensor *Robot::getSensor(qint8 _id)
{
        //TODO implementation for the Id search
        return sensorList[0];
}
