#include "Position.h"

void Position::Set(Position& obj)
{
	x = obj.x;
	y = obj.y;
	degree = obj.degree;
}

void Position::Set(short& x, short& y, short& degree)
{
	this->x = x;
	this->y = y;
	this->degree = degree;
}

short Position::GetX() const
{
	return x;
}

short Position::GetY() const
{
	return y;
}

short Position::GetDegree() const
{
	return degree;
}

Position & Position::operator+(const Position & p2) 
{
	Position* p3 = new Position;
	p3->x = this->x + p2.x;
	p3->y = this->y + p2.y;
	p3->degree = this->degree + p2.degree;

	return *p3;
}

Position & Position::operator-(const Position & p2) 
{
	Position* p3 = new Position;
	p3->x = this->x - p2.x;
	p3->y = this->y - p2.y;
	p3->degree = this->degree - p2.degree;

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
