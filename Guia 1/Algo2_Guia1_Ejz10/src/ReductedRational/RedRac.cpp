/*
 * RedRac.cpp
 *
 *  Created on: 7 oct. 2020
 *      Author: Ramiro
 */
#include <iostream>
#include "RedRac.h"

RedRac::RedRac() {
	this->num=0;
	this->denum=1;
}

RedRac::RedRac(int num,int denum) {
	int mcd=RedRac::getMCD(num,denum);
	this->num = num/mcd;
	this->denum = denum/mcd;
}

RedRac::RedRac(const RedRac &other) {
	this->num=other.num;
	this->denum=other.denum;
}

RedRac::~RedRac() {}

RedRac& RedRac::operator=(const RedRac &other) {
	this->num=other.num;
	this->denum=other.denum;
	return *this;
}

int RedRac::getMCD(int mcd,int aux)
{
	int r;
	do{
		r=mcd%aux;
		mcd=aux;
		aux=r;
	}while(r!=0);
	return mcd;
}

RedRac RedRac::operator*(const RedRac &other){

	return RedRac(this->num*other.num,this->denum*other.denum);
}
RedRac RedRac::operator/(const RedRac &other){

	return RedRac(this->num*other.denum,this->denum*other.num);

}
RedRac RedRac::operator-(const RedRac &other){

	return RedRac(other.denum*this->num - this->denum*other.num ,this->denum*other.denum);
}
RedRac RedRac::operator+(const RedRac &other){

	return RedRac(other.denum*this->num + this->denum*other.num ,this->denum*other.denum);
}

void RedRac::show(void){
	std::cout<<"La fraccion Ingresada es "<<num<<" / "<<denum<<std::endl;
}

float RedRac::rr2float(const RedRac number){
	float aux=number.num/number.denum;
	return aux;
}

double RedRac::rr2double(const RedRac number){
	double aux=number.num/number.denum;
	return aux;

}


