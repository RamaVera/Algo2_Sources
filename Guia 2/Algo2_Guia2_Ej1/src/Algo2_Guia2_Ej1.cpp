//============================================================================
// Name        : Algo2_Guia2_Ej1.cpp
// Author      : Ramiro
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#define _BSD_SOURCE
using namespace std;


#define N 10000
int sum_of_squares(int n);

#define CODE_3
#ifdef CODE_1
int sumOfSquaresRec(int n);
#endif
#ifdef CODE_2
int sumOfSquaresTailRec(int n, int acum);
#endif
#ifdef CODE_3
int sumOfSquaresIteration(int n);
#endif

int main() {
	struct timeval tval_before, tval_after;

	mingw_gettimeofday(&tval_before, NULL);
	sum_of_squares(N);
	_sleep(1000);
	mingw_gettimeofday(&tval_after, NULL);

	printf("Time elapsed: %ld.%06ld\n", (long int)( tval_after.tv_sec - tval_before.tv_sec), (long int)( tval_after.tv_usec - tval_before.tv_usec));

	return 0;
}


//--------------------------------------------------------------------//

int sum_of_squares(int n){
#ifdef CODE_1
	return sumOfSquaresRec(N);
#endif
#ifdef CODE_2
	return sumOfSquaresTailRec(N, 0);
#endif
#ifdef CODE_3
	return sumOfSquaresIteration(N);
#endif
}

#ifdef CODE_1
int sumOfSquaresRec(int n){
	if(!n) return 0;
	return n*n + sumOfSquaresRec(n-1);
}
#endif
#ifdef CODE_2
int sumOfSquaresTailRec(int n, int acum){
	if(!n) return acum;
	return sumOfSquaresTailRec(n-1,n*n+acum);
}
#endif
#ifdef CODE_3
int sumOfSquaresIteration(int n){
	int acum = 0;
	for(int i = 1 ; i == n ; i++)
	{
		acum = i*i + acum;
	}
	return acum;
}
#endif
