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


// Core
#include <QSettings>
#include <QString>
#include <QFile>

// GUI
#include <QMessageBox>
#include <QKeySequence>
#include <QFileDialog>

// XML
#include <QXmlSimpleReader>
#include <QXmlInputSource>

// UI
#include "sourceeditor.h"

// General
#include "robotqt.h"
#include "config.h"
#include "pluginhandler.h"

/**
 * TODO: - Implement settings configurations
 *       -
 */

RobotQt::RobotQt(QWidget *parent)
	:	QMainWindow(parent)
{
	setupUi(this);

	// There are no reason to use smart pointer, since Qt destroys all QWidgets
	sourceEditor = new SourceEditor(this);

	qDebug() << "Setting up Actions";
	setupActions();

	qDebug() << "Reading Settup";
	readSettings();
}

/**
 * Public Slots
 */

void RobotQt::beforeQuit()
{	
	QSharedPointer<Config> config = Config::getInstance();
	config->closeLog();
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
	// RobotQt Plugins files should terminate with .rqt?
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open A Plugin File"),
	                                                QDir::currentPath(),
	                                                tr("RobotQt Plugin (*.rqt)"));

	if (fileName.isEmpty()) {
		qWarning() << "File " << fileName << " is empty";
		return;
	}

	qDebug() << "Setting up SAX XML Parser for " << fileName;

	// setup SAX XML Parser
	PluginHandler handler(graphicsView);
	QXmlSimpleReader reader;
	reader.setContentHandler(&handler);
	reader.setErrorHandler(&handler);

	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		qWarning() << "Cannot read file " << fileName << ": " << file.errorString();

		QMessageBox::warning(this, tr("RobotQt"),
				     tr("Cannot read file %1:\n%2.")
				     .arg(fileName)
				     .arg(file.errorString()));
		return;
	}

	qDebug() << "Calling PluginHandler callbacks methods";

	// The parser is calling PluginHandler callbacks methods
	QXmlInputSource xmlInputSource(&file);
	if (reader.parse(xmlInputSource)) {
		qDebug() << "Plugin Loaded";

		statusBar()->showMessage(tr("Plugin loaded"), 2000);
	}
}

/**
 * Private Methods
 */

void RobotQt::setupActions()
{
	actionPreferences->setShortcut(QKeySequence::Preferences);
	actionNew->setShortcut(QKeySequence::New);
	actionQuit->setShortcut(QKeySequence::Quit);

	fileToolBar->addAction(actionNew);
	fileToolBar->addAction(actionAddPlugin);
	controlToolBar->addAction(actionPlay);
	controlToolBar->addAction(actionPause);
	controlToolBar->addAction(actionStop);

	graphicsView->addAction(actionPlay);
	graphicsView->addAction(actionPause);
	graphicsView->addAction(actionStop);
	graphicsView->setContextMenuPolicy(Qt::ActionsContextMenu);

	connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
	connect(actionAddPlugin, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(actionAboutRobotQt, SIGNAL(triggered()), this, SLOT(openAbout()));
	connect(actionSourceEditor, SIGNAL(triggered()), sourceEditor, SLOT(show()));
}

void RobotQt::readSettings()
{
	QSettings settings("RobotQt.org", "RobotQt");

	qDebug() << "Reading settings for RobotQt Main Window";

	settings.beginGroup("RobotQtMainWindow");
	// do stuff
	settings.endGroup();
}
