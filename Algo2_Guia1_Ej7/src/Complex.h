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

	double getReal()  const;
	double getImg()   const;
	double getRad()   const;
	double getAngle() const;

	Complex operator!(void);
	Complex operator*(const Complex &other) const;
	Complex operator/(const Complex &other) const;
	Complex operator-(const Complex &other) const;
	Complex operator+(const Complex &other) const;
	Complex& operator=(const Complex &other)const;

	void printComplex(void);
};

#endif /* COMPLEX_H_ */
