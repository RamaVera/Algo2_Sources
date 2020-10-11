/*
 * Complex.cpp
 *
 *  Created on: 5 oct. 2020
 *      Author: Ramiro
 */

using namespace std;

#include <cmath>
#include <iostream>

//#define SHOW_MESSAGE   // emite mensaje cuando se llama a constructor o destructor (Comentar para que no emita)

#include "Complex.h"

double* Complex::rec2pol(const double rec[])
{
	double* pol = new double[2];
	pol[0]= sqrt(rec[0]*rec[0] + rec[1]*rec[1]); //pol[0]=radius
	pol[1]= tan(rec[1]/rec[0]);					//pol[1]=angle
	return &pol[0];
}
double* Complex::pol2rec(const double pol[])
{
	double* rec = new double[2];
	rec[0]= pol[0]*cos(pol[1]);		//rec[0]=real
	rec[1]= pol[0]*sin(pol[1]);		//rec[1]=imag
	return &rec[0];
}

//Complex::Complex() {
//	this->real = 0;
//	this->imag = 0;
//	this->radius = 0;
//	this->angle = 0;
//#ifdef SHOW_MESSAGE
//cout << "Constructor por defecto" << endl;
//#endif
//}

Complex::Complex(): real(0),imag(0),radius(0),angle(0){
#ifdef SHOW_MESSAGE
cout << "Constructor por defecto" << endl;
#endif
}
Complex::Complex(double r, double i=0): real(0),imag(0){
	double rec[2]={r,i};
	double* pol = Complex::rec2pol(rec);
//	this->real = r;
//	this->imag = i;
	this->radius = pol[0];
	this->angle = pol[1];
	delete[] pol;
#ifdef SHOW_MESSAGE
	cout << "Constructor por parametros" << endl;
#endif
}
Complex::Complex(double r, double i=0, Ctype type){
	switch(type)
	{
		case Ctype::rec:
		{
			double rec[2] = {r,i};
			double* pol = Complex::rec2pol(rec);
			this->real = r;
			this->imag = i;
			this->radius = pol[0];
			this->angle = pol[1];
			delete[] pol;
		}
		break;
		case Ctype::pol:
		{
			double pol[2] = {r,i};
			double* rec = Complex::pol2rec(pol);
			this->real = rec[0];
			this->imag = rec[1];
			this->radius = r;
			this->angle = i;
			delete[] rec;
		}
		break;
		default:
		#ifdef SHOW_MESSAGE
			cout << "Error, tipo mal elegido" << endl;
		#endif
		break;
	};
#ifdef SHOW_MESSAGE
	cout << "Constructor por parametros 2" << endl;
#endif
}

Complex::Complex(const Complex & c){
	this->real = c.real;
	this->imag = c.imag;
	this->radius = c.radius;
	this->angle = c.angle;
#ifdef SHOW_MESSAGE
	cout << "Constructor por copia" << endl;
#endif
}
Complex::~Complex() {
#ifdef SHOW_MESSAGE
	cout << "Destructor" << endl;
#endif
}

void Complex::setReal(double r){
	this->real= r;
}
void Complex::setImg(double i){
	this->imag= i;
}
void Complex::setRad(unsigned int r){
	this->radius= r;
}
void Complex::setAngle(unsigned int a){
	this->angle= a;
}

double Complex::getReal(){
	return this->real;
}
double Complex::getImg(){
	return this->imag;
}
double Complex::getRad(){
	return this->radius;
}
double Complex::getAngle(){
	return this->angle;
}

Complex& Complex::operator=(const Complex &other){
	this->real = other.real ;
	this->imag = other.imag ;
	this->radius = other.radius;
	this->angle = other.angle;
	return *this;
}

Complex Complex::operator*(const Complex &other){
//	Complex aux;
//	aux.real = this->real * other.real - this->imag * other.imag;
//	aux.imag = this->real * other.imag + this->imag * other.real;
//	double rec[2] = {this->real,this->imag};
//	double* pol = Complex::rec2pol(rec);
//	aux.radius = pol[0];
//	aux.angle = pol[1];
//	delete[] pol;
//	return aux;
	return Complex(this->real * other.real - this->imag * other.imag,this->real * other.imag + this->imag * other.real);
}
Complex Complex::operator/(const Complex &other){
//	Complex aux;
	Complex conjugateOther(other.real,- other.imag);
	Complex num = (*this)*(conjugateOther);
//	Complex(num.real/(other.radius*other.radius),num.imag/(other.radius*other.radius );
//	aux.real = num.real/(other.radius*other.radius);
//	aux.imag = num.imag/(other.radius*other.radius);
//	double rec[2] = {aux.real,aux.imag};
//	double* pol = Complex::rec2pol(rec);
//	aux.radius = pol[0];
//	aux.angle = pol[1];
//	delete[] pol;
//	return aux;
	return Complex(num.real/(other.radius*other.radius),num.imag/(other.radius*other.radius));

}
Complex Complex::operator-(const Complex &other){
//	Complex aux;
//	aux.real = this->real - other.real;
//	aux.imag = this->imag - other.imag;
//	double rec[2] = {this->real,this->imag};
//	double* pol = Complex::rec2pol(rec);
//	aux.radius = pol[0];
//	aux.angle = pol[1];
//	delete[] pol;
//	return aux;
	return Complex(this->real - other.real,this->imag - other.imag);
}
Complex Complex::operator+(const Complex &other){
//	Complex aux;
//	aux.real = this->real + other.real;
//	aux.imag = this->imag + other.imag;
//	double rec[2] = {this->real,this->imag};
//	double* pol = Complex::rec2pol(rec);
//	aux.radius = pol[0];
//	aux.angle = pol[1];
//	delete[] pol;
//	return aux;
	return Complex(this->real + other.real,this->imag + other.imag);
}

Complex Complex::operator!(void){
	Complex aux;
	aux.real =  this->real;
	aux.imag = - this->imag;
	aux.radius = this->radius;
	aux.angle = - this->angle;
	return aux;
}

void Complex::printComplex(void){
	cout<< "( "<< this->real << " , " << this->imag << " ) " << endl;
}
