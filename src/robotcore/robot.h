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

/*
 * TODO: Debugging using qDebug()
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "core.h"

#include <QString>
#include <QList>

class Motor;
class Sensor;
class RobotPosition;

class Robot : public Core {
public:
    //not using, for now
//    enum Periferic {Motor, Sensor};

    /*
     * Creates a new Robot
     */
    Robot(const QString &_name, quint8 _id);
    virtual ~Robot();

    /*
     * It Appends Motor's and Sensor's to their respective lists
     */
    void setMotor(Motor *newMotor);
    void setSensor(Sensor *newSensor);

    /*
     * It returns a pointer to the respective object
     */
    Motor * getMotor(quint8 _id) const;
    Sensor * getSensor(quint8 _id) const;

    /*
     * It turns on and off the object actions
     *
     * Returns true if it worked properly, false otherwise
     */
    bool turnOn();
    bool turnOff();

    /*
     * Abstract virtual functions that the child will inherit and do whatever
     * they want to their functionality when the object will start and stop
     */
    virtual void start() = 0;
    virtual void stop() = 0;

private:
    /*
     * Lists that contains pointers to object that belongs to the Robot
     */
    QList<Motor *> motorList;
    QList<Sensor *> sensorList;

//    RobotPosition currentPosition;
};

#endif /* ROBOT_H */
