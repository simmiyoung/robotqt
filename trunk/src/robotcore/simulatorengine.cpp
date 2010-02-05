/*
 * simulatorengine.cpp
 * RobotQt - Robot Simulation
 *
 * Created by Felipe Tonello on 2010-05-02.
 * Copyright 2010 Felipe Ferreri Tonello. All rights reserved.
 * http://robotqt.googlecode.com/
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

#include <cmath>
#include <QGraphicsScene>

#include "robotinterface.h"
#include "simulatorcontrol.h"

#include "simulatorengine.h"

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle) {
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

SimulatorEngine::SimulatorEngine(RobotInterface *_robot)
{
    robot = _robot;
    angle = robot->startAngle;
    speed = 0;
}

void SimulatorEngine::moveForward(qreal value)
{

}

void SimulatorEngine::moveForward(const QTime &time)
{

}

void SimulatorEngine::moveBackward(qreal value)
{

}

void SimulatorEngine::moveBackward(const QTime &time)
{

}

void SimulatorEngine::turn(qreal value)
{

}

void SimulatorEngine::turn(const QTime &time)
{

}

void SimulatorEngine::doStep()// const
{
    QLineF lineToCenter(QPointF(0, 0), robot->mapFromScene(0, 0));
    if (lineToCenter.length() > 150) {
        qreal angleToCenter = ::acos(lineToCenter.dx() / lineToCenter.length());
        if (lineToCenter.dy() < 0)
            angleToCenter = TwoPi - angleToCenter;
        angleToCenter = normalizeAngle((Pi - angleToCenter) + Pi / 2);

        if (angleToCenter < Pi && angleToCenter > Pi / 4) {
            // Rotate left
            angle += (angle < -Pi / 2) ? 0.25 : -0.25;
        } else if (angleToCenter >= Pi && angleToCenter < (Pi + Pi / 2 + Pi / 4)) {
            // Rotate right
            angle += (angle < Pi / 2) ? 0.25 : -0.25;
        }
    } else if (::sin(angle) < 0) {
        angle += 0.25;
    } else if (::sin(angle) > 0) {
        angle -= 0.25;
    }

    // Try not to crash with any other stuff
    QList<QGraphicsItem *> dangerStuff = robot->scene()->items(QPolygonF() <<
                                                               robot->mapToScene(robot->boundingRect()));
    foreach (QGraphicsItem *item, dangerStuff) {
        if (item == robot)
            continue;

        QLineF lineToStuff(QPointF(0, 0), robot->mapFromItem(item, 0, 0));
        qreal angleToStuff = ::acos(lineToStuff.dx() / lineToStuff.length());
        if (lineToStuff.dy() < 0)
            angleToStuff = TwoPi - angleToStuff;
        angleToStuff = normalizeAngle((Pi - angleToStuff) + Pi / 2);

        if (angleToStuff >= 0 && angleToStuff < Pi / 2) {
            // Rotate right
            angle += 0.5;
        } else if (angleToStuff <= TwoPi && angleToStuff > (TwoPi - Pi / 2)) {
            // Rotate left
            angle -= 0.5;
        }
    }

    // Add some random movement
    if (dangerStuff.size() > 1 && (qrand() % 10) == 0) {
        if (qrand() % 1)
            angle += (qrand() % 100) / 500.0;
        else
            angle -= (qrand() % 100) / 500.0;
    }

    speed += (-50 + qrand() % 100) / 100.0;

    qreal dx = ::sin(angle) * 10;

    robot->setRotation(robot->rotation() + dx);
    robot->setPos(robot->mapToParent(0, -(3 + sin(speed) * 3)));

    // request an update to paint the changes
    robot->update(robot->boundingRect());
}

void SimulatorEngine::setParent(SimulatorControl *_control)
{
    control = _control;
}

inline QRectF SimulatorEngine::sceneRect() const
{
    return robot->scene()->sceneRect();
}
