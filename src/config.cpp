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

Config *Config::pConfig = 0; // initialize signleton

Config::Config()
{
    /*
     * If it's linux or unix, return $HOME/.robotqt
     * else (if is windows) return where RobotQt is installed, probably
     * HOMEDRIVE\robotqt
     */
#if defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
        RobotQtDir = QDir::home();
        if (!RobotQtDir.exists(".robotqt"))
            RobotQtDir.mkdir(".robotqt");
        RobotQtDir.cd(".robotqt");
        RobotQtPath = RobotQtDir.absolutePath();
#elif defined(Q_OS_WIN32)
        RobotQtDir = QDir::current();
        RobotQtPath = RobotQtDir.absolutePath();
#endif // Q_OS_*
}

/*
 * Singleton implementation
 */
Config * Config::getInstance()
{
    return pConfig ? pConfig : (pConfig = new Config());
}

QDir Config::getDir() const
{
    return RobotQtDir;
}

QString Config::getPath() const
{
    return RobotQtPath;
}

/*-------------------------------------
  End of Config class implementation
  -------------------------------------*/

void handleRobotQtMessages(QtMsgType type, const char *msg)
{
    Config *config = Config::getInstance();
    QFile log(config->getPath() + "/debuglog.txt");
    if (log.open(QFile::WriteOnly | QFile::Append)) {
        QTextStream logs(&log);
        switch (type) {
            case QtDebugMsg:
                logs << "Debug: " << msg << endl;
            break;
            case QtWarningMsg:
                logs << "Warning: " << msg << endl;
            break;
            case QtCriticalMsg:
                logs << "Critical: " << msg << endl;
            break;
            case QtFatalMsg:
                logs << "Fatal: " << msg << endl;
                QCoreApplication::exit(1); // ERROR, ABORT THE PROGRAM
            break;
        }
    }
}