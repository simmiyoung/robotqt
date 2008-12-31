/*
 * Sensor.h
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

class Sensor {
public:
    Sensor(const QString _name, quint8 _id);
    virtual ~Sensor();

    quint8 getId() const;
    QString getName() const;

private:
    QString name;
    quint8 id;
};

#endif // SENSOR_H
