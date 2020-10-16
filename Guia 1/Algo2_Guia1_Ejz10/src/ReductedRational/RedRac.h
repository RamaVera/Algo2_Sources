/*
 * RedRac.h
 *
 *  Created on: 7 oct. 2020
 *      Author: Ramiro
 */

#ifndef REDUCTEDRATIONAL_REDRAC_H_
#define REDUCTEDRATIONAL_REDRAC_H_

class RedRac {
private:
	int num;
	int denum;
	static int getMCD(int,int);
public:
	RedRac();
	RedRac(int,int);
	RedRac(RedRac &&other);
	RedRac(const RedRac &other);

	virtual ~RedRac();

	RedRac& operator=(const RedRac &other);
	RedRac operator*(const RedRac &other);
	RedRac operator/(const RedRac &other);
	RedRac operator-(const RedRac &other);
	RedRac operator+(const RedRac &other);

	void show(void);
	float rr2float(const RedRac);
	double rr2double(const RedRac);

};

#endif /* REDUCTEDRATIONAL_REDRAC_H_ */
