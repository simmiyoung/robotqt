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

#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include <QtPlugin>
#include <QGraphicsItem>
#include "pluginbase.h"

class SensorInterface : public QGraphicsItem, public PluginBase {
public:
    /*
     * virtual destructor to silence the compiler, which might
     * otherwise complain about the lack of a virtual destructor
     * in a class that has vitual functions
     */
    virtual ~SensorInterface() {}


    /*
     * This pure virtual function defines the outer bounds of the
     * item as a rectangle; all painting must be restricted to inside
     * an item's bounding rect. QGraphicsView uses this to determine
     * whether the item requires redrawing.
     */
    virtual QRectF boundingRect() const = 0;

    /*
     * Returns the shape of this item as a QPainterPath in local coordinates.
     * The shape is used for many things, including collision detection,
     * hit tests, and for the QGraphicsScene::items() functions.
     */
    virtual QPainterPath shape() const = 0;

    /*
     * This pure virtual function, which is usually called by QGraphicsView,
     * paints the contents of an item in local coordinates.
     */
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) = 0;

    /*
     * It turns on and off the object actions
     *
     * Returns true if it worked properly, false otherwise
     */
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    /*
     * All the possible object states
     * ON and OFF, for now
     */
    enum Status {ON, OFF};

    SensorInterface::Status status;
};

Q_DECLARE_INTERFACE(SensorInterface, "org.robotqt.RobotQt.SensorInterface/0.1")

#endif // SENSORINTERFACE_H
