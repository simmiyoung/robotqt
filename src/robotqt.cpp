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
#include <QSize>
#include <QGraphicsScene>

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

	// setting a new scene to the graphics view
	graphicsView->setScene(new QGraphicsScene());

	qDebug() << "Setting up Actions";
	setupActions();

	qDebug() << "Setting up State Machine";
	setupStateMachine();

	qDebug() << "Reading Settup";
	readSettings();
}

RobotQt::~RobotQt()
{
	Config *config = Config::getInstance();
	delete config;

	PluginHandler *handler = PluginHandler::getInstance();
	delete handler;
}

/**
 * Private Slots
 */

void RobotQt::resetScenario()
{
	PluginHandler *handler = PluginHandler::getInstance();
	delete handler;
}

void RobotQt::openAbout()
{
	QMessageBox::about(this, tr("About RobotQt"),
	                   tr("<h2>RobotQt %1</h2>"
	                      "<p>Copyright &copy; 2010 Felipe Ferreri Tonello</p>"
	                      "<p>RobotQt is a open source 2D robot simulator for academic"
	                      "purpose.</p>").arg(String_Version));
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
	PluginHandler *handler = PluginHandler::getInstance();
	handler->setGraphicsView(graphicsView);
	QXmlSimpleReader reader;
	reader.setContentHandler(handler);
	reader.setErrorHandler(handler);

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
	}

	emit pluginLoaded();
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

	// connect(actionNew, SIGNAL(triggered()), this, SLOT(resetScenario()));
	connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
	// connect(actionAddPlugin, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(actionAboutRobotQt, SIGNAL(triggered()), this, SLOT(openAbout()));
	connect(actionSourceEditor, SIGNAL(triggered()), sourceEditor, SLOT(show()));
}

void RobotQt::setupStateMachine()
{
	m_stateInitial.addTransition(actionAddPlugin, SIGNAL(triggered()), &m_stateLoadingPlugin);
	m_stateLoadingPlugin.addTransition(this, SIGNAL(pluginLoaded()), &m_stateStopped);
	m_stateStopped.addTransition(actionPlay, SIGNAL(triggered()), &m_stateRunning);
	m_stateStopped.addTransition(actionAddPlugin, SIGNAL(triggered()), &m_stateLoadingPlugin);
	m_stateStopped.addTransition(actionNew, SIGNAL(triggered()), &m_stateInitial);
	m_stateRunning.addTransition(actionStop, SIGNAL(triggered()), &m_stateStopped);
	m_stateRunning.addTransition(actionPause, SIGNAL(triggered()), &m_statePaused);
	m_statePaused.addTransition(actionPlay, SIGNAL(triggered()), &m_stateRunning);
	m_statePaused.addTransition(actionStop, SIGNAL(triggered()), &m_stateStopped);
	m_statePaused.addTransition(actionAddPlugin, SIGNAL(triggered()), &m_stateLoadingPlugin);

	// Linking properties with respective state
	m_stateInitial.assignProperty(actionPlay, "enabled", false);
	m_stateInitial.assignProperty(actionStop, "enabled", false);
	m_stateInitial.assignProperty(actionPause, "enabled", false);
	m_stateInitial.assignProperty(actionAddPlugin, "enabled", true);
	m_stateInitial.assignProperty(actionNew, "enabled", false);

	m_stateStopped.assignProperty(actionPlay, "enabled", true);
	m_stateStopped.assignProperty(actionStop, "enabled", false);
	m_stateStopped.assignProperty(actionPause, "enabled", false);
	m_stateStopped.assignProperty(actionAddPlugin, "enabled", true);
	m_stateStopped.assignProperty(actionNew, "enabled", true);

	m_stateRunning.assignProperty(actionPlay, "enabled", false);
	m_stateRunning.assignProperty(actionStop, "enabled", true);
	m_stateRunning.assignProperty(actionPause, "enabled", true);
	m_stateRunning.assignProperty(actionAddPlugin, "enabled", false);
	m_stateRunning.assignProperty(actionNew, "enabled", false);

	m_statePaused.assignProperty(actionPlay, "enabled", true);
	m_statePaused.assignProperty(actionStop, "enabled", true);
	m_statePaused.assignProperty(actionPause, "enabled", false);
	m_statePaused.assignProperty(actionAddPlugin, "enabled", true);
	m_statePaused.assignProperty(actionNew, "enabled", false);

	connect(&m_stateInitial, SIGNAL(entered()), this, SLOT(resetScenario()));
	connect(&m_stateLoadingPlugin, SIGNAL(entered()), this, SLOT(openFile()));

	m_stateMachine.addState(&m_stateInitial);
	m_stateMachine.addState(&m_stateLoadingPlugin);
	m_stateMachine.addState(&m_stateStopped);
	m_stateMachine.addState(&m_stateRunning);
	m_stateMachine.addState(&m_statePaused);

	m_stateMachine.setInitialState(&m_stateInitial);
	m_stateMachine.start();
}

void RobotQt::readSettings()
{
	QSettings settings("RobotQt.org", "RobotQt");

	qDebug() << "Reading settings for RobotQt Main Window";

	settings.beginGroup("RobotQtMainWindow");
	// do stuff
	settings.endGroup();
}
