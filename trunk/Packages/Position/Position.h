
//RobotQt - http://robotqt.googlecode.com/

//Packages/Position/Position.h

//Revision: $Rev$
//Author: $Author$
//Date: $Date$

#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
Position(): x(0), y(0), degree(0) {};
Position(short _x, short _y, ushort _d) : x( _x ), y( _y ), degree( _d ) {};
Position(const Position& obj);
~Position();

inline void set(Position &obj);
void set(short x, short y, short degree);
short getX() const;
short getY() const;
short getDegree() const;

Position & operator+(const Position &);
Position & operator-(const Position &);
//inline Position & operator=(const Position & p2);

private:
	short x;
	short y;
	ushort degree;
};

#endif
