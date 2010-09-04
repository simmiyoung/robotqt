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
 * sourceeditor.cpp
 * RobotQt - Robot Simulation
 * http://robotqt.org/
 *
 * Created by Felipe Tonello on 2010-09-04.
 *
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

#include <QtGui/QMessageBox>

#include "sourceeditor.h"

SourceEditor::SourceEditor(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);

	openButton->setShortcut(QKeySequence::Open);
	saveButton->setShortcut(QKeySequence::Save);
	saveAsButton->setShortcut(QKeySequence::SaveAs);
	closeButton->setShortcut(QKeySequence::Close);

	connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));
	connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
	connect(saveButton, SIGNAL(clicked()), this, SLOT(saveAs()));
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

SourceEditor::~SourceEditor()
{

}

QString SourceEditor::sourceName() const
{
	return currentSourceName;
}

void SourceEditor::setSourceName(const QString &_name)
{
	currentSourceName = _name;
}

void SourceEditor::openFile()
{

}

void SourceEditor::save()
{

}

void SourceEditor::saveAs()
{

}

bool SourceEditor::okToContinue()
{
	if (isSourceModified()) {
		int r = QMessageBox::warning(this, tr("RobotQt"),
					tr("This source code has been modified.\n"
					"Do you want to save your changes?"),
					QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		if (r == QMessageBox::Yes) {
			save();
			return true;
		} else if (r == QMessageBox::Cancel) {
			return false;
		}
	}
	return true;
}

bool SourceEditor::isSourceModified() const
{
	return false;
}
