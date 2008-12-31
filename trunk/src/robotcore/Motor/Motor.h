/*
 * Motor.h
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
    enum Direction {Forward, Backward};

    Motor(const QString _name, quint8 _id, Motor::Direction _direction=Forward);
    virtual ~Motor();

    quint8 getId() const;
    QString getName() const;

    virtual quint16 getRpm() const;
    virtual void setRpm(quint16 _rpm);
    virtual Motor::Direction getDirection() const;
    virtual void setDirection(Motor::Direction _direction);

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    Motor::Direction direction;
private:
    QString name;
    quint8 id;
    quint16 rpm;
};

#endif // MOTOR_H
