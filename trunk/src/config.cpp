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
 * config.cpp
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

#include <QtGlobal>
#include <QCoreApplication>
#include <QDateTime>

#include "config.h"

QSharedPointer<Config> Config::m_pConfig = QSharedPointer<Config>(); // initialize signleton

Config::Config()
{
	/**
	 * If it's *nix, return $HOME/.robotqt
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

/**
 * Singleton implementation
 */
QSharedPointer<Config> Config::getInstance()
{
	return (m_pConfig.isNull()) ? (m_pConfig = QSharedPointer<Config>(new Config())) : m_pConfig;
}

QDir Config::getDir() const
{
	return RobotQtDir;
}

QString Config::getPath() const
{
	return RobotQtPath;
}

/**
 * This method is called from QCoreApplication::aboutToQuit() signal
 */
void Config::closeLog()
{
	QSharedPointer<Config> config = Config::getInstance();
	QFile log(config->getPath() + "/robotqt_log.txt");

	if (log.open(QFile::WriteOnly | QFile::Append)) {
		QTextStream logs(&log);
		logs.setCodec("UTF-8"); // force to use unicode

		logs << endl;
		logs << "====================" << endl;
		logs << endl;
	}
}

/**
 * End of Config class implementation
 */
void handleRobotQtMessages(QtMsgType type, const char *msg)
{
	QSharedPointer<Config> config = Config::getInstance();
	QFile log(config->getPath() + "/robotqt_log.txt");
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
