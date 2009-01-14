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
    status(OFF), name(_name), id(_id)
{
    qDebug() << "Core() name(" << _name << "), id(" << _id << "), status("
        << OFF << ")";
}

Core::~Core()
{
    qDebug() << "~Core()";
}

quint8 Core::getId() const
{
    qDebug() << "quint8 Core::getId() const returning (" << id << ")";
    return id;
}

QString Core::getName() const
{
    qDebug() << "QString Core::getName() const returning (" << name << ")";
    return name;
}
