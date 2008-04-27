
//RobotQt - http://robotqt.googlecode.com/

//main.cpp

//Revision: $Rev$
//Author: $Author$
//Date: $Date$

#include <iostream>

#include <QApplication>
#include <QLabel>

using namespace std;

int main(int argc, char *argv[]){
	cout << "RobotQt Loaded" << endl;
	QApplication RobotQtApp(argc, argv);
	QLabel *lblTeste = new QLabel("RobotQt Project is loading...");
	
	lblTeste->show();
	
    return RobotQtApp.exec();
}
