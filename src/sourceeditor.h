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

// TODO open, save and save as functions

class SourceEditor : public QWidget, private Ui::SourceEditor {
    Q_OBJECT

public:
    SourceEditor(QWidget *parent = 0);
    ~SourceEditor();

    QString sourceName() const;
    void setSourceName(const QString &_name);

private slots:
    void openFile(); // Opens a source code file
    void save(); // Save the current source code file
    void saveAs(); // Save the current source code file

private:
    /*
     * Check if it's ok to continue
     */
    bool okToContinue();
    /*
     * return if current robot was modified
     * Ex.: Added new sensor
     */
    bool isSourceModified() const;

    QString currentSourceName;

};

#endif
