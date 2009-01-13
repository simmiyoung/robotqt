/*
 * robot.cpp
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

class Motor;
class Sensor;
class RobotPosition;

class Robot : public Core {
public:
    //not using, for now
//    enum Periferic {Motor, Sensor};

    Robot(const QString &_name, quint8 _id);
    virtual ~Robot();

    virtual void setWheelSize(quint8 cm);
    quint8 getWheelSize() const;

    void setMotor(Motor *newMotor);
    void setSensor(Sensor *newSensor);
    Motor * getMotor(quint8 _id) const;
    Sensor * getSensor(quint8 _id) const;

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

protected:
    enum Status {ON, OFF}; //on and off, for now

    Robot::Status status;

private:
    QString name;
    quint8 id;
    quint32 wheelSize; // in centmeters

    QList<Motor *> motorList;
    QList<Sensor *> sensorList;

    RobotPosition currentPosition;
};

#endif /* ROBOT_H */
