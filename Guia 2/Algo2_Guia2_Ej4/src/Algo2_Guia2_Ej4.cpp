//============================================================================
// Name        : Algo2_Guia2_Ej4.cpp
// Author      : Ramiro
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

static int mcCarthy(int n)
{
	static int i=0;
	cout<<"Nº: "<<i++<<"Entre con n = "<<n<<endl;

	if (n > 100)
		return n - 10;
	else
		return mcCarthy(mcCarthy(n + 11));
}

int main() {
	mcCarthy(101);
	cout << "Termino" << endl; // prints
	return 0;
}
