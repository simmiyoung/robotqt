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

static const QString String_Version = "0.1";

/*
 * Config class
 * It's a singleton class, use Config::getInstance() to instance it
 */
class Config {
public:
    /*
     * Returns the, only available, instance of Config class
     */
    static Config * getInstance();

    /*
     * Returns the QDir object to where RobotQt is located
     */
    QDir getDir() const;

    /*
     * Same as getDir() but returns as a QString
     */
    QString getPath() const;

private:
    /*
     * Initialize config variables.
     * This constructor is private because it can't be initialize without the
     * getInstance() method.
     */
    Config();

    QDir RobotQtDir;
    QString RobotQtPath;

    static Config *pConfig;
};

/*
 * Message handler.
 * It's a function that prints out debug messages, warnings,
 * critical and fatal error messages. If it is a fatal message, the application
 * aborts immediately.
 */
void handleRobotQtMessages(QtMsgType type, const char *msg);

#endif // CONFIG_H
