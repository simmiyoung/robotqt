/*
 * simulatorengine.h
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

#ifndef SIMULATORENGINE_H
#define SIMULATORENGINE_H

#include <QMultiMap>

class RobotInterface;
class SimulatorControl;
class QTime;
class QRectF;

class SimulatorEngine
{
public:
    SimulatorEngine(RobotInterface *_robot);

    // TODO: implement methods
    // Actions
    void moveForward(qreal value);
    void moveForward(const QTime &time);
    void moveBackward(qreal value);
    void moveBackward(const QTime &time);
    void turn(qreal value);
    void turn(const QTime &time);

    // do the animation
    void doStep();// const;

    void setParent(SimulatorControl *_control);

private:
    inline QRectF sceneRect() const;

    RobotInterface *robot;

    enum Action { MoveForward, MoveBackward, Turn };

    /*
     * Struct with actions information.
     * The 'value' need to be set as the number of the action.
     * Eg.: if the action is MoveForward the value needs to be in pixels.
     *   if the action is Turn the value needs to be in degrees.
     */
    struct DoAction
    {
        DoAction(SimulatorEngine::Action _action, qreal _value)
        {
            action = _action;
            value = _value;
        }

        SimulatorEngine::Action action;
        qreal value;
    };

    QList<struct DoAction> listOfActions;

    SimulatorControl *control;

    qreal angle;
    qreal speed;
};

#endif // SIMULATORENGINE_H
