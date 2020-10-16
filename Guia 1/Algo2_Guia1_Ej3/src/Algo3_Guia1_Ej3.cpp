//============================================================================
// Name        : Algo3_Guia1_Ej3.cpp
// Author      : Ramiro
// Version     :
// Copyright   : 
// Description : Arguments Example
//	Escribir un programa que lea caracteres del stream estándar de entrada, cin, y escriba la información
//	codificada por cout. La forma de encriptar un caracter d es
//	e = d ^ key[i];
//	donde key es un string pasado por linea de comando. De ser necesario, el programa deberá usar
//	los caracteres de key en forma cíclica (notar que re-encriptar texto con la misma llave produce el texto
//	original).

//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_ARGUMENTS 2
#define MAX_TEXT_INPUT 100
int checkArguments(int argc ,const char * argv[] );


///////////////////////////////////////////////////////////////////////////
/* 1) Example of Argc and Argv

// Precondition 1 string argument
int main(int argc, char* argv[] )
{
	cout << "Argc : " << argc << endl;

	int length=strlen(argv[argc-1]);
	cout << "Length : " << length << endl;

	for(int i ; i < length ; i++)
		cout <<"Argv ["<< i << "]" << argv[argc-1][i]  << endl;
	return 0;
}
*/
///////////////////////////////////////////////////////////////////////////
//2) Cin as a char
/*
int main(int argc, char* argv[] )
{
	checkArguments(argc,argv);
	int length = strlen(argv[argc-1]);
	char key[length];
	strcpy(key,argv[argc-1]);
	int i;
	while(true)
	{
		char d;
		cin >> d;
		cout <<"La letra ingresada es : "<< d << endl;
		i++ ;
		i = i % length;
		cout <<"El indice es "<< i << endl;
		char e=d ^ key[i];
		cout <<"La codificacion es "<< e << endl;
	}
}
 */

/////////////////////////////////////////////////////////////////////////////
//3) Cin as a string

int main(int argc, const char* argv[] )
{
	checkArguments(argc,argv);
	int length = strlen(argv[argc-1]);
	char key[length];
	strcpy(key,argv[argc-1]);

	char text[MAX_TEXT_INPUT];
	char encriptedText[MAX_TEXT_INPUT];

	cout << "Insert Text: ";
	cin.getline(text, MAX_TEXT_INPUT);

	for(int i = 0,j = 0 ; i < MAX_TEXT_INPUT ; i++,j++)
	{
		j=(j % length);
		encriptedText[i]= text[i] ^ key[j];
	}

	cout << "Encripted Text is:[" << encriptedText << "]"<< endl;
}


int checkArguments(int argc ,const char * argv[] )
{
	if (argc != MAX_ARGUMENTS )
		return 1;
	return 0;
}
