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

RobotPosition::RobotPosition()
{
    RobotPosition(0, 0, 0);
}

RobotPosition::RobotPosition(const RobotPosition &obj)
{
    RobotPosition(obj.x, obj.y, obj.degree);
}

RobotPosition::RobotPosition(quint16 _x, quint16 _y, qint8 _degree)
{
    set(_x, _y, _degree);
}

RobotPosition::~RobotPosition()
{

}

void RobotPosition::set(const RobotPosition &obj)
{
    set(obj.x, obj.y, obj.degree);
}

void RobotPosition::set(quint16 x, quint16 y, qint8 degree)
{
    setX(x);
    setY(y);
    setDegree(degree);
}

void RobotPosition::setX(quint16 x)
{
    this->x = x;
}

void RobotPosition::setY(quint16 y)
{
    this->y = y;
}

/* Degree is in celcius */
void RobotPosition::setDegree(qint8 degree)
{
    this->degree = degree % 360;
}

quint16 RobotPosition::getX() const
{
    return x;
}

quint16 RobotPosition::getY() const
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
    n_pos->set((x + obj.x), (y + obj.y), (degree + obj.degree));
    return *n_pos;
}

RobotPosition & RobotPosition::operator-(const RobotPosition &obj)
{
    Position *n_pos = new RobotPosition;
    n_pos->set((x - obj.x), (y - obj.y), (degree - obj.degree));
    return *n_pos;
}

RobotPosition & RobotPosition::operator=(const RobotPosition &obj)
{
    set(obj.x, obj.y, obj.degree);
    return *this;
}
