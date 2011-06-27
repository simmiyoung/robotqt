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
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
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
	: m_itemGroup(0),
		m_point(QPointF())
{
	m_curPen.setStyle(Qt::SolidLine);
	m_curPen.setBrush(Qt::SolidPattern);
	m_curPen.setWidth(1);
	m_curPen.setBrush(Qt::black);
}

Plugin::~Plugin()
{
	qDeleteAll(m_drawStack);

	// it also deletes all items that belongs to this group
	delete m_itemGroup;
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
																			CMD4(x1, y1, x2, y2)));
	} else if (cmd == "ellipse") {
		m_drawStack.push_back(new Command(Command::Ellipse,
																			CMD5(x, y, width, height, color)));
	} else {
		m_errorStr = QObject::tr("%1 is not a valid draw command.").arg(cmd);
		return false;
	}

	return true;
}

void Plugin::setPos(const QPointF &point)
{
	m_point = point;
}

QPointF Plugin::pos() const
{
	return m_point;
}

QString Plugin::pluginName() const
{
	return m_pluginName;
}

void Plugin::setPluginName(const QString &name)
{
	m_pluginName = name;
}

void Plugin::setErrorStr(const QString &str)
{
	m_errorStr = str;
}

void Plugin::setErrorCmdStr(const QString &attr,
                            const QString &cmd,
                            const QString &format)
{
	m_errorStr = QObject::tr("%1 attribute inside %2 command was not found or it's"
													 "in wrong format.\nThe right format is %3=%4.")
		.arg(attr)
		.arg(cmd)
		.arg(attr)
		.arg(format);
}

QString Plugin::errorStr() const
{
	qCritical() << m_errorStr;
	return m_errorStr;
}

bool Plugin::render(QGraphicsView *graphicsView, QGraphicsItem *parent)
{
	qDebug() << "Painting the Scenario";
	
	m_itemGroup = new QGraphicsItemGroup();
	QVector<Plugin::Command *> stack = drawStack(); // copying
	
	while (!stack.isEmpty()) {
		const Plugin::Command *cmd = stack.front();
		stack.pop_front();
		
		QStringList tokList = cmd->values().split(':', QString::SkipEmptyParts);
		bool ret = true; // return value
		
		switch (cmd->drawCommand()) {
			case Plugin::Command::Pen: 
				ret = setCurPen(tokList);
				break;
				
				// added brackets to delimit the variables scope
				// thats not necessary on case Pen.
			case Plugin::Command::Rect: {
				QGraphicsRectItem *rect = rectItem(tokList);

				if (rect)
					m_itemGroup->addToGroup(rect);
				else
					ret = false;
			}
				break;
				
			case Plugin::Command::Line: {
				QGraphicsLineItem *line = lineItem(tokList);

				if (line)
					m_itemGroup->addToGroup(line);
				else
					ret = false;
			}
				break;
				
			case Plugin::Command::Ellipse: {
				QGraphicsEllipseItem *ellipse = ellipseItem(tokList);

				if (ellipse)
					m_itemGroup->addToGroup(ellipse);
				else
					ret = false;
			}
				break;
		}
		
		if (!ret) {
			delete m_itemGroup; // force to delete the group
			return false;
		}
	}
	
	if (parent)
		m_itemGroup->setParentItem(parent);
	
	m_itemGroup->setPos(m_point);
	graphicsView->scene()->addItem(m_itemGroup);
	
	return true;
}


QVector<Plugin::Command *> Plugin::drawStack() const
{
	return m_drawStack;
}

QGraphicsItemGroup * Plugin::itemGroup() const
{
	return m_itemGroup;
}

void Plugin::setItemGroup(QGraphicsItemGroup *group)
{
	m_itemGroup = group;
}

/**
 * Drawign parsers
 */

bool Plugin::setCurPen(const QStringList &tokList)
{
	QStringList tmpList;
	int tokIdx;

	// setting up width
	tokIdx = tokList.indexOf(QRegExp("width=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("width", "pen", "0-9[.0-9]");
		return false;
	}

	tmpList = tokList.at(tokIdx).split('=');
	m_curPen.setWidthF(tmpList.at(1).toDouble());

	// setting up color
	tokIdx = tokList.indexOf(QRegExp("color=" REGEXP_COLOR));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("color", "pen", "#RRGGBB");
		return false;
	}

	tmpList = tokList.at(tokIdx).split('=');
	m_curPen.setColor(QColor(tmpList.at(1)));
	
	return true;
}

QGraphicsRectItem * Plugin::rectItem(const QStringList &tokList)
{
	QStringList tmpList;
	int tokIdx;

	tokIdx = tokList.indexOf(QRegExp("x=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("x", "rect", "0-9[.0-9]");
		return 0;
	}

	tmpList = tokList.at(tokIdx).split('=');
	qreal x = tmpList.at(1).toDouble();

	tokIdx = tokList.indexOf(QRegExp("y=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("y", "rect", "0-9[.0-9]");
		return 0;
	}

	tmpList = tokList.at(tokIdx).split('=');
	qreal y = tmpList.at(1).toDouble();

	tokIdx = tokList.indexOf(QRegExp("width=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("width", "rect", "0-9[.0-9]");
		return 0;
	}

	tmpList = tokList.at(tokIdx).split('=');
	qreal w = tmpList.at(1).toDouble();

	tokIdx = tokList.indexOf(QRegExp("height=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("height", "rect", "0-9[.0-9]");
		return 0;
	}

	tmpList = tokList.at(tokIdx).split('=');
	qreal h = tmpList.at(1).toDouble();

	// setting up color
	tokIdx = tokList.indexOf(QRegExp("color=" REGEXP_COLOR));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("color", "rect", "#RRGGBB");
		return 0;
	}

	tmpList = tokList.at(tokIdx).split('=');

	QGraphicsRectItem *rectItem = new QGraphicsRectItem(x, y, w, h);
	rectItem->setBrush(QBrush(QColor(tmpList.at(1))));
	rectItem->setPen(m_curPen);

	return rectItem;
}

QGraphicsLineItem * Plugin::lineItem(const QStringList &tokList)
{
	QStringList tmpList;
	int tokIdx;

	tokIdx = tokList.indexOf(QRegExp("x1=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("x1", "line", "0-9[.0-9]");
		return 0;
	}

	tmpList = tokList.at(tokIdx).split('=');
	qreal x1 = tmpList.at(1).toDouble();

	tokIdx = tokList.indexOf(QRegExp("y1=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("y1", "line", "0-9[.0-9]");
		return 0;
	}

	tmpList = tokList.at(tokIdx).split('=');
	qreal y1 = tmpList.at(1).toDouble();

	tokIdx = tokList.indexOf(QRegExp("x2=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("x2", "line", "0-9[.0-9]");
		return 0;
	}

	tmpList = tokList.at(tokIdx).split('=');
	qreal x2 = tmpList.at(1).toDouble();

	tokIdx = tokList.indexOf(QRegExp("y2=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("y2", "line", "0-9[.0-9]");
		return 0;
	}

	tmpList = tokList.at(tokIdx).split('=');
	qreal y2 = tmpList.at(1).toDouble();

	QGraphicsLineItem *lineItem = new QGraphicsLineItem(x1, y1, x2, y2);
	lineItem->setPen(m_curPen);

	return lineItem;
}

QGraphicsEllipseItem * Plugin::ellipseItem(const QStringList &tokList)
{
	QStringList tmpList;
	int tokIdx;

	tokIdx = tokList.indexOf(QRegExp("x=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("x", "ellipse", "0-9[.0-9]");
		return 0;
	}
				
	tmpList = tokList.at(tokIdx).split('=');
	qreal x = tmpList.at(1).toDouble();
				
	tokIdx = tokList.indexOf(QRegExp("y=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("y", "ellipse", "0-9[.0-9]");
		return 0;
	}
				
	tmpList = tokList.at(tokIdx).split('=');
	qreal y = tmpList.at(1).toDouble();
				
	tokIdx = tokList.indexOf(QRegExp("width=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("width", "ellipse", "0-9[.0-9]");
		return 0;
	}
				
	tmpList = tokList.at(tokIdx).split('=');
	qreal w = tmpList.at(1).toDouble();
				
	tokIdx = tokList.indexOf(QRegExp("height=" REGEXP_FLOAT));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("height", "ellipse", "0-9[.0-9]");
		return 0;
	}
				
	tmpList = tokList.at(tokIdx).split('=');
	qreal h = tmpList.at(1).toDouble();
				
	// setting up color
	tokIdx = tokList.indexOf(QRegExp("color=" REGEXP_COLOR));
	// error, regexp not found
	if (tokIdx == -1) {
		setErrorCmdStr("color", "ellipse", "#RRGGBB");
		return 0;
	}
				
	tmpList = tokList.at(tokIdx).split('=');
				
	QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(x, y, w, h);
	ellipseItem->setBrush(QBrush(QColor(tmpList.at(1))));
	ellipseItem->setPen(m_curPen);

	return ellipseItem;
}
