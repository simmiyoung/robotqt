/**
 * RobotQt - Robot Simulation
 * Copyright (C) 2010 Felipe Ferreri Tonello
 *
 * This file is part of RobotQt.
 *
 * RobotQt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RobotQt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RobotQt.  If not, see <http://www.gnu.org/licenses/>.
 *
 * ----
 *
 * config.h
 * RobotQt - Robot Simulation
 * http://robotqt.org/
 *
 * Created by Felipe Tonello on 2010-09-04.
 *
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
	~Config();

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
void handleRobotQtMessages( QtMsgType type, const char *msg );

#endif // CONFIG_H
