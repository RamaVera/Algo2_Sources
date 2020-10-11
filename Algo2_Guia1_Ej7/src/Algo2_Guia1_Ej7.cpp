//============================================================================
// Name        : Algo2_Guia1_Ej7.cpp
// Author      : Ramiro
// Version     :
// Copyright   : 
// Description : (a) Implementar una clase complejo, definiendo adecuadamente los operadores aritméticos usuales.
//					Escribir un programa que reciba como entrada una secuencia x0 . . . xn−1 de números complejos
//					y calcule e imprima la señal segun la fft-.
//				 (b) Reescribir la clase complejo y usar notación polar para la representación interna de los números.
//				  	Verificar que, a igual entrada, ambos programas producen salidas similares.
//============================================================================

#include "Complex.h"
#include <iostream>
using namespace std;

int main() {
	float real,imag;
	char usrchoice;
	int index=0;
	Complex complexArray[100];
	bool exit=false;
	do
	{
		cout << "Por favor ingrese el numero real " << endl;
		cin >> real;
		cout << "Por favor ingrese el numero complejo  "<< endl;
		cin>> imag ;
		cout<< "z ="
		complexArray[index] = Complex(real,imag);
		complexArray[index].printComplex();
		index++;
		cout << "Desea agregar otro complejo [y/n]?" << endl;
		cin >> usrchoice;
		exit=(usrchoice=='y')?false:true;
	}while(exit == false);

// HACER SUMATORIA FEA ESA...

	return 0;
}
