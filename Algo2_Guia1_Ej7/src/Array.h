/*
 * Array.h
 *
 *  Created on: 25 abr. 2020
 *      Author: Ramiro
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "Complex.h"

class Array {
private:
	unsigned int length;
	Complex * pArray;
public:
	Array();
	Array(unsigned int length);
	Array(const Array &other);
	Complex& operator[](unsigned int index);
	virtual ~Array();

};

#endif /* ARRAY_H_ */
