/*
 * RobotPosition.cpp
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

#include "RobotPosition.h"

RobotPosition::RobotPosition() : x(0), y(0), degree(0)
{

}

RobotPosition::RobotPosition(qint16 _x, qint16 _y, qint8 _degree) :
	x(_x), y(_y), degree(_degree)
	{

}

RobotPosition::RobotPosition(const RobotPosition &obj)
{
	this->x = obj.x;
	this->y = obj.y;
	this->degree = obj.degree;
}

RobotPosition::~RobotPosition()
{

}

void RobotPosition::set(const RobotPosition &obj)
{
    this->x = obj.x;
    this->y = obj.y;
    this->degree = obj.degree;
}

void RobotPosition::set(qint16 x, qint16 y, qint8 degree)
{
	this->x = x;
	this->y = y;
	this->degree = degree;
}

qint16 RobotPosition::getX() const
{
	return x;
}

qint16 RobotPosition::getY() const
{
	return y;
}

qint8 RobotPosition::getDegree() const
{
	return degree;
}

RobotPosition & RobotPosition::operator+(const RobotPosition &obj)
{
	Position *n_pos = new RobotPosition;
	n_pos->x = x - obj.x;
	n_pos->y = y - obj.y;
	n_pos->degree = degree - obj.degree;

	return *n_pos;
}

RobotPosition & RobotPosition::operator-(const RobotPosition &obj)
{
	Position *n_pos = new RobotPosition;
	n_pos->x = x - obj.x;
	n_pos->y = y - obj.y;
	n_pos->degree = degree - obj.degree;

	return *n_pos;
}

RobotPosition & RobotPosition::operator=(const RobotPosition &obj)
{
	this->x = obj.x;
	this->y = obj.y;
	this->degree = obj.degree;

	return *this;
}
