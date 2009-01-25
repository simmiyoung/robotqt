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
#include <QDir>
#include <QFile>

/*
 * Config class
 * It's a singleton class, use Config::getInstance() to instance it
 */
class Config {
public:
    static Config * getInstance();

    QDir getDir() const;
    QString getPath() const;

protected:
    Config();

private:
    QDir RobotQtDir;
    QString RobotQtPath;

    static Config *pConfig;
};

void handleRobotQtMessages(QtMsgType type, const char *msg);

#endif // CONFIG_H
