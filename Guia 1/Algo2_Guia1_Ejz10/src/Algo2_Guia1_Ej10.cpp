//============================================================================
// Name        : Algo2_Guia1_Ej10.cpp
// Author      : Ramiro
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "RedRac.h"
using namespace std;

int main() {

	RedRac n1(5,5);
	RedRac n2(6,3);
	RedRac n3(22,3);
	RedRac n4(1,3);
	n1.show();
	n2.show();
	n3.show();
	n4.show();
	(n1-n2).show();
	(n1+n2).show();
	(n3/n4).show();
	(n3*n2+n4).show();

	return 0;
}
