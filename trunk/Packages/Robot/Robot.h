
//RobotQt - http://robotqt.googlecode.com/

//Packages/Robot/Robot.h

//Revision: $Rev$
//Author: $Author$
//Date: $Date$

#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include <QString>

class Sensor;
class Motor;
class Position;

class Robot
{
public:
	Robot(Qstring _name, ushort _id = 1) : name( _name ), id( _id );
	~Robot();		 

	QString getName();
	ushort getId();

	ushort getWheelSize();
	void setWheelSize(ushort cm);

	void setMotor(Motor newMotor);
	Motor *getMotor(ushort id);
	void setSensor(Sensor newSensor);
	Sensor *getSensor(ushort id);

private:
	ushort id;
	ushort wheelSize;
	QString name;

	vector<Motor> motorsVector;
	vector<Sensor> sensorsVector;

	Position actualPosition;
};

#endif