
//RobotQt - http://robotqt.googlecode.com/

//Packages/Position/Position.cpp

//Revision: $Rev$
//Author: $Author$
//Date: $Date$

#include <iostream>

#include "Position.h"

using namespace std;

Position::~Position()
{
	cout << "Robot Object destructed done!" << endl;
}

void Position::set(Position &obj)
{
	x = obj.x;
	y = obj.y;
	degree = obj.degree;
}

void Position::set(short x, short y, short degree)
{
	this->x = x;
	this->y = y;
	this->degree = degree;
}

short Position::getX() const
{
	return x;
}

short Position::getY() const
{
	return y;
}

short Position::getDegree() const
{
	return degree;
}

Position & Position::operator+(const Position & p2) 
{
	Position* p3 = new Position;
	p3->x = x + p2.x;
	p3->y = y + p2.y;
	p3->degree = degree + p2.degree;

	return *p3;
}

Position & Position::operator-(const Position & p2) 
{
	Position* p3 = new Position;
	p3->x = x - p2.x;
	p3->y = y - p2.y;
	p3->degree = degree - p2.degree;

	return *p3;
}

//Position & Position::operator=(const Position & p2) 
//{
//	this->x = p2.x;
//	this->y = p2.y;
//	this->degree = p2.degree;
//	
//	return *this;
//}