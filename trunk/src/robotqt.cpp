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
 * robotqt.cpp
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


#include "robotqt.h"
#include "config.h"

// Core
#include <QtCore/QSettings>

// GUI
#include <QtGui/QMessageBox>
#include <QtGui/QKeySequence>

// UI
#include "sourceeditor.h"

RobotQt::RobotQt( QWidget *parent ) :
	QMainWindow( parent )
{
	setupUi( this );

	sourceEditor = new SourceEditor( this );

	setupActions();
	readSettings();
}

RobotQt::~RobotQt()
{

}

/**
 * Private Slots
 */

void RobotQt::openAbout()
{
	QMessageBox::about(this, tr("About RobotQt"),
		tr("<h2>RobotQt %1</h2>"
		"<p>Copyright &copy; 2010 Felipe Ferreri Tonello</p>"
		"<p>RobotQt is a open source 2D robot simulator for academic purpose.</p>").arg(String_Version));
}

void RobotQt::openFile()
{

}

/**
 * Private Methods
 */

void RobotQt::setupActions()
{
	actionPreferences->setShortcut( QKeySequence::Preferences );
	actionNew->setShortcut( QKeySequence::New );
	actionQuit->setShortcut( QKeySequence::Quit );

	fileToolBar->addAction( actionNew );
	fileToolBar->addAction( actionAddPlugin );
	controlToolBar->addAction( actionPlay );
	controlToolBar->addAction( actionPause );
	controlToolBar->addAction( actionStop );

	graphicsView->addAction( actionPlay );
	graphicsView->addAction( actionPause );
	graphicsView->addAction( actionStop );
	graphicsView->setContextMenuPolicy( Qt::ActionsContextMenu );

	connect( actionQuit, SIGNAL(triggered()), this, SLOT(close()) );
	connect( actionAddPlugin, SIGNAL(triggered()), this, SLOT(openFile()) );
	connect( actionAboutRobotQt, SIGNAL(triggered()), this, SLOT(openAbout()) );
	connect( actionSourceEditor, SIGNAL(triggered()), sourceEditor, SLOT(show()) );
}

void RobotQt::readSettings()
{
	QSettings settings( "RobotQt.org", "RobotQt" );

	qDebug() << "Reading settings for RobotQt Main Window";

	settings.beginGroup( "RobotQtMainWindow" );
	// do stuff
	settings.endGroup();
}
