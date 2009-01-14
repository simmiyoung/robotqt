/*
 * robotposition.h
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
 *       Operation overloading
 */

#ifndef ROBOTPOSITION_H
#define ROBOTPOSITION_H

#include <QtGlobal>

class RobotPosition {
public:
    RobotPosition(const RobotPosition &obj);
    RobotPosition(quint32 _x=0, quint32 _y=0, quint16 _degree=0);
    ~RobotPosition();

    void set(const RobotPosition &obj);
    void set(quint32 _x, quint32 _y, quint16 _degree);
    void setX(quint32 _x);
    void setY(quint32 _y);
    void setDegree(quint16 _degree);
    quint32 getX() const;
    quint32 getY() const;
    quint16 getDegree() const;

    RobotPosition & operator+(const RobotPosition &obj);
    RobotPosition & operator-(const RobotPosition &obj);
    RobotPosition & operator=(const RobotPosition &obj);
//    RobotPosition & operator==(const RobotPosition &obj);

private:
    quint32 x;
    quint32 y;
    quint16 degree;
};

#endif /* ROBOTPOSITION_H */
