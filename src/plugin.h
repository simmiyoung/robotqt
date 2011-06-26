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
 * plugin.h
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

#ifndef PLUGIN_H
#define PLUGIN_H

#include <QStringList>

#include <QXmlAttributes>

#include <QVector>
#include <QPen>

class QGraphicsView;
class QGraphicsItemGroup;
class QGraphicsEllipseItem;
class QGraphicsLineItem;
class QGraphicsRectItem;

#define REGEXP_COLOR "#([a-fA-F\\d]{1}|[a-fA-F\\d]{3}|[a-fA-F\\d]{6})"
#define REGEXP_FLOAT "\\d+(\\.\\d+)?"

/**
 * This is the base plugin class
 */

class Plugin {
public:

	struct Command {

		// TODO: structure for all plugin commands

		// Possible drawing commands
		enum Draw {
			Pen,
			Rect,
			Line,
			Ellipse,
		};

		Command(Draw cmd, const QString &values)
		: m_drawCmd(cmd),
			m_values(values)
		{

		}

		Draw drawCommand() const { return m_drawCmd; }
		QString values() const { return m_values; }

		Draw m_drawCmd;
		QString m_values;
	};

	Plugin();
	~Plugin();

	/**
	 * For XML Processing.
	 * Maybe it is better to separate this to the Plugin classes. But,
	 * for now, it's not necessary to add this complexity to the
	 * codebase
	 */
	virtual bool           setXMLCommand(const QString &cmd,
	                                     const QXmlAttributes &atts) = 0;
	virtual bool           setXMLDrawingCommand(const QString &cmd,
	                                            const QXmlAttributes &atts);
							           
	void                   setErrorStr(const QString &str);
	QString                errorStr() const;

	virtual bool           render(QGraphicsView *graphicsView) = 0;

protected:
	void                   setErrorCmdStr(const QString &attr,
	                                      const QString &cmd,
	                                      const QString &format);

	QVector<Command *>     drawStack() const;

	QGraphicsItemGroup   * itemGroup() const;
	void                   setItemGroup(QGraphicsItemGroup *group);

	// drawing commands parser
	bool                   setCurPen(const QStringList &tokList);
	QGraphicsRectItem    * rectItem(const QStringList &tokList);
	QGraphicsLineItem    * lineItem(const QStringList &tokList);
	QGraphicsEllipseItem * ellipseItem(const QStringList &tokList);

private:
	// XML Parser error string
	QString             m_errorStr;

	// FIFO stack for draw commands
	QVector<Command *>  m_drawStack;

	// Current pen for the painter
	QPen                m_curPen;

	// All QGraphicsItem from this plugin
	QGraphicsItemGroup *m_itemGroup;
};

#endif // PLUGIN_H
