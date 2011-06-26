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
 * pluginfactory.h
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

#ifndef PLUGINFACTORY_H
#define PLUGINFACTORY_H

#include "pluginhandler.h"

class Plugin;
class Scenario;

/**
 * This class creates all Plugins instances
 */

class PluginFactory {
public:
	static Plugin * getInstance(PluginHandler::PluginType pluginType);

	// to be called when pluginhandler is destroyed
	static void cleanScenario();

private:
	static Scenario *m_pScenario;

	PluginFactory();
};

#endif // PLUGINFACTORY_H
