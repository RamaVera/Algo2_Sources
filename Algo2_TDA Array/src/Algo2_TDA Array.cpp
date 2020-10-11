//============================================================================
// Name        : Algo2_TDA.cpp
// Author      : Ramiro
// Version     :
// Copyright   : 
// Description :  Ansi-style
//============================================================================

#include <iostream>
#include "Array.h"
using namespace std;

int main() {

	Array Arr1={5,4,3,2,1};		Arr1.show();
	Array Arr2(10);	 			Arr2.show();
	Array Arr3(5);	 			Arr3.show();
	Array Arr4;		 			Arr4.show();

	Arr3[0] = 1;
	Arr3[1] = 2;
	Arr3[2] = 3;
	Arr3[3] = 4;
	Arr3[4] = 5;				Arr3.show();

	Arr3 = Arr1; 		 		Arr3.show();
	Arr2 = Arr1 + Arr2 + Arr4; 	Arr2.show();
	(Arr3 == Arr1)? (cout<<"Arr3 y Arr1 son iguales"<<endl)   : (cout<<"Arr3 y Arr1 no son iguales"<<endl);
	(Arr2 ^= Arr3)? (cout<<"Arr3 y Arr1 equidistantes"<<endl) : (cout<<"Arr3 y Arr1 no son equidistantes"<<endl);
//	Arr4[4] = 2;				Arr4.show(); Debe tirar error

	Arr2.show();
	Arr2.resize(5);
	Arr2.show();
	Arr2.resize(7);
	Arr2.show();

	cout<< Arr3 <<endl;
	cout<<"Ingrese un arreglo de numeros separados por coma (sin espacios) comenzando por '[' y terminando con ']' " << endl;
	Array Arr5;
	cin >> Arr5;
	cout<< Arr5 <<endl;
	return 0;
}
