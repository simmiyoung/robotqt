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

#ifndef ROBOT_H_
#define ROBOT_H_

#include <QString>
#include <QList>

#include "RobotPosition.h"

class Motor;
class Sensor;

class Robot {
public:
    Robot(QString _name, quint8 _id);
    virtual ~Robot();

    QString getName() const;
    quint8 getId() const;

    quint8 getWheelSize() const;
    void setWheelSize(quint8 cm);

    void set(Motor *newMotor);
    void set(Sensor *newSensor);
    Motor * getMotor(quint8 _id) const;
    Sensor * getSensor(quint8 _id) const;

    // TODO set position functions

private:
    quint8 id;
    quint8 wheelSize;
    QString name;

    QList<Motor *> motorList;
    QList<Sensor *> sensorList;

    RobotPosition actualPosition;
};

#endif /* ROBOT_H_ */
