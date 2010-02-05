/*
 * scenariointerface.h
 * RobotQt - Robot Simulation
 *
 * Created by Felipe Tonello on 2010-28-01.
 * Copyright 2010 Felipe Ferreri Tonello. All rights reserved.
 * http://robotqt.googlecode.com/
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

#ifndef SCENARIOINTERFACE_H
#define SCENARIOINTERFACE_H

#include <QtPlugin>
#include <QGraphicsItem>
#include "pluginbase.h"

class ScenarioInterface : public QGraphicsItem, public PluginBase {
public:
    /*
     * virtual destructor to silence the compiler, which might
     * otherwise complain about the lack of a virtual destructor
     * in a class that has vitual functions
     */
    virtual ~ScenarioInterface() {}

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

    QRectF scenarioRect;

    /*
     * Size representation of the scenario
     */
    enum sizeType { Centimeter, Meter, Kilometer };
    QSizeF scenarioSize;
};

Q_DECLARE_INTERFACE(ScenarioInterface, "org.robotqt.RobotQt.ScenarioInterface/0.1")

#endif // SCENARIOINTERFACE_H


