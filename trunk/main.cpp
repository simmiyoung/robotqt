
//RobotQt - http://robotqt.googlecode.com/

//main.cpp

//Revision: $Rev$
//Author: $Author$
//Date: $Date$

#include <iostream>

#include "ui_RobotQt.h"

using namespace std;

int main(int argc, char *argv[]){
	QApplication RobotQtApp(argc, argv);
	QMainWindow *RobotQtMainWindow = new QMainWindow;
	Ui::MainWindow MainWindowUI;
	MainWindowUI.setupUi(RobotQtMainWindow);
	
	RobotQtMainWindow->show();

	cout << "RobotQt Loaded" << endl;
	
    return RobotQtApp.exec();
}
