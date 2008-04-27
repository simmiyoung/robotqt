
//RobotQt - http://robotqt.googlecode.com/

//Packages/Robot/Robot.h

//Revision: $Rev$
//Author: $Author$
//Date: $Date$

#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include <string>
#include <iostream>

typedef unsigned short int USINT;
using namespace std;

class Robot {
    public:
		//constructor
		Robot(string Name, USINT Id = 1);
        
		//robot characteristics
		string getName();
        USINT getId();
        
		USINT getWheelSize();
        void setWheelSize(USINT cm);
		
		//robot addins
		void setMotor(Motor NewMotor);
        Motor *getMotor(USINT Id);
        void setSensor(Sensor NewSensor);
        Sensor *getSensor(USINT Id);
		
		//destructor
		~Robot();

    private:
        USINT Id;
        USINT WheelSize;
        string Name;
        
        vector<Motor> MotorsVector;
        vector<Sensor> SensorsVector;

        //unsigned short int Degree;
        //short int posX;
        //short int posY;
};

#endif
