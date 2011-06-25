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
 * sensor.cpp
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
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsItemGroup>

#include <QStringList>
#include <QRegExp>

#include "scenario.h"
#include "config.h"

bool Scenario::setXMLCommand(const QString &cmd, const QXmlAttributes &atts)
{
	if (cmd == "set") {
		qDebug() << "Found a set command";

	} else if (cmd == "size") {
		qDebug() << "Found a size command";

		QString ret;

		ret = atts.value("width");
		if (!ret.isEmpty()) {
			m_width = ret.toInt();
		} else {
			m_errorStr = QObject::tr("Width attribute is empty.");
			return false;
		}

		ret = atts.value("height");
		if (!ret.isEmpty()) {
			m_height = ret.toInt();
		} else {
			m_errorStr = QObject::tr("Height attribute is empty.");
			return false;
		}

		qDebug() << "Scenario width = " << m_width << " height = " << m_height;

	} else {
		m_errorStr = QObject::tr("%1 command is not supported by a Scenario Plugin.")
			.arg(cmd);

		return false;
	}

	return true;
}

bool Scenario::render(QGraphicsView *graphicsView)
{
	qDebug() << "Cleaning past Scenarios, if exists, and setting up the new one";

	QGraphicsScene *scene = new QGraphicsScene();

	// deletes items that belongs to the last scenario plugin, if this
	// is the first scenario loaded, it does nothing.
	delete m_itemsGroup;

	graphicsView->setScene(scene);

	qDebug() << "Painting the Scenario";

	QList<QGraphicsItem *> itemsList;

	while (!m_drawStack.isEmpty()) {
		const Plugin::Command *cmd = m_drawStack.front();
		m_drawStack.pop_front();

		QStringList tokList = cmd->values().split(':', QString::SkipEmptyParts);
		QStringList tmpList;
		int tokIdx;

		switch (cmd->drawCommand()) {
		case Plugin::Command::Pen: 

			// setting up width
			tokIdx = tokList.indexOf(QRegExp("width=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("width", "pen", "0-9[.0-9]");
				return false;
			}

			tmpList = tokList.at(tokIdx).split('=');
			m_curPen.setWidthF(tmpList.at(1).toDouble());

			// setting up color
			tokIdx = tokList.indexOf(QRegExp("color=" REGEXP_COLOR));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("color", "pen", "#RRGGBB");
				return false;
			}

			tmpList = tokList.at(tokIdx).split('=');
			m_curPen.setColor(QColor(tmpList.at(1)));
			break;

			// added brackets to delimit the variables scope
			// thats not necessary on case Pen.
		case Plugin::Command::Rect: {
			tokIdx = tokList.indexOf(QRegExp("x=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("x", "rect", "0-9[.0-9]");
				return false;
			}

			tmpList = tokList.at(tokIdx).split('=');
			qreal x = tmpList.at(1).toDouble();

			tokIdx = tokList.indexOf(QRegExp("y=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("y", "rect", "0-9[.0-9]");
				return false;
			}

			tmpList = tokList.at(tokIdx).split('=');
			qreal y = tmpList.at(1).toDouble();

			tokIdx = tokList.indexOf(QRegExp("width=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("width", "rect", "0-9[.0-9]");
				return false;
			}

			tmpList = tokList.at(tokIdx).split('=');
			qreal w = tmpList.at(1).toDouble();

			tokIdx = tokList.indexOf(QRegExp("height=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("height", "rect", "0-9[.0-9]");
				return false;
			}

			tmpList = tokList.at(tokIdx).split('=');
			qreal h = tmpList.at(1).toDouble();

			// setting up color
			tokIdx = tokList.indexOf(QRegExp("color=" REGEXP_COLOR));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("color", "rect", "#RRGGBB");
				return false;
			}

			tmpList = tokList.at(tokIdx).split('=');

			QGraphicsRectItem *rectItem = new QGraphicsRectItem(x, y, w, h);
	
			rectItem->setBrush(QBrush(QColor(tmpList.at(1))));
			rectItem->setPen(m_curPen);

			itemsList.push_back(rectItem);
		}
			break;

		case Plugin::Command::Line: {
			tokIdx = tokList.indexOf(QRegExp("x1=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("x1", "line", "0-9[.0-9]");
				return false;
			}

			tmpList = tokList.at(tokIdx).split('=');
			qreal x1 = tmpList.at(1).toDouble();

			tokIdx = tokList.indexOf(QRegExp("y1=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("y1", "line", "0-9[.0-9]");
				return false;
			}

			tmpList = tokList.at(tokIdx).split('=');
			qreal y1 = tmpList.at(1).toDouble();

			tokIdx = tokList.indexOf(QRegExp("x2=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("x2", "line", "0-9[.0-9]");
				return false;
			}

			tmpList = tokList.at(tokIdx).split('=');
			qreal x2 = tmpList.at(1).toDouble();

			tokIdx = tokList.indexOf(QRegExp("y2=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("y2", "line", "0-9[.0-9]");
				return false;
			}

			tmpList = tokList.at(tokIdx).split('=');
			qreal y2 = tmpList.at(1).toDouble();

			QGraphicsLineItem *lineItem = new QGraphicsLineItem(x1, y1, x2, y2);
	
			lineItem->setPen(m_curPen);

			itemsList.push_back(lineItem);
		}
			break;

		case Plugin::Command::Ellipse: {
			tokIdx = tokList.indexOf(QRegExp("x=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("x", "rect", "0-9[.0-9]");
				return false;
			}
				
			tmpList = tokList.at(tokIdx).split('=');
			qreal x = tmpList.at(1).toDouble();
				
			tokIdx = tokList.indexOf(QRegExp("y=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("y", "rect", "0-9[.0-9]");
				return false;
			}
				
			tmpList = tokList.at(tokIdx).split('=');
			qreal y = tmpList.at(1).toDouble();
				
			tokIdx = tokList.indexOf(QRegExp("width=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("width", "rect", "0-9[.0-9]");
				return false;
			}
				
			tmpList = tokList.at(tokIdx).split('=');
			qreal w = tmpList.at(1).toDouble();
				
			tokIdx = tokList.indexOf(QRegExp("height=" REGEXP_FLOAT));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("height", "rect", "0-9[.0-9]");
				return false;
			}
				
			tmpList = tokList.at(tokIdx).split('=');
			qreal h = tmpList.at(1).toDouble();
				
			// setting up color
			tokIdx = tokList.indexOf(QRegExp("color=" REGEXP_COLOR));
			// error, regexp not found
			if (tokIdx == -1) {
				m_errorStr = errorCmdStr("color", "rect", "#RRGGBB");
				return false;
			}
				
			tmpList = tokList.at(tokIdx).split('=');
				
			QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(x, y, w, h);
				
			ellipseItem->setBrush(QBrush(QColor(tmpList.at(1))));
			ellipseItem->setPen(m_curPen);
				
			itemsList.push_back(ellipseItem);
		}
			break;
		}
	}

	m_itemsGroup = scene->createItemGroup(itemsList);

	qDebug() << "Resizing GraphicsView Widget";

	graphicsView->resize(QSize(m_width, m_height));
	graphicsView->setMaximumSize(QSize(m_width, m_height));

	// ========

	return true;
}
