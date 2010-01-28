/*
 * pluginbase.cpp
 * RobotQt - Robot Simulation
 *
 * Created by Felipe Tonello on 2010-21-01.
 * Copyright 2010 Felipe Ferreri Tonello. All rights reserved.
 * http://robotqt.googlecode.com/
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

#include "pluginbase.h"

void PluginBase::setName(const QString &_name)
{
    name = _name;
}

QString PluginBase::getName() const
{
    return name;
}

void PluginBase::setType(PluginBase::Type _type)
{
    type = _type;
}

PluginBase::Type PluginBase::getType() const
{
    return type;
}
