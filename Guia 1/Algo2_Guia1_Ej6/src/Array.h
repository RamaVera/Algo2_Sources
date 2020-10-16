/*
 * Array.h
 *
 *  Created on: 25 abr. 2020
 *      Author: Ramiro
 */

#ifndef ARRAY_H_
#define ARRAY_H_

class Array {
public:
	Array();
	Array(unsigned int length);
	Array(const Array &other);
	int& operator[](int);
	virtual ~Array();
private:
	unsigned int length;
	int * pArray;
};

#endif /* ARRAY_H_ */
