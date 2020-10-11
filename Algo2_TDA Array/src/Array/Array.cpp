/*
 * Array.cpp
 *
 *  Created on: 25 abr. 2020
 *      Author: Ramiro
 */

#include "Array.h"
#include <iostream>

#ifndef NULL
#define NULL 0
#endif
#define MAX_LENGTH 500
//Descripcion: 	Crea un arreglo vacio.
//Precondicion:	No hay argumentos.
//Postcondicion:Arreglo vacio creado.
Array::Array():length(0),pArray(NULL){}

//Descripcion: 	Crea un arreglo definiendo su longitud.
//Precondicion:	Argumento lenght entero.
//Postcondicion:Arreglo creado. Arreglo relleno de ceros
Array::Array(int length){
	if (length >= MAX_LENGTH || length < 0) {
			std::cout << "Enter a valid lenght";
			std::exit(0);
	}
	this->length = length;
	this->pArray = new int[length]{0};
//	for(int i=0; i < this->length; i++ )   // todo esto se suplanta con el {0}
//		this->pArray[i]=0;
}

//Descripcion: 	Crea un arreglo a partir de otro de la clase Array
//Precondicion:	Other no puede cambiarse.
//Postcondicion:Arreglo creado con el mismo contenido de other
Array::Array(const Array &other) {

	this->length = other.length;
	this->pArray = new int[other.length];
	for(int i=0; i < other.length; i++ )
		this->pArray[i]=other.pArray[i];
}


//Descripcion: 	Crea un arreglo a partir un arreglo entre {}
//Precondicion:
//Postcondicion:Arreglo creado con el mismo contenido de other
Array::Array(std::initializer_list<int> l){
	int len=static_cast<int>(l.size());
	this->length = len;
	this->pArray = new int[len];
	for(int i=0; i < len; i++ )
		this->pArray[i]=*(l.begin()+i);
}




//Descripcion: 	Asigna a un arreglo el valor de otro
//Precondicion:	Other no puede cambiarse.
//Postcondicion:Arreglo creado con el mismo contenido de other. No puede apuntar a other
Array& Array::operator= (const Array &other){
	if(other.pArray){
		if(&other!=this) // Comparando direcciones se puede determinar si son el mismo arreglo
		{
			if(other.length!=this->length)
			{
				delete [] this->pArray;
//				this->pArray = new int[other.length];
//				this->length = other.length;
//				for(int i=0; i < other.length; i++ )
//					this->pArray[i]=other.pArray[i];
				Array * aux = new Array(other);
				this->pArray= aux->pArray;
				this->length= aux->length;

			}else
			{
				for(int i=0; i < other.length; i++ )
						this->pArray[i]=other.pArray[i];
			}
		}
	}else{
		delete [] pArray;
		this->pArray =NULL;
		this->length =0;
	}
	return *this;
}

//Descripcion: 	Concatena dos arreglos
//Precondicion:	Tienen que ser del mismo tipo de dato. Other no debe cambiar
//Postcondicion:Debe poder concatenarse
//No puede ser salida por referencia por que eso obliga a que el objeto que retorno o
//bien sea el objeto this o bien sea other y no queremos que ambos cambien su valor, por
//lo que es necesario realiza una copia.

Array Array::operator+(const Array & other) const{
	if(other.pArray || other.length )
	{
		Array aux(other.length + this->length);
		//int * aux = new int[other.length + this->length];
		//for(int i = 0 ; i < this->length ; i++){ aux[i]=this->pArray[i];}
		//for(int i = 0 ; i < other.length ; i++){ aux[i+this->length]=other.pArray[i];}
		//delete [] this->pArray;
		//this->pArray = aux;
		//this->length = other.length + this->length;
		for(int i = 0 ; i < this->length ; i++){ aux.pArray[i]=this->pArray[i];}
		for(int i = 0 ; i < other.length ; i++){ aux.pArray[i+this->length]=other.pArray[i];}
		return aux;
	}
	return *this;

}

//Descripcion: 	Operador igualdad: devuelve verdadero si son iguales termino a termino y viceversa
//Precondicion:	Deben ser dos tipos Array. Si alguno de los arreglos esta vacio devuelve falso
//Postcondicion:Debe poder concatenarse
bool Array::operator==(const Array &other) const{
if(this->length != other.length || this->pArray == NULL || other.pArray==NULL )
	return false;
else{
	for(int i=0 ;i < this->length;i++)
	{
		if(this->pArray[i] != other.pArray[i]) return false;
	}
	return true;
}
}

//Descripcion: 	Operador simililtud: devuelve verdadero si son tienen igual tamaño y viceversa
//Precondicion:	Deben ser dos tipos Array
//Postcondicion:Debe poder concatenarse
bool Array::operator^=(const Array &other) const{
	return (this->length == other.length)? true:false;
}


//Descripcion: 	Operador seleccion por indice
//Precondicion:	Entero positivo
//Postcondicion:Debe poder concatenarse
int& Array::operator [](int index) const{
	if (index >= length || index < 0 || this->pArray == NULL) {
		std::cout << "Array index out of bound, exiting";
		std::exit(0);
	}
	return pArray[index];
}


//Descripcion: Muestra en pantalla el contenido del array
//Precondicion: Si es nulo debe decir que esta vacio
//Postcondicion:
void Array::show(void) const{
	if(this->pArray){
		std::cout<< "El Arreglo contiene : ["<< this->pArray[0];
		for(int i=1;i<this->length;i++){
			std::cout <<", "<<this->pArray[i];
		}
		std::cout<<"]"<<std::endl;
	}else{
		std::cout<< "El Arreglo esta vacio "<<std::endl;
	}

}

//Descripcion: 	Redimensiona un arreglo
//Precondicion: El objeto debe redimensionar si es necesario. Si es menor recorta. Si es mayor paddle de ceros
//Postcondicion:
void Array::resize(int len){
	if(this->length != len){
		int * aux = new int[len]{0};
		int L = (len > this->length)? this->length:len;
		for(int i=0; i < L ; i++){ aux[i]=this->pArray[i];}
		delete [] this->pArray;
		this->pArray=aux;
		this->length=len;
	}
}


//Descripcion: 	Destructor
//Precondicion:
//Postcondicion:Debe liberar la memoria y poner a cero las variables
Array::~Array() {
	// TODO Auto-generated destructor stub
	std::cout<<"Destructor Called"<<std::endl;
	delete[] pArray;
	pArray=NULL;
	length=0;
}

//Descripcion: 	Operador de flujo <<
//Precondicion:
//Postcondicion:
std::ostream & operator<< (std::ostream& os,const Array & arr)
{
	if( arr.length == 0 ){
		os << "[]";
		return os;
	}
	os << "[";
	for(int i=0; i<arr.length-1; ++i){
		os << arr[i] << ",";
	}
	os << arr[arr.length-1];
	os << "]";
	return os;
}


//Descripcion: Carga desde el flujo de entrada hacia el flujo de salida
//Precondicion: el formato debe ser [x,x,x,x,x,x,x] sin espacios y con numeros enteros
//Postcondicion:
std::istream & operator>>(std::istream& is,Array & arr)
{
	Array * aux= new Array(10);
	int number;
	char ch;
	int i;
	if( (is >> ch) && (ch == '[') && (is >> number) ){
		aux->pArray[0]=number;
		for(i=1 ;((is >> ch) && (ch == ',') && (is >> number)); i++ ){
			aux->pArray[i]=number;
			if(i == aux->length-1){
				aux->resize(aux->length+10);
			}
		}
	}
	if ( ch != ']' ){
		delete aux;
	}
	aux->resize(i);
	arr.pArray=aux->pArray;
	arr.length=aux->length;
	return is;
}
