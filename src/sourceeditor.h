/*
 * sourceeditor.h
 * RobotQt - Robot Simulation
 *
 * Created by Felipe Tonello on 2008-12-10.
 * Copyright 2008 Felipe Ferreri Tonello. All rights reserved.
 * http://robotqt.googlecode.com/
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

#ifndef SOURCEEDITOR_H
#define SOURCEEDITOR_H

#include "ui_sourceeditor.h"

class SourceEditor : public QWidget, private Ui::SourceEditor {
Q_OBJECT

public:
    SourceEditor(QWidget *parent = 0);
    ~SourceEditor();

private:

};

#endif
