//============================================================================
// Name        : Algo2_Guia1_Ej2.cpp
// Author      : Ramiro
// Version     :
// Copyright   : 
// Description : Verificar si el compilador genera código equivalente para
//				 iterar usando punteros.
//				 Analizar informalmente cómo influye el nivel de optimización
//				 del compilador en la calidad del código generado.
//============================================================================

#include <iostream>





#define MEASURE_WITH_CTIME
//#define MEASURE_WITH_WINDOWS
//#define MEASURE_WITH_CHRONO

#ifdef MEASURE_WITH_CTIME
	#include <ctime>
#endif
#ifdef MEASURE_WITH_WINDOWS
	#include <windows.h>
#endif
#ifdef MEASURE_WITH_CHRONO
	#include <chrono>
#endif

using namespace std;

void usar(char * p);
void usar(char p);

int main() {
	char v[]="Holaaa";

#ifdef MEASURE_WITH_CTIME
	time_t start, finish;
	time(&start);
#endif
#ifdef MEASURE_WITH_WINDOWS
	DWORD dw1 = GetTickCount();
#endif
#ifdef MEASURE_WITH_CHRONO
	auto start_time = std::chrono::high_resolution_clock::now();
#endif

	//---- Program to Analize----//
	for (char *p = v; *p; ++p)
		usar(*p);

#ifdef MEASURE_WITH_CTIME
	time(&finish);
	cout << "Time difference is " << difftime(finish, start) << " seconds"<< endl;
#endif
#ifdef MEASURE_WITH_WINDOWS
	DWORD dw2 = GetTickCount();
	cout<<"Time difference is "<<(dw2-dw1)<<" milliSeconds"<<endl;
#endif
#ifdef MEASURE_WITH_CHRONO
	auto end_time = std::chrono::high_resolution_clock::now();
	auto time = end_time - start_time;
	cout << "Time difference is "<< time/std::chrono::milliseconds(1) << "ms to run" << endl;;
#endif

	//////////////////////////////////////////////////////////////////////////////

#ifdef MEASURE_WITH_CTIME
	time(&start);
#endif
#ifdef MEASURE_WITH_WINDOWS
	dw1 = GetTickCount();
#endif
#ifdef MEASURE_WITH_CHRONO
	start_time = std::chrono::high_resolution_clock::now();
#endif

	//---- Program to Analize----//
	for (int i = 0; v[i]; ++i)
		usar(v[i]);

#ifdef MEASURE_WITH_CTIME
	time(&finish);
	cout << "Time required = " << difftime(finish, start) << " seconds"<< endl;
#endif
#ifdef MEASURE_WITH_WINDOWS
	dw2 = GetTickCount();
	cout<<"Time difference is "<<(dw2-dw1)<<" milliSeconds"<<endl;
#endif
#ifdef MEASURE_WITH_CHRONO
	end_time = std::chrono::high_resolution_clock::now();
	time = end_time - start_time;
	cout << "Time difference is "<< time/std::chrono::milliseconds(1) << "ms to run" << endl;;
#endif
	return 0;
}

void usar(char * p)
{
	cout << *p <<" - "<< sizeof(p) <<endl;
}

void usar(char p)
{
	cout << p <<" - "<< sizeof(p) << endl;
}
