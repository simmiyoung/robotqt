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
#include "pluginbase.h"

class RobotInterface : public QGraphicsItem, public PluginBase {
public:
    /*
     * virtual destructor to silence the compiler, which might
     * otherwise complain about the lack of a virtual destructor
     * in a class that has vitual functions
     */
    virtual ~RobotInterface() {}

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
     * Current robot angle. Refering to the scene.
     */
    qreal angle;
    /*
     * Current robot speed. It basecly "walk" more pixels when it's faster.
     */
    qreal speed;
    /*
     * The point that the robot will start in the current map.
     */
    QPointF startingPoint;
};

Q_DECLARE_INTERFACE(RobotInterface, "org.robotqt.RobotQt.RobotInterface/0.1")

#endif /* ROBOTINTERFACE_H */
