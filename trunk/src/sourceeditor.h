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
 * sourceeditor.h
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

#ifndef SOURCEEDITOR_H
#define SOURCEEDITOR_H

#include "ui_sourceeditor.h"

/**
	TODO open, save and save as functions
*/

class SourceEditor : public QMainWindow, private Ui::SourceEditor {
	Q_OBJECT

public:
	SourceEditor( QWidget *parent = 0 );
	~SourceEditor();

	QString fileName() const;
	void setFileName( const QString &_name );

private slots:
	void openFile();
	void save();
	void saveAs();

private:
	void setupActions();
	bool okToContinue();
	bool isFileModified() const;

	QString currentFileName;

};

#endif
