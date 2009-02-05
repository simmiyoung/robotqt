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
#include <QDateTime>

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
    //TODO: Check if log file is too large
    if (log.open(QFile::WriteOnly | QFile::Append)) {
        QTextStream logs(&log);
        logs.setCodec("UTF-8"); // force to use unicode
        QDateTime currentTime = QDateTime::currentDateTime();
        QString current = currentTime.toString(Qt::ISODate); //YYYY-MM-DDTHH:MM:SS
        switch (type) {
            case QtDebugMsg:
                logs << "(" << current << ") Debug: " << msg << endl;
            break;
            case QtWarningMsg:
                logs << "(" << current << ") Warning: " << msg << endl;
            break;
            case QtCriticalMsg:
                logs << "(" << current << ") Critical: " << msg << endl;
            break;
            case QtFatalMsg:
                logs << "(" << current << ") Fatal: " << msg << endl;
                QCoreApplication::exit(1); // ERROR, ABORT THE PROGRAM
            break;
        }
    }
}
