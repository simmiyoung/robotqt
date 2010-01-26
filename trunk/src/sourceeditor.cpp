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
