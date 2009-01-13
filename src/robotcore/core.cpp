/*
 * core.cpp
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

#include "core.h"

Core::Core(const QString &_name, quint8 _id) :
    name(_name), id(_id)
{

}

Core::~Core()
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
