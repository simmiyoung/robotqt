/*
 * robotcore.h
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

#ifndef CORE_H
#define CORE_H

#include <QString>
#include "config.h"

/*
 * Base class for all robotcore
 */
class RobotCore {
public:
    RobotCore(const QString &_name);
    virtual ~RobotCore();

    /*
     * Get the object's name
     */
    QString getName() const;

    /*
     * Abstract virtual functions that controls when the object will
     * turnOn() or turnOff()
     */
    virtual bool turnOn() = 0;
    virtual bool turnOff() = 0;

    /*
     * All the possible object states
     * ON and OFF, for now
     */
    enum Status {ON, OFF};

    /*
     * Refers to enum Status
     */
    Status status;

private:
    QString name;
};

#endif // CORE_H
