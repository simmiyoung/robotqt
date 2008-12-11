/*
 * RobotPosition.h
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

#ifndef ROBOTPOSITION_H_
#define ROBOTPOSITION_H_

class RobotPosition {
public:
	RobotPosition();
	RobotPosition(qint16 _x, qint16 _y, qint8 _degree);
	RobotPosition(const RobotPosition &obj);
	virtual ~RobotPosition();

	void set(const RobotPosition &obj);
	void set(qint16 x, qint16 y, qint8 degree);
	qint16 getX() const;
	qint16 getY() const;
	qint8 getDegree() const;

	RobotPosition & operator+(const RobotPosition &obj);
	RobotPosition & operator-(const RobotPosition &obj);
	RobotPosition & operator=(const RobotPosition &obj);

private:
        qint16 x;
        qint16 y;
        qint8 degree;
};

#endif /* ROBOTPOSITION_H_ */
