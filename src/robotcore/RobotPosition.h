/*
 * RobotPosition.h
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

#ifndef ROBOTPOSITION_H
#define ROBOTPOSITION_H

#include <QtGlobal>

class RobotPosition {
public:
    RobotPosition(const RobotPosition &obj);
    RobotPosition(quint16 _x=0, quint16 _y=0, qint8 _degree=0);
    virtual ~RobotPosition();

    void set(const RobotPosition &obj);
    void set(quint16 _x, quint16 _y, qint8 _degree);
    void setX(quint16 _x);
    void setY(quint16 _y);
    void setDegree(qint8 _degree);
    quint16 getX() const;
    quint16 getY() const;
    qint8 getDegree() const;

    RobotPosition & operator+(const RobotPosition &obj);
    RobotPosition & operator-(const RobotPosition &obj);
    RobotPosition & operator=(const RobotPosition &obj);

private:
    quint16 x;
    quint16 y;
    qint8 degree;
};

#endif /* ROBOTPOSITION_H */
