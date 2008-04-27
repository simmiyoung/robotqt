
//RobotQt - http://robotqt.googlecode.com/

//Packages/Robot/Robot.cpp

//Revision: $Rev$
//Author: $Author$
//Date: $Date$

#include "Robot.h"

Robot::Robot(string Name, USINT Id)
{
	cout << "Robot constructor working..." << endl;
	this->Name = Name;
	this->Id = Id;
	
	this->setWheelSize(100); //1 meter == 100 cm
	cout << "Robot constructor done!" << endl;
}

string Robot::getName()
{
	return this->Name;
}

USINT Robot::getId()
{
	return this->Id;
}

USINT Robot::getWheelSize()
{
	return this->WheelSize;
}

void Robot::setWheelSize(USINT cm)
{
	this->WheelSize = cm;
}

void Robot::setMotor(Motor NewMotor)
{
	this->MotorsVector.push_back(NewMotor);
	cout << "NewMotor added" << endl;
}

Motor Robot::getMotor(USINT Id)
{
	//TODO implementation for the Id search
	return this->MotorsVector[0];
}

void Robot::setSensor(Sensor NewSensor)
{
	this->SensorsVector.push_back(NewSensor);
	cout << "NewSensor added" << endl;
}

Sensor Robot::getSensor(USINT Id)
{
	//TODO implementation for the Id search
	return this->SensorsVector[0];
}

Robot::~Robot()
{
	cout << "Robot Object destructed done!" << endl;
}