/*
 * Complex.h
 *
 *  Created on: 5 oct. 2020
 *      Author: Ramiro
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

enum class Ctype{
	rec,
	pol
};

class Complex{
private:
	double real;
	double imag;
	double radius;
	double angle;
	static double* rec2pol(const double rec[]);
	static double* pol2rec(const double pol[]);
public:
	Complex();
	Complex(double r, double i);
	Complex(double r, double i,Ctype type);
	Complex(const Complex & c);
	~Complex();

	void setReal(double r);
	void setImg(double i);
	void setRad(unsigned int r);
	void setAngle(unsigned int a);

	double getReal();
	double getImg();
	double getRad();
	double getAngle();

	Complex operator!(void);
	Complex operator*(const Complex &other);
	Complex operator/(const Complex &other);
	Complex operator-(const Complex &other);
	Complex operator+(const Complex &other);
	Complex& operator=(const Complex &other);

	void printComplex(void);
	friend std::ostream & operator<< (std::ostream& os,const Complex & c);
	friend std::istream & operator>>(std::istream& is,Complex & c);
};

#endif /* COMPLEX_H_ */
