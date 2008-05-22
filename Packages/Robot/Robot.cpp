
//RobotQt - http://robotqt.googlecode.com/

//Packages/Robot/Robot.cpp

//Revision: $Rev$
//Author: $Author$
//Date: $Date$

#include <iostream>

#include "Robot.h"
#include "../Position/Position.h"

using namespace std;

Robot::Robot(string _name, ushort _id) : name( _name ), id( _id )
{
	cout << "Robot constructor working..." << endl;
	setWheelSize(100); //1 meter == 100 cm
	cout << "Robot constructor done!" << endl;
}

Robot::~Robot()
{
	cout << "Robot Object destructed done!" << endl;
}

QString Robot::getName()
{
	return name;
}

ushort Robot::getId()
{
	return id;
}

ushort Robot::getWheelSize()
{
	return wheelSize;
}

void Robot::setWheelSize(ushort cm)
{
	wheelSize = cm;
}

void Robot::setMotor(Motor newMotor)
{
	motorsVector.push_back(newMotor);
	cout << "NewMotor added" << endl;
}

Motor Robot::getMotor(ushort id)
{
	//TODO implementation for the Id search
	return motorsVector[0];
}

void Robot::setSensor(Sensor newSensor)
{
	sensorsVector.push_back(newSensor);
	cout << "NewSensor added" << endl;
}

Sensor Robot::getSensor(ushort id)
{
	//TODO implementation for the Id search
	return sensorsVector[0];
}