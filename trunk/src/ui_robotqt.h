/********************************************************************************
** Form generated from reading ui file 'robotqt.ui'
**
** Created: Wed Dec 10 16:14:22 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ROBOTQT_H
#define UI_ROBOTQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotQtClass
{
public:

    void setupUi(QWidget *RobotQtClass)
    {
    if (RobotQtClass->objectName().isEmpty())
        RobotQtClass->setObjectName(QString::fromUtf8("RobotQtClass"));
    RobotQtClass->resize(400, 300);

    retranslateUi(RobotQtClass);

    QMetaObject::connectSlotsByName(RobotQtClass);
    } // setupUi

    void retranslateUi(QWidget *RobotQtClass)
    {
    RobotQtClass->setWindowTitle(QApplication::translate("RobotQtClass", "RobotQt", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(RobotQtClass);
    } // retranslateUi

};

namespace Ui {
    class RobotQtClass: public Ui_RobotQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTQT_H
