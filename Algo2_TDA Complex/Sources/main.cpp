/*
 * main.cpp
 *
 *  Created on: 5 oct. 2020
 *      Author: Ramiro
 */
#include <iostream>
#include <cstdlib>

#include "Complex.h"

using namespace std;

int main (void)
{
	cout << "Comienzo..." << endl;

	Complex z1(1,1);
	cout << "z1 = "; z1.printComplex();
	Complex z2(2,0,Ctype::pol);
	cout << "z2 = "; z2.printComplex();
	Complex z3;
	cout << "z3 = "; z3.printComplex();
	Complex z4;
	cout << "z4 = "; z4.printComplex();
	Complex z5;
	cout << "z5 = "; z5.printComplex();
	Complex z6;
	cout << "z6 = "; z6.printComplex();

	cout << "Operaciones..." << endl;

	z3=z1+z2;
	cout << "z1 = "; z1.printComplex();
	cout << "z2 = "; z2.printComplex();
	cout << "z3 = "; z3.printComplex();
	cout << "z4 = "; z4.printComplex();
	cout << "z5 = "; z5.printComplex();
	z4=z1-z2;
	cout << "z1 = "; z1.printComplex();
	cout << "z2 = "; z2.printComplex();
	cout << "z3 = "; z3.printComplex();
	cout << "z4 = "; z4.printComplex();
	cout << "z5 = "; z5.printComplex();
	z5=!z1;
	cout << "z1 = "; z1.printComplex();
	cout << "z2 = "; z2.printComplex();
	cout << "z3 = "; z3.printComplex();
	cout << "z4 = "; z4.printComplex();
	cout << "z5 = "; z5.printComplex();
	z6=(z1/z1)*(!z3);
	cout << "z1 = "; z1.printComplex();
	cout << "z2 = "; z2.printComplex();
	cout << "z3 = "; z3.printComplex();
	cout << "z4 = "; z4.printComplex();
	cout << "z5 = "; z5.printComplex();
    cout << "z6 = "; z6.printComplex();

    cin>>z1;
    cout << "z1 = "; z1.printComplex();
	return EXIT_SUCCESS;
}



