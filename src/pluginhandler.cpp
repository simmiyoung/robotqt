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

#include "config.h"

/**
 * TODO: - add debug log comments
 *       - explatory comments
 *       - support a generic viewer of plugins
 */

// initialize signleton
PluginHandler *PluginHandler::m_pPluginHandler = 0;

PluginHandler::PluginHandler()
	: m_graphicsView(0),
	  m_metDrawingTag(false),
	  m_metPluginTag(false),
		m_curPlugin(0)
{

}

PluginHandler::~PluginHandler()
{
	qDeleteAll(m_MMPlugin);
	PluginFactory::cleanScenario(); // scenario pointer = 0
	m_pPluginHandler = 0;
}

/**
 * Singleton implementation
 */
PluginHandler * PluginHandler::getInstance()
{
	return (m_pPluginHandler) ? m_pPluginHandler : 
		(m_pPluginHandler = new PluginHandler());
}

void PluginHandler::setGraphicsView(QGraphicsView *graphicsView)
{
	m_graphicsView = graphicsView;
}

bool PluginHandler::startDocument()
{
	qDebug() << "Begin of XML document";

	return true;
}

bool PluginHandler::endDocument()
{
	qDebug() << "End of XML document";

	qDebug() << "Rendering the plugin to the GraphicsView Widget";

	// Render all modifications
	return m_curPlugin->render(m_graphicsView);
}

bool PluginHandler::startElement(const QString &namespaceURI,
                                 const QString &localName,
                                 const QString &qName,
                                 const QXmlAttributes &atts)
{
	Q_UNUSED(namespaceURI);
	Q_UNUSED(localName);

	if (!m_metPluginTag) {
		if (qName == "scenario") {
			qDebug() << "Found a Scenario Plugin";
			m_pluginType = Scenario;

		} else if (qName == "sensor") {
			qDebug() << "Found a Sensor Plugin";
			m_pluginType = Sensor;
 
		} else if (qName == "robot") {
			qDebug() << "Found a Robot Plugin";
			m_pluginType = Robot;

		} else {
			qDebug() << "This file is not a RobotQt Plugin file";
			m_errorStr = QObject::tr("This file is not a RobotQt Plugin file.");
			return false;
		}

		// if didn't returned an error, it initializes the current plugin
		m_curPlugin = PluginFactory::getInstance(m_pluginType);

		// map all plugins n times, except scenario, that is only one possible
		if (m_pluginType == Scenario && !m_MMPlugin.contains(m_pluginType) ||
				m_pluginType != Scenario)
			m_MMPlugin.insert(m_pluginType, m_curPlugin);

		m_metPluginTag = true;

		return true;
	}

	if (!m_metDrawingTag && qName == "drawing") {
		qDebug() << "Found a drawing command";
		m_metDrawingTag = true;

		return true;
	}

	if (m_metDrawingTag) {
		if (!m_curPlugin->setXMLDrawingCommand(qName, atts)) {
			m_errorStr = m_curPlugin->errorStr();
			m_metDrawingTag = false;
			m_metPluginTag = false;
			return false;
		}
	} else {		
		if (!m_curPlugin->setXMLCommand(qName, atts)) {
			m_errorStr = m_curPlugin->errorStr();
			m_metDrawingTag = false;
			m_metPluginTag = false;
			return false;
		}
	}

	return true;
}

bool PluginHandler::endElement(const QString &namespaceURI,
                               const QString &localName,
                               const QString &qName)
{
	Q_UNUSED(namespaceURI);
	Q_UNUSED(localName);
	
	if (qName == "drawing")
		m_metDrawingTag = false;
	else if (qName == "scenario" ||
					 qName == "robot" ||
					 qName == "sensor")
		m_metPluginTag = false;
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

PluginHandler::MMPlugin PluginHandler::pluginMM() const
{
	return m_MMPlugin;
}
