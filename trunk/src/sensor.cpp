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
 * sensor.cpp
 * RobotQt - Robot Simulation
 * http://robotqt.org/
 *
 * Created by Felipe Tonello on 2011-06-20.
 *
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

#include <QGraphicsView>
#include <QGraphicsItem>

#include "config.h"
#include "sensor.h"
#include "pluginhandler.h"

bool Sensor::setXMLCommand(const QString &cmd, const QXmlAttributes &atts)
{
	if (cmd == "set") {
		qDebug() << "Found a set command";
		
		QString ret;
		
		if (!atts.value("name").isEmpty()) {
			ret = atts.value("name");
			if (!ret.isEmpty()) {
				setPluginName(ret);
			} else {
				setErrorStr(QObject::tr("Name attribute is empty."));
				return false;
			}
		}
		
		qDebug() << "Robot plugin name = " << ret;

	} else if(cmd == "pos") {
		QString ret;
		qreal x, y;
		
		ret = atts.value("x");
		if (!ret.isEmpty()) {
			x = ret.toDouble();
		} else {
			setErrorStr(QObject::tr("x attribute is empty."));
			return false;
		}
		
		ret = atts.value("y");
		if (!ret.isEmpty()) {
			y = ret.toDouble();
		} else {
			setErrorStr(QObject::tr("y attribute is empty."));
			return false;
		}

		setPos(QPointF(x, y));

	} else {
		setErrorStr(QObject::tr("%1 command is not supported by a Robot Plugin.")
		            .arg(cmd));
		
		return false;
	}
	
	return true;
}

bool Sensor::render(QGraphicsView *graphicsView, QGraphicsItem *parent)
{
	PluginHandler *handler = PluginHandler::getInstance();
	PluginHandler::MMPlugin mmap = handler->pluginMM();
	
	/**
	 * FIXME: It does not work with multiple robot plugins
	 *				To fix that, it's necessary to create a table
	 *				widget to select which robot plugin to select
	 */
	
	if (!mmap.contains(PluginHandler::Robot)) {
		setErrorStr("You must load a Robot plugin first.");
		return false;
	}
	
	QGraphicsItem *robot = dynamic_cast<QGraphicsItem *>(mmap.value(PluginHandler::Robot)->itemGroup());
	
	return Plugin::render(graphicsView, robot);
}
