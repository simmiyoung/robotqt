/*
 * core.cpp
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

/*
 * Base class for all robotcore
 */
class Core
{
public:
    Core(const QString &_name, quint8 _id);
    virtual ~Core();

    quint8 getId() const;
    QString getName() const;

    virtual bool init() = 0;
    virtual bool stop() = 0;

private:
    QString name;
    quint8 id;
};

#endif // CORE_H
