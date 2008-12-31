/*
 * Robot.cpp
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

#ifndef ROBOT_H
#define ROBOT_H

#include <QString>
#include <QList>

#include "Motor/Motor.h"
#include "Sensor/Sensor.h"
#include "RobotPosition.h"


class Robot {
public:
    Robot(const QString _name, quint8 _id);
    virtual ~Robot();

    QString getName() const;
    quint8 getId() const;

    virtual void setWheelSize(quint8 cm);
    quint8 getWheelSize() const;

    virtual void set(Motor *newMotor);
    virtual void set(Sensor *newSensor);
    Motor * getMotor(quint8 _id) const;
    Sensor * getSensor(quint8 _id) const;

    // TODO set position functions

private:
    QString name;
    quint8 id;
    quint8 wheelSize;

    QList<Motor *> motorList;
    QList<Sensor *> sensorList;

    RobotPosition currentPosition;
};

#endif /* ROBOT_H */
