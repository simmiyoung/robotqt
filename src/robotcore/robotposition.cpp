/*
 * robotposition.cpp
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

#include "robotposition.h"

RobotPosition::RobotPosition(const RobotPosition &obj)
{
    set(obj.x, obj.y, obj.degree);
}

RobotPosition::RobotPosition(quint32 _x, quint32 _y, quint16 _degree)
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

void RobotPosition::set(quint32 _x, quint32 _y, quint16 _degree)
{
    setX(_x);
    setY(_y);
    setDegree(_degree);
}

void RobotPosition::setX(quint32 _x)
{
    x = _x;
}

void RobotPosition::setY(quint32 _y)
{
    y = _y;
}

/* Degree is in celcius */
void RobotPosition::setDegree(quint16 _degree)
{
    degree = _degree % 360;
}

quint32 RobotPosition::getX() const
{
    return x;
}

quint32 RobotPosition::getY() const
{
    return y;
}

quint16 RobotPosition::getDegree() const
{
    return degree;
}

RobotPosition & RobotPosition::operator+(const RobotPosition &obj)
{
    RobotPosition *n_pos = new RobotPosition;
    n_pos->set((x + obj.x), (y + obj.y), (degree + obj.degree));
    return *n_pos;
}

RobotPosition & RobotPosition::operator-(const RobotPosition &obj)
{
    RobotPosition *n_pos = new RobotPosition;
    n_pos->set((x - obj.x), (y - obj.y), (degree - obj.degree));
    return *n_pos;
}

RobotPosition & RobotPosition::operator=(const RobotPosition &obj)
{
    set(obj.x, obj.y, obj.degree);
    return *this;
}
