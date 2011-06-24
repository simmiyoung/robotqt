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
		qDebug() << cmd << " command is not supported by a Scenario Plugin";
		m_errorStr = QObject::tr("%1 command is not supported by a Scenario Plugin.")
			.arg(cmd);

		return false;
	}

	return true;
}

bool Scenario::render(QGraphicsView *graphicsView)
{
	setGraphicsView(graphicsView);

	qDebug() << "Cleaning past Scenarios, if exists, and setting up the new one";

	QGraphicsScene *scene = new QGraphicsScene();

	// TODO: take care of other plugins items in this scene.
	delete graphicsView->scene();
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
			tokIdx = tokList.indexOf(QRegExp("width=\\d+(\\.\\d+)?"));
			tmpList = tokList.at(tokIdx).split('=');
			m_curPen.setWidthF(tmpList.at(1).toDouble());

			// setting up color
			tokIdx = tokList.indexOf(QRegExp("color=#[A-F\\d]{6}"));
			tmpList = tokList.at(tokIdx).split('=');
			m_curPen.setColor(QColor(tmpList.at(1)));
			break;

			// added brackets to delimit the variables scope
			// thats not necessary on case Pen.
		case Plugin::Command::Rect: {
			tokIdx = tokList.indexOf(QRegExp("x=\\d+(\\.\\d+)?"));
			tmpList = tokList.at(tokIdx).split('=');
			qreal x = tmpList.at(1).toDouble();

			tokIdx = tokList.indexOf(QRegExp("y=\\d+(\\.\\d+)?"));
			tmpList = tokList.at(tokIdx).split('=');
			qreal y = tmpList.at(1).toDouble();

			tokIdx = tokList.indexOf(QRegExp("width=\\d+(\\.\\d+)?"));
			tmpList = tokList.at(tokIdx).split('=');
			qreal w = tmpList.at(1).toDouble();

			tokIdx = tokList.indexOf(QRegExp("height=\\d+(\\.\\d+)?"));
			tmpList = tokList.at(tokIdx).split('=');
			qreal h = tmpList.at(1).toDouble();

			QGraphicsRectItem *rectItem = new QGraphicsRectItem(x, y, w, h);

			// setting up color
			tmpList = tokList.at(tokList.indexOf(QRegExp("color=#[A-F\\d]{6}"))).split('=');
			rectItem->setBrush(QBrush(QColor(tmpList.at(1))));

			rectItem->setPen(m_curPen);

			itemsList.push_back(rectItem);
		}
			break;

		case Plugin::Command::Line:
			break;

		case Plugin::Command::Ellipse:
			break;
		}
	}

	m_itemsGroup = scene->createItemGroup(itemsList);

	qDebug() << "Resizing GraphicsView Widget";

	// TODO: melhorar o esquema de sizehint da mainwindow e do
	// graphicsprint.

	QSize newSz(m_width, m_height);

	QSize gvSz = graphicsView->size();
	QSize mwSz = graphicsView->window()->size();

	QSize diffSz(m_width - gvSz.width(), m_height - gvSz.height());

	graphicsView->setMinimumSize(newSz);
	graphicsView->window()->resize(mwSz + diffSz);

	// ========

	return true;
}
