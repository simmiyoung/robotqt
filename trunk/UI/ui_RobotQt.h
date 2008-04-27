/********************************************************************************
** Form generated from reading ui file 'RobotQt.ui'
**
** Created: Sat Apr 26 18:35:26 2008
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ROBOTQT_H
#define UI_ROBOTQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionQuit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuRobotQt;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(801, 572);
    actionAbout = new QAction(MainWindow);
    actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
    actionQuit = new QAction(MainWindow);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
    actionQuit->setMenuRole(QAction::QuitRole);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 801, 22));
    menuRobotQt = new QMenu(menubar);
    menuRobotQt->setObjectName(QString::fromUtf8("menuRobotQt"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    menubar->addAction(menuRobotQt->menuAction());
    menuRobotQt->addAction(actionAbout);
    menuRobotQt->addSeparator();
    menuRobotQt->addAction(actionQuit);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionAbout->setText(QApplication::translate("MainWindow", "About RobotQt", 0, QApplication::UnicodeUTF8));
    actionQuit->setText(QApplication::translate("MainWindow", "Quit RobotQt", 0, QApplication::UnicodeUTF8));
    menuRobotQt->setTitle(QApplication::translate("MainWindow", "RobotQt", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

#endif // UI_ROBOTQT_H
