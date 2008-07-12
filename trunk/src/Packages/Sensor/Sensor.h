// 
//  Sensor.cpp
//  RobotQt
//  
//  Created by Felipe Tonello on 2008-06-22.
//  Copyright 2008 Felipe Ferreri Tonello. All rights reserved.
// 
//  http://robotqt.googlecode.com/
// 
//  Revision: $Rev$
//  Author: $Author$
//  Date: $Date$

#ifndef SENSOR_H
#define SENSOR_H

#include <QString>

class Sensor
{
public:
    Sensor(QString _name, ushort _id) : name( _name ), id( _id ) {};
    virtual ~Sensor();

    QString getName();                                                    
    ushort getId();
    ushort getRange();

private:
    QString name;
    ushort id;
    ushort range;
};

#endif /* SENSOR_H */
