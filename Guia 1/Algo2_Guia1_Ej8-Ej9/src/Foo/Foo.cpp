/*
 * Foo.cpp
 *
 *  Created on: 7 oct. 2020
 *      Author: Ramiro
 */


#include <iostream>
#include "Foo.h"

using namespace std;

Foo::Foo() {
	cout<<"Creador Normal"<<endl;
}

Foo::Foo( const Foo & ) {
	cout<<"Creador por Copia"<<endl;
}

Foo const & Foo::operator=(Foo const &f) {
cout << "foo const &operator=(foo const &)" << endl;
return *this;
}


Foo::~Foo() {
	cout<<"Destructor"<<endl;
}

