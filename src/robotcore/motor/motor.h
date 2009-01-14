/*
 * motor.h
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

/*
 * TODO: Debugging using qDebug()
 */

#ifndef MOTOR_H
#define MOTOR_H

#include "../core.h"

#include <QString>

class Motor : public Core {
public:
    enum Direction {FORWARD, BACKWARD};

    Motor(const QString &_name, quint8 _id, Motor::Direction _direction=FORWARD);
    virtual ~Motor();

    quint32 getRpm() const;
    void setRpm(quint32 _rpm);

    // there is a direct access to Motor::Direction by 'direction'
//    inline Motor::Direction getDirection() const;
//    inline void setDirection(Motor::Direction _direction);

    /*
     * It turns on and off the object actions
     *
     * @bool If it worked properly
     */
    bool turnOn();
    bool turnOff();

    /*
     * Abstract virtual functions that the child will inherit and do whatever
     * they want to their functionality when the object will start and stop
     */
    virtual void start() = 0;
    virtual void stop() = 0;

    Motor::Direction direction;

private:
    quint32 rpm;
};

#endif // MOTOR_H
