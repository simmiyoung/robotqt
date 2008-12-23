/*
 * Motor.cpp
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

#ifndef MOTOR_H
#define MOTOR_H

#include <QString>

class Motor {
public:
    enum MotorDirection {Forward, Backward};

    Motor(const QString _name, quint8 _id);
    virtual ~Motor();

    quint8 getId() const;
    QString getName() const;

    virtual void setRpm(quint16 _rpm);
    virtual void setDirection(Motor::MotorDirection _direction);

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    static Motor::MotorDirection Direction;
private:
    QString name;
    quint8 id;
    quint16 rpm;
}

#endif // MOTOR_H
