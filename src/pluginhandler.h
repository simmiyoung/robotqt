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
 * pluginhandler.cpp
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

#ifndef PLUGINHANDLER_H
#define PLUGINHANDLER_H

#include <QXmlDefaultHandler>
#include <QString>
#include <QSharedPointer>

#include "plugin.h"

class QGraphicsView;

/**
 * This class implements a simple SAX XML parser handler
 */

class PluginHandler : public QXmlDefaultHandler {
public:
	enum PluginType {
		Scenario,
		Sensor,
		Robot
	};

	PluginHandler(QGraphicsView *graphicsView);

	bool    startDocument();
	bool    endDocument();

	bool    startElement(const QString &namespaceURI,
	                     const QString &localName,
	                     const QString &qName,
	                     const QXmlAttributes &atts);
	bool    endElement(const QString &namespaceURI,
	                   const QString &localName,
	                   const QString &qName);

	bool    characters(const QString &ch);

	bool    fatalError(const QXmlParseException &exception);

	QString errorString() const;

private:
	QGraphicsView         *m_graphicsView;
								        
	QString                m_currentText;
	QString                m_errorStr;
								        
	bool                   m_metPluginTag;
	PluginType             m_pluginType;

	QSharedPointer<Plugin> m_plugin;
};

#endif // PLUGINHANDLER_H
