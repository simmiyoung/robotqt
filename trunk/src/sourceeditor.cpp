/*
 * sourceeditor.cpp
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

#include "sourceeditor.h"

SourceEditor::SourceEditor(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);

    closeButton->setShortcut(QKeySequence::Close);

    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

SourceEditor::~SourceEditor()
{

}
