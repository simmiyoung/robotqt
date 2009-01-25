/*
 * sensor.cpp
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

#include "sensor.h"

Sensor::Sensor(const QString &_name, quint8 _id, quint32 _range, quint8 _accuracy,
           quint32 _frequency, Sensor::FrequencyType _freqType)
    : Core(_name, _id), range(_range), frequency(_frequency), accuracy(_accuracy),
    freqType(_freqType)
{

}

Sensor::~Sensor()
{
    turnOff();
}

quint32 getRange() const
{
    return range;
}

void setRange(quint32 _range)
{
    range = _range;
}

quint32 getFrequency() const
{
    return frequency;
}

void setFrequency(quint32 _frequency)
{
    frequency = _frequency;
}

quint8 gettAccuracy() const
{
    return accuracy;
}

void setAccuracy(quint8 _accuracy)
{
    accuracy = _accuracy;
}

Sensor::FrequencyType getFreqType() const
{
    return freqType;
}

void setFreqType(Sensor::FrequencyType _freqType)
{
    freqType = _freqType;
}

/*
 * implementing pure virtual function Core::init()
 */
bool Sensor::turnOn()
{
    start();
    status = Core::ON;
    return true;
}

bool Sensor::turnOff()
{
    if (status != Core::OFF) {
        stop();
        status = Core::OFF;
        return true;
    } else
        return false;
}