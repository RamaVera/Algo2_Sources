//============================================================================
// Name        : Algo2_Guia1_Ej8.cpp
// Author      : Ramiro
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Foo.h"

Foo bar(Foo  A);
using namespace std;

//Observacion: el destructor se llama 3 veces al final.
//Segun lei, las variables creadas se guardan en una memoria LIFO, last in first out
//por ende el orden de destruccion es inverso al de construccion.
//Poniendo ampersand a la funcion bar en la entrada y salida no se vuelven a llamar a los creadores y se aprovecha stack


int main() {
	Foo A; // Se llama al creador normal
	Foo B(A);
	Foo C = A; // Loco pero se llama al constructor por copia y no al metodo de sobrecarga
	bar(A);// Se envia la copia de A a bar
	return 0;
}


Foo bar(Foo A) // Aca se invoca al constructor por copia (no hay un ampersand de referencia)
{
	cout << "foo bar(foo)" << endl;
	return A; // Aca tambien se envia una copia por no haber un Ampersand de referencia
}

