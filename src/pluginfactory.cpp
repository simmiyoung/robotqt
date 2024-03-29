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
#include "plugin.h"
#include "scenario.h"
#include "sensor.h"
#include "robot.h"

// loading singleton object
Scenario *PluginFactory::m_pScenario = 0;

PluginFactory::PluginFactory()
{

}

Plugin * PluginFactory::getInstance(PluginHandler::PluginType pluginType)
{
	switch (pluginType) {
	case PluginHandler::Scenario:
		return (m_pScenario) ? m_pScenario : (m_pScenario = new Scenario());
		break;

	case PluginHandler::Sensor:		
		return new Sensor();
		break;

	case PluginHandler::Robot:
		return new Robot();
		break;
	}

	return 0;
}

void PluginFactory::cleanScenario()
{
	m_pScenario = 0;
}
