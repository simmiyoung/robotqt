/*
 * robotinterface.cpp
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

#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include <QtPlugin>
#include <QGraphicsItem>

class QString;
class QColor;

class RobotInterface : public QGraphicsItem {
public:
    /*
     * virtual destructor to silence the compiler, which might
     * otherwise complain about the lack of a virtual destructor
     * in a class that has vitual functions
     */
    virtual ~RobotInterface() {}

    /*
     * It turns on and off the object actions
     *
     * Returns true if it worked properly, false otherwise
     */
//    virtual bool turnOn() = 0;
//    virtual bool turnOff() = 0;
//
//    /*
//     * turns the robot in a -32768 to 32767 range of Celsius degrees.
//     */
//    virtual void turn(qint16 degree) = 0;
//
//    /*
//     * turns the robot in a -32768 to 32767 range of Celsius degrees.
//     */
//    virtual void run(qint16 degree) = 0;

    /*
     * All the possible object states
     * ON and OFF, for now
     */
    enum Status {ON, OFF};

    RobotInterface::Status status;
    QString name;
    qreal angle;
    qreal speed;
    QColor color;
};

Q_DECLARE_INTERFACE(RobotInterface, "org.robotqt.RobotQt.RobotInterface/0.1")

#endif /* ROBOTINTERFACE_H */
