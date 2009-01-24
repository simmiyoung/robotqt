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

#include <QtGlobal>
#include <QCoreApplication>

#include "config.h"

Config::Config()
{
#if defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
    RobotQtDir = QDir::home();
    if (!RobotQtDir.exists(RobotQtDir.absolutePath() + "/.robotqt"))
        RobotQtDir.mkdir(".robotqt");
    RobotQtDir.cd(".robotqt");
    RobotQtPath = RobotQtDir.absolutePath() + "/.robotqt";
#elif defined(Q_OS_WIN32)
    RobotQtDir = QDir::current();
    RobotQtPath = RobotQtDir.absolutePath();
#endif
    // I think this is not the best way to do that, but anyway..
    logFile = QFile(QDir::fromNativeSeparators(RobotQtPath + "/debuglog.txt"));
}

void handleRobotQtMessages(QtMsgType type, const char *msg)
{
    if (logFile.open(QFile::WriteOnly | QFile::Append)) {
        QTextStream log(&logFile);
        switch (type) {
            case QtDebugMsg:
                log << "Debug: " << msg << endl;
            break;
            case QtWarningMsg:
                log << "Warning: " << msg << endl;
            break;
            case QtCriticalMsg:
                log << "Critical: " << msg << endl;
            break;
            case QtFatalMsg:
                log << "Fatal: " << msg << endl;
                QCoreApplication::exit(1); // ERROR
        }
    }
}
