#ifndef ROBOTQT_H
#define ROBOTQT_H

#include <QtGui/QWidget>
#include "ui_robotqt.h"

class RobotQt : public QWidget
{
    Q_OBJECT

public:
    RobotQt(QWidget *parent = 0);
    ~RobotQt();

private:
    Ui::RobotQtClass ui;
};

#endif // ROBOTQT_H
