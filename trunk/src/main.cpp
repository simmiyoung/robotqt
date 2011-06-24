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
 * main.cpp
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

#include <QApplication>
#include <QTime>

#include "robotqt.h"
#include "config.h"

#if QT_VERSION < 0x040600 // needs Qt 4.6.0 or better
#error "Please use Qt 4.6 or a more recent version"
#endif

int main(int argc, char *argv[])
{
	qInstallMsgHandler(handleRobotQtMessages);
	QApplication a(argc, argv);

	// setting random values
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

	RobotQt w;

	// QObject::connect(&a, SIGNAL(aboutToQuit()), &w, SLOT(beforeQuit()));

	w.show();

	return a.exec();
}
