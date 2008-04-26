
//RobotQt - http://robotqt.googlecode.com/

//Packages/Robot/Robot.cpp

//Revision: $Rev$
//Author: $Author$
//Date: $Date$

#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

typedef unsigned short int USINT;

class Robot {
    public:
		//constructors
		Robot(char *Name);
		Robot(char *Name, USINT Id);
        
		//robot characteristics
		char * getName();
        USINT getId();
        
		USINT getRodaSize();
        void setRodaSize(USINT cm);
		
		//robot addins
		void setMotor(Motor motor);
        Motor * getMotor(USINT Id);
        void setSensor(Sensor sensor);
        Motor * getSensor(USINT Id);
		
		//destructor
		~Robot();

    private:
        USINT Id;
        USINT RodaSize;
        char * Name;
        
        vector<Motor> Motors;
        vector<Sensor> Sensors;

        //unsigned short int Degree;
        //short int posX;
        //short int posY;
};

#endif
