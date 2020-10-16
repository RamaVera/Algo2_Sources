/*
 * Foo.h
 *
 *  Created on: 7 oct. 2020
 *      Author: Ramiro
 */

#ifndef FOO_FOO_H_
#define FOO_FOO_H_


class Foo {
public:

	Foo();
	Foo( const Foo & );
	~Foo();
	Foo const &operator=(Foo const &f);
};


#endif /* FOO_FOO_H_ */
