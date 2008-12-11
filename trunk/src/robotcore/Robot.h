/*
 * Robot.cpp
 * RobotQt - Robot Simulation
 *
 * Created by Felipe Tonello on 2008-12-10.
 * Copyright 2008 Felipe Ferreri Tonello. All rights reserved.
 * http://robotqt.googlecode.com/
 *
 * Revision: $Rev$
 * Author: $Author$
 * Date: $Date$
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <qstring.h>
#include <qlist.h>

class Motor;
class Sensor;
class RobotPosition;

class Robot {
public:
	Robot(QString _name, qint8 _id);
	virtual ~Robot();

	QString getName() const;
	qint8 getId() const;

	qint8 getWheelSize() const;
	void setWheelSize(qint8 cm);

	void setMotor(Motor *newMotor);
	Motor * getMotor(qint8 _id) const;
	void setSensor(Sensor *newSensor);
	Sensor * getSensor(qint8 _id) const;

	//TODO set position functions

private:
	qint8 id;
	qint8 wheelSize;
	QString name;

	QList<Motor *> motorList;
	QList<Sensor *> sensorList;

	RobotPosition actualPosition;
};

#endif /* ROBOT_H_ */
