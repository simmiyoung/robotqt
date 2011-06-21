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
#include <QMessageBox>

#include "pluginhandler.h"
#include "pluginfactory.h"

/**
 * TODO: - add debug log comments
 *       - explatory comments
 *       - support a generic viewer of plugins
 */

PluginHandler::PluginHandler(QGraphicsView *graphicsView)
	: m_graphicsView(graphicsView),
	  m_metPluginTag(false)
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
	if (!m_metPluginTag) {
		if (qName == "scenario") {
			m_pluginType = Scenario;

		} else if (qName == "sensor") {
			m_pluginType = Sensor;

		} else if (qName == "robot") {
			m_pluginType = Robot;

		} else {
			m_errorStr = QObject::tr("The file is not a RobotQt Plugin file.");
			return false;
		}

		// if didn't returned an error, it initializes the current plugin
		m_plugin = PluginFactory::getInstance(m_pluginType);
		m_metPluginTag = true;

	}


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
	QMessageBox::information(m_graphicsView->window(),
	                         QObject::tr("SAX Bookmarks"),
	                         QObject::tr("Parse error at line %1, column %2:\n %3")
	                         .arg(exception.lineNumber())
	                         .arg(exception.columnNumber())
	                         .arg(exception.message()));
	return false;
}

QString PluginHandler::errorString() const
{
	return m_errorStr;
}
