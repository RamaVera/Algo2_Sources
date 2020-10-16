//============================================================================
// Name        : Algo2_Guia1_Ej1.cpp
// Author      : Ramiro
// Version     :
// Copyright   : 
// Description : Escribir un programa que imprima los tamaños de los tipos
//				 fundamentales y de varios tipos de punteros, usando el operador
//				 sizeof.
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int Entero;
	float Decimal;
	char Letra;

	Entero =10.1;
	Decimal=10.1;
	Letra='a';


	cout<< Entero << endl;
	cout<< Decimal << endl;
	cout<< Letra << endl;
	cout << "Size of Char :"<< sizeof(char) << endl;
	cout << "Size of Short :"<< sizeof(short) << endl;
	cout << "Size of Int :"<< sizeof(int) << endl;
	cout << "Size of Float :"<< sizeof(float) << endl;
	cout << "Size of Long :"<< sizeof(long) << endl;
	cout << "Size of Double :"<< sizeof(double) << endl;
	return 0;
}
