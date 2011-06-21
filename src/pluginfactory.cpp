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
 * pluginfactory.cpp
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

#include "pluginfactory.h"
#include "scenario.h"
#include "sensor.h"
#include "robot.h"

QSharedPointer<Plugin> PluginFactory::m_pScenario = QSharedPointer<Plugin>(); // Scenario Singleton

QSharedPointer<Plugin> PluginFactory::getInstance(PluginHandler::PluginType pluginType)
{
	switch (pluginType) {
	case PluginHandler::Scenario:

		if (m_pScenario.isNull()) {
			m_pScenario = QSharedPointer<Plugin>(new Scenario());
		}

		return m_pScenario;
		break;

	case PluginHandler::Sensor:
		
		QSharedPointer<Plugin>(new Sensor());
		break;

	case PluginHandler::Robot:

		QSharedPointer<Plugin>(new Robot());
		break;
	}

	return QSharedPointer<Plugin>();
}
