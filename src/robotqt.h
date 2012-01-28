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
 * robotqt.h
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

#ifndef ROBOTQT_H
#define ROBOTQT_H

#include "ui_robotqt.h"

#include <QStateMachine>
#include <QState>
#include <QFinalState>

class SourceEditor;

/**
 * This is the main class that represents the main window
 */

class RobotQt : public QMainWindow, private Ui::RobotQt {
	Q_OBJECT

public:
	RobotQt(QWidget *parent = 0);
	~RobotQt();

signals:
	void pluginLoaded();

private slots:
	void resetScenario();
	void openAbout();
	void openFile();

private:
	void setupActions();
	void setupStateMachine();
	void readSettings();

	// UI's
	SourceEditor *sourceEditor;

	/* State Machine Framewok
	   For mor info, check docs/state-machine.png
	 */
	QStateMachine m_stateMachine;
	QState        m_stateRunning;       // Simulation is running
	QState        m_statePaused;        // Simulation has been paused
	QState        m_stateStopped;       // Simulation has been forced to stop
	QState        m_stateLoadingPlugin; // Loading Plugin
	QState        m_stateInitial;       // Simulation is empty (initial state)
};

#endif // ROBOTQT_H
