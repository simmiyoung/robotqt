/*
 * sensorinterface.h
 * RobotQt - Robot Simulation
 *
 * Created by Felipe Tonello on 2010-21-01.
 * Copyright 2010 Felipe Ferreri Tonello. All rights reserved.
 * http://robotqt.googlecode.com/
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

/*
 * TODO: Debugging using qDebug()
 */

#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include <QString>

class SensorInterface {
public:
    /*
     * virtual destructor to silence the compiler, which might
     * otherwise complain about the lack of a virtual destructor
     * in a class that has vitual functions
     */
    virtual ~SensorInterface() {}

    /*
     * It turns on and off the object actions
     *
     * Returns true if it worked properly, false otherwise
     */
    virtual bool turnOn() = 0;
    virtual bool turnOff() = 0;

    /*
     * All the possible object states
     * ON and OFF, for now
     */
    enum Status {ON, OFF};

    SensorInterface::Status status;
    QString name;
    quint32 range;
};

Q_DECLARE_INTERFACE(SensorInterface, "org.robotqt.RobotQt.SensorInterface/0.1")

#endif // SENSORINTERFACE_H
