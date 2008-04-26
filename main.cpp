
//RobotQt - http://robotqt.googlecode.com/

//main.cpp

//Revision: $Rev$
//Author: $Author$
//Date: $Date$

#include <iostream>

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]){
	std::cout << "RobotQt Loaded" << std::endl;
	QApplication RobotQtApp(argc, argv);
	QLabel *lblTeste = new QLabel("RobotQt Project");
	
	lblTeste->show();
	
    return RobotQtApp.exec();
}
