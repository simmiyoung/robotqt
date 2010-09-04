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

// Core


// GUI
#include <QtGui/QAction>
#include <QtGui/QMessageBox>

#include "sourceeditor.h"

SourceEditor::SourceEditor( QWidget *parent )
	: QMainWindow( parent )
{
	setupUi( this );

	setupActions();
}

SourceEditor::~SourceEditor()
{

}

QString SourceEditor::fileName() const
{
	return currentFileName;
}

void SourceEditor::setFileName( const QString &_name )
{
	currentFileName = _name;
}

/**
 * Private Slots
 */

void SourceEditor::openFile()
{

}

void SourceEditor::save()
{

}

void SourceEditor::saveAs()
{

}

/**
 * Private Methods
 */

void SourceEditor::setupActions()
{
	QAction *actionSeparator = new QAction( this );
	actionSeparator->setSeparator( true );
	
	actionOpen->setShortcut( QKeySequence::Open );
	actionSave->setShortcut( QKeySequence::Save );
	actionSaveAs->setShortcut( QKeySequence::SaveAs );
	actionClose->setShortcut( QKeySequence::Close );
	
	toolBar->addAction( actionOpen );
	toolBar->addAction( actionSave );
	toolBar->addAction( actionSaveAs );
	
	editor->addAction( actionOpen );
	editor->addAction( actionSave );
	editor->addAction( actionSaveAs );
	editor->addAction( actionSeparator );
	editor->addAction( actionClose );
	editor->setContextMenuPolicy(Qt::ActionsContextMenu);
	
	connect( actionOpen, SIGNAL(triggered()), this, SLOT(openFile()) );
	connect( actionSave, SIGNAL(triggered()), this, SLOT(save()) );
	connect( actionSaveAs, SIGNAL(triggered()), this, SLOT(saveAs()) );
	connect( actionClose, SIGNAL(triggered()), this, SLOT(close()) );
}

bool SourceEditor::okToContinue()
{
	if ( isFileModified() ) {
		int r = QMessageBox::warning( this, tr( "RobotQt" ),
					tr( "This source code has been modified.\n"
					"Do you want to save your changes?" ),
					QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel );
		if ( r == QMessageBox::Yes ) {
			save();
			return true;
		} else if ( r == QMessageBox::Cancel ) {
			return false;
		}
	}
	return true;
}

bool SourceEditor::isFileModified() const
{
	return false;
}
