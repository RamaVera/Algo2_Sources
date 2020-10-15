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

enum class showType {
	ascendent,
	descendent
};

enum class sortType {
	bubble,
	merge,
	insertion,
	quick
};

class Array {
private:
	int length;
	int * pArray;

	void _show_(const int,const showType) const;
	int _sum_(int index,int accum) const;
	void _bubbleSort_(int index, int maxLen);
	void _insertSort_(int index);

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

	int sum(void)const;
	int size(void) const {return this->length;};
	void show(void)const;
	void show(const showType) const;
	void resize(const int);
	void swap(const int index1,const int index2);
	void sort(const sortType);

	friend std::ostream & operator<<(std::ostream& os,const Array & arr);
	friend std::istream & operator>>(std::istream& is,Array & arr); //TODO
};
#endif /* ARRAY_H_ */
