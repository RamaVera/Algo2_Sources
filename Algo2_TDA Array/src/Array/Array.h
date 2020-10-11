/*
 * Array.h
 *
 *  Created on: 25 abr. 2020
 *      Author: Ramiro
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#include <initializer_list>
#include <iostream>

class Array {
private:
	int length;
	int * pArray;
public:
	~Array();
	Array();
	Array(int length);
	Array(const Array &other);
	Array(std::initializer_list<int> l);

	Array& operator=(const Array &other);
	Array operator+(const Array & other) const;
	bool operator==(const Array &other)	const;
	bool operator^=(const Array &other) const;
	int& operator[](int index) const;

	int size(void){return this->length;};
	void show(void)const;
	void resize(int);

	friend std::ostream & operator<<(std::ostream& os,const Array & arr);
	friend std::istream & operator>>(std::istream& is,Array & arr); //TODO
};
#endif /* ARRAY_H_ */
