/*
 * sensor.h
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

#ifndef SENSOR_H
#define SENSOR_H

#include <QString>

class Sensor : public Core {
public:
    Sensor(const QString &_name, quint8 _id);
    virtual ~Sensor();

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

protected:
    enum Status {ON, OFF}; //on and off, for now

    Sensor::Status status;

private:
    QString name;
    quint8 id;
};

#endif // SENSOR_H
