// 
//  Sensor.cpp
//  RobotQt
//  
//  Created by Felipe Tonello on 2008-06-22.
//  Copyright 2008 Felipe Ferreri Tonello. All rights reserved.
// 
//  http://robotqt.googlecode.com/
// 
//  Revision: $Rev$
//  Author: $Author$
//  Date: $Date$

#include <iostream>

#include "Sensor.h"

using namespace std;

Sensor::~Sensor()
{
	cout << "Super Sensor Object destructed done!" << endl;
}

QString Robot::getName()
{
	return name;
}

ushort Robot::getId()
{
	return id;
}