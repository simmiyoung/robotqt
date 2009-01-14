/*
 * config.cpp
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

#include "config.h"

Config::Config()
{
}

/*
 * TODO: write in log files instead stderr as above
 */
void handleRobotQtMessages(QtMsgType type, const char *msg)
{
    switch (type) {
        case QtDebugMsg:
//            fprintf(stderr, "Debug: %s\n", msg);
        break;
        case QtWarningMsg:
//            fprintf(stderr, "Warning: %s\n", msg);
        break;
        case QtCriticalMsg:
//            fprintf(stderr, "Critical: %s\n", msg);
        break;
        case QtFatalMsg:
//            fprintf(stderr, "Fatal: %s\n", msg);
        abort();
    }
}
