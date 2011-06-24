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
 * plugin.cpp
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
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>

#include "plugin.h"
#include "config.h"

// Macros for the command string
#define CMD1(a) QString("%1=%2") \
	.arg(#a).arg(atts.value(#a))

#define CMD2(a, b) QString("%1=%2:%3=%4") \
	.arg(#a).arg(atts.value(#a)) \
	.arg(#b).arg(atts.value(#b))

#define CMD3(a, b, c) QString("%1=%2:%3=%4:%5=%6") \
	.arg(#a).arg(atts.value(#a)) \
	.arg(#b).arg(atts.value(#b)) \
	.arg(#c).arg(atts.value(#c))

#define CMD4(a, b, c, d) QString("%1=%2:%3=%4:%5=%6:%7=%8") \
	.arg(#a).arg(atts.value(#a)) \
	.arg(#b).arg(atts.value(#b)) \
	.arg(#c).arg(atts.value(#c)) \
	.arg(#d).arg(atts.value(#d))

#define CMD5(a, b, c, d, e) QString("%1=%2:%3=%4:%5=%6:%7=%8:%9=%10") \
	.arg(#a).arg(atts.value(#a)) \
	.arg(#b).arg(atts.value(#b)) \
	.arg(#c).arg(atts.value(#c)) \
	.arg(#d).arg(atts.value(#d)) \
	.arg(#e).arg(atts.value(#e))


#define CMD6(a, b, c, d, e, f) QString("%1=%2:%3=%4:%5=%6:%7=%8:%9=%10:%11=%12") \
	.arg(#a).arg(atts.value(#a)) \
	.arg(#b).arg(atts.value(#b)) \
	.arg(#c).arg(atts.value(#c)) \
	.arg(#d).arg(atts.value(#d)) \
	.arg(#e).arg(atts.value(#e)) \
	.arg(#f).arg(atts.value(#f))

Plugin::Plugin()
{
	m_curPen.setStyle(Qt::SolidLine);
	m_curPen.setBrush(Qt::SolidPattern);
	m_curPen.setWidth(1);
	m_curPen.setBrush(Qt::black);
}

Plugin::~Plugin()
{
	qDeleteAll(m_drawStack);
	
	m_graphicsView->scene()->destroyItemGroup( m_itemsGroup);
}

void Plugin::setGraphicsView(QGraphicsView *graphicsView)
{
	m_graphicsView = graphicsView;
}

bool Plugin::setXMLDrawingCommand(const QString &cmd, const QXmlAttributes &atts)
{
	if (cmd == "pen") {
		m_drawStack.push_back(new Command(Command::Pen,
		                                CMD2(color, width)));
	} else if (cmd == "rect") {
		m_drawStack.push_back(new Command(Command::Rect,
		                                CMD5(x, y, width, height, color)));
	} else if (cmd == "line") {
		m_drawStack.push_back(new Command(Command::Line,
		                                CMD5(x1, y1, x2, y2, color)));
	} else if (cmd == "ellipse") {
		m_drawStack.push_back(new Command(Command::Ellipse,
		                                CMD5(x, y, width, height, color)));
	} else {
		qCritical() << cmd << " is not a valid draw command";
		m_errorStr = QObject::tr("%1 is not a valid draw command.").arg(cmd);
		return false;
	}

	return true;
}

QString Plugin::errorStr() const
{
	return m_errorStr;
}

QGraphicsItemGroup * Plugin::group() const
{
	return m_itemsGroup;
}
