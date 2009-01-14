/*
 * config.h
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

#ifndef CONFIG_H
#define CONFIG_H

#include <QtDebug>

class Config {
public:
    Config();
};

void handleRobotQtMessages(QtMsgType type, const char *msg);

#endif // CONFIG_H
