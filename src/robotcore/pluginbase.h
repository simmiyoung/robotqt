/*
 * pluginbase.h
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

#ifndef PLUGINBASE_H
#define PLUGINBASE_H

#include <QString>

/*
 * The base of all plugins.
 * There is just common characteristics like name and type.
 */
class PluginBase
{
public:
    enum Type { Robot, Sensor, Scenario };

    virtual ~PluginBase() {}

    void setName(const QString &_name);
    QString getName() const;

    void setType(PluginBase::Type _type);
    PluginBase::Type getType() const;

private:
    QString name;
    PluginBase::Type type;
};

// struct to set a linked list of properties to animate
template<class PropertyClass>
struct AnimationProperties
{
    AnimationProperties(const QString &_property, const PropertyClass &_value, quint32 _duration = 1000)
    {
        property = _property;
        duration = _duration;
        value = _value;
        next = NULL;
    }

    QString             property;
    quint32             duration; // it only uses if next != NULL
    PropertyClass       value;
    AnimationProperties *next;
};

#endif // PLUGINBASE_H
