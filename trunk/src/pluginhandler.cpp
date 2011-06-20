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
 * pluginhandler.h
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

#include "pluginhandler.h"

/**
 * TODO: - add debug log comments
 *       - explatory comments
 *       - support a generic viewer of plugins
 */

PluginHandler::PluginHandler(QGraphicsView *graphicsView)
	: m_graphicsView(graphicsView)
{

}

bool PluginHandler::startDocument()
{
	return true;
}

bool PluginHandler::endDocument()
{
	return true;
}

bool PluginHandler::startElement(const QString &namespaceURI,
                                 const QString &localName,
                                 const QString &qName,
                                 const QXmlAttributes &atts)
{
	return true;
}

bool PluginHandler::endElement(const QString &namespaceURI,
                               const QString &localName,
                               const QString &qName)
{
	return true;
}

bool PluginHandler::characters(const QString &ch)
{
	return true;
}

bool PluginHandler::fatalError(const QXmlParseException &exception)
{
	return true;
}

QString PluginHandler::errorString() const
{
	return QString("It happened one error.");
}