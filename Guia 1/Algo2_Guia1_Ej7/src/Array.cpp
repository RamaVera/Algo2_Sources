/*
 * Array.cpp
 *
 *  Created on: 25 abr. 2020
 *      Author: Ramiro
 */

#include "Array.h"
#include "Complex.h"
#include <iostream>


Array::Array() {
	length = 0;
	pArray = NULL;
}

Array::Array(unsigned int length) {
	this->length = length;
	this->pArray = new Complex[length];
}

Array::Array(const Array &other) {
	this->length = other.length;
	this->pArray = new Complex[other.length];
	for(unsigned int i=0; i < other.length; i++ )
		this->pArray[i]=other.pArray[i];
}

Complex& Array::operator[](unsigned int index)
{
	if (index >=length)
	{
        std::cout << "Array index out of bound, exiting";
        std::exit(0);
    }
    return pArray[index];
}


Array::~Array() {
	delete[] pArray;
}

