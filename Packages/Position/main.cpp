/*
 ********************************************************************************
 *										*	
 *------ARQUIVO DE TESTE DA CLASSE POSITION					*
 *										*
 *	Para rodar, compile-o junto de Position.h e Position.cpp:		*
 *	(g++ Position.h Position.cpp main.cpp)					*
 *										*	 *										*
 *										*
 ********************************************************************************
 */
 

#include "Position.h"
#include <iostream>

using namespace std;

int main()
{
	short x; short y; short degree;

	Position p1, p2, p3;
	cout << "Informe o valor de p1.x:";
	cin >> x; cin.get();
	
	cout << "Informe o valor de p1.y:";
	cin >> y; cin.get();

	cout << "Informe o valor de p1.degree:";
	cin >> degree; cin.get();

	p1.Set(x,y,degree);
	cout << endl << "P1(" << p1.GetX() << ", " << p1.GetY() << ", " << p1.GetDegree() << "° )" << endl << endl ;

	cout << "p2 = p1" << endl;
	p2 = p1;
	cout << "P2(" << p2.GetX() << ", " << p2.GetY() << ", " << p2.GetDegree() << "° )" << endl << endl ;

	x = 10;
	y = 10;
	degree = 10;
	p3.Set(x,y,degree);

	cout << "p2 = p2 + p3" << endl;
	p2 = p2 + p3;
	cout << "P2(" << p2.GetX() << ", " << p2.GetY() << ", " << p2.GetDegree() << "° )" << endl << endl ;
	
	cout << "p2 = p2 - p1" << endl;
	p2 = p2 - p1;
	cout << "P2(" << p2.GetX() << ", " << p2.GetY() << ", " << p2.GetDegree() << "° )" << endl << endl ;

	return 0;
}
