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

#include <QVector>
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
			setErrorStr(QObject::tr("Width attribute is empty."));
			return false;
		}

		ret = atts.value("height");
		if (!ret.isEmpty()) {
			m_height = ret.toInt();
		} else {
			setErrorStr(QObject::tr("Height attribute is empty."));
			return false;
		}

		qDebug() << "Scenario width = " << m_width << " height = " << m_height;

	} else {
		setErrorStr(QObject::tr("%1 command is not supported by a Scenario Plugin.")
		            .arg(cmd));

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
	delete itemGroup();

	graphicsView->setScene(scene);

	qDebug() << "Painting the Scenario";

	QList<QGraphicsItem *>     itemsList;
	QVector<Plugin::Command *> stack = drawStack();

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
				itemsList.push_back(rect);
			else
				ret = false;
		}
			break;

		case Plugin::Command::Line: {
			QGraphicsLineItem *line = lineItem(tokList);
			if (line)
				itemsList.push_back(line);
			else
				ret = false;
		}
			break;

		case Plugin::Command::Ellipse: {
			QGraphicsEllipseItem *ellipse = ellipseItem(tokList);
			if (ellipse)
				itemsList.push_back(ellipse);
			else
				ret = false;
		}
			break;
		}

		if (!ret)
			return false; // ret == false
	}

	setItemGroup(scene->createItemGroup(itemsList));

	qDebug() << "Resizing GraphicsView Widget";

	scene->setSceneRect(0.0, 0.0, m_width, m_height);

	// these 2 pixels more is for the scenerect pen width
	QSize size = QSize(m_width + 2, m_height + 2);
	graphicsView->resize(size);
	graphicsView->setMaximumSize(size);

	return true;
}
