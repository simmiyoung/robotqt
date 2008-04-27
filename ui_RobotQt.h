/********************************************************************************
** Form generated from reading ui file 'RobotQt.ui'
**
** Created: Sun Apr 27 01:00:50 2008
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
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionQuit;
    QAction *actionAbout_QT;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout;
    QPushButton *btnTest;
    QSpacerItem *spacerItem;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *hboxLayout1;
    QLabel *lblZuera;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuRobotQt;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->setWindowModality(Qt::ApplicationModal);
    MainWindow->resize(847, 665);
    actionAbout = new QAction(MainWindow);
    actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
    actionAbout->setMenuRole(QAction::AboutRole);
    actionQuit = new QAction(MainWindow);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
    actionQuit->setMenuRole(QAction::QuitRole);
    actionAbout_QT = new QAction(MainWindow);
    actionAbout_QT->setObjectName(QString::fromUtf8("actionAbout_QT"));
    actionAbout_QT->setMenuRole(QAction::AboutQtRole);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    hboxLayout = new QHBoxLayout(centralwidget);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    groupBox = new QGroupBox(centralwidget);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
    groupBox->setSizePolicy(sizePolicy);
    groupBox->setMinimumSize(QSize(200, 550));
    vboxLayout = new QVBoxLayout(groupBox);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    btnTest = new QPushButton(groupBox);
    btnTest->setObjectName(QString::fromUtf8("btnTest"));

    vboxLayout->addWidget(btnTest);


    hboxLayout->addWidget(groupBox);

    spacerItem = new QSpacerItem(51, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setMinimumSize(QSize(550, 550));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    hboxLayout1 = new QHBoxLayout(tab);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    lblZuera = new QLabel(tab);
    lblZuera->setObjectName(QString::fromUtf8("lblZuera"));
    lblZuera->setLayoutDirection(Qt::LeftToRight);

    hboxLayout1->addWidget(lblZuera);

    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    tabWidget->addTab(tab_2, QString());

    hboxLayout->addWidget(tabWidget);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 847, 22));
    menuRobotQt = new QMenu(menubar);
    menuRobotQt->setObjectName(QString::fromUtf8("menuRobotQt"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    menubar->addAction(menuRobotQt->menuAction());
    menuRobotQt->addAction(actionAbout);
    menuRobotQt->addAction(actionAbout_QT);
    menuRobotQt->addSeparator();
    menuRobotQt->addAction(actionQuit);

    retranslateUi(MainWindow);
    QObject::connect(btnTest, SIGNAL(clicked()), lblZuera, SLOT(hide()));

    tabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RobotQt - Robot Simulation", 0, QApplication::UnicodeUTF8));
    actionAbout->setText(QApplication::translate("MainWindow", "About RobotQt", 0, QApplication::UnicodeUTF8));
    actionQuit->setText(QApplication::translate("MainWindow", "Quit RobotQt", 0, QApplication::UnicodeUTF8));
    actionAbout_QT->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("MainWindow", "Robot Addin", 0, QApplication::UnicodeUTF8));
    btnTest->setText(QApplication::translate("MainWindow", "Fa\303\247a o teste ->", 0, QApplication::UnicodeUTF8));
    lblZuera->setText(QApplication::translate("MainWindow", "ISSO \303\211 UM TESTE", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Cenario", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Source Code", 0, QApplication::UnicodeUTF8));
    menuRobotQt->setTitle(QApplication::translate("MainWindow", "RobotQt", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

#endif // UI_ROBOTQT_H
