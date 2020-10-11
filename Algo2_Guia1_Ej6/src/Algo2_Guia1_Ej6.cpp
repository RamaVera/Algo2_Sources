//============================================================================
// Name        : Algo2_Guia1_Ej6.cpp
// Author      : Ramiro
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Array.h"
using namespace std;

int main() {

	Array a(7);
	a[0] = 3;
	a[1] = 6;
	a[2] = a[0] + a[1];
	std::cout << "El numero es :" << a[2] << std::endl;
	Array b = a;
	std::cout << "Tambien es :" << b[2] << std::endl;

	return 0;
}
