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

//Descripcion: Invoca a _sum_
//Precondicion:
//Postcondicion:
int Array::sum(void)const{
	int accum = 0 , index = 0;
	accum = this->_sum_(index,accum);
	return accum;
}

//Descripcion: Mediante recursividad de cola suma todos los elementos
//Precondicion:
//Postcondicion:
int Array::_sum_(int index,int accum)const{
	if(index < 0 || index > this->length)
		return 0;
	if( index == this->length)
		return accum;
	return this->_sum_(index+1,accum+this->pArray[index]);
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

//Descripcion: Show con argumentos. Invoca a _show_
//Precondicion: debe recibir 1 o menos 1
//Postcondicion:
void Array::show(showType type) const{
	if(this->pArray){
		std::cout<< "El Arreglo contiene : [" ;

		switch(type){
			case showType::ascendent:
				this->_show_(0,type);
			break;
			case showType::descendent:
				this->_show_(this->length-1,type);
			break;
			default:
			break;
		}
		std::cout<<"]"<<std::endl;
	}else{
		std::cout<< "El Arreglo esta vacio "<<std::endl;
	}

}

//Descripcion: Show con argumentos. Mediante recursividad muestra en orden
//ascendente o descenden el arreglo
//Precondicion:
//Postcondicion:
void Array::_show_(const int param,const showType type )const {

	std::cout<<this->pArray[param];

	switch(type)
	{
	case showType::ascendent:
		if(param != this->length -1 )
		{
			std::cout<<", ";
			this->_show_(param+1,type);
		}
		break;
	case showType::descendent:
			if(param != 0)
			{
				std::cout<<", ";
				this->_show_(param-1,type);
			}
		break;
	default:
		break;
	}

}


//Descripcion: 	Redimensiona un arreglo
//Precondicion: El objeto debe redimensionar si es necesario. Si es menor recorta. Si es mayor paddle de ceros
//Postcondicion:
void Array::resize(const int len){
	if(this->length != len){
		int * aux = new int[len]{0};
		int L = (len > this->length)? this->length:len;
		for(int i=0; i < L ; i++){ aux[i]=this->pArray[i];}
		delete [] this->pArray;
		this->pArray=aux;
		this->length=len;
	}
}


//Descripcion: 	Invoca Metodos de Ordenamiento segun type y los inicializa
//Precondicion:
//Postcondicion:
void Array::sort(sortType type){

	switch(type){
	case sortType::bubble:
			this->_bubbleSort_(0,this->length-1);
		break;
	case sortType::insertion:
			this->_insertSort_(0);
		break;
	case sortType::merge:
				this->_mergeSort_(0,this->length-1);
			break;

	default:
		break;
	}
}

//Descripcion: 	Metodo de ordenamiento por burbujeo recursivo.
//maxLen se decrementa a medida que el metodo confirma una posicion
//index1 apunta al primero de los dos elemtnos consecutivos a comparar
//Precondicion: index1 y maxLen se consideran bien inicializados
//Postcondicion: arreglo ordenado
void Array::_bubbleSort_(int index, int maxLen){
	if( maxLen == 0)
		return;
	if( index == maxLen)
		this->_bubbleSort_(0,maxLen-1);
	else
	{
		if( this->pArray[index] > this->pArray[index+1])
			this->swap(index,index+1);
		this->_bubbleSort_(index+1,maxLen);
	}
}


//Descripcion: 	Metodo de ordenamiento por burbujeo recursivo.
//maxLen se decrementa a medida que el metodo confirma una posicion
//index1 apunta al primero de los dos elemtnos consecutivos a comparar
//Precondicion: index1 y maxLen se consideran bien inicializados
//Postcondicion: arreglo ordenado
void Array::_insertSort_(int index){
	int i;
	index++;
	if(index == this->length){return;}
	else{
		for(i = 0; pArray[index]>pArray[i] ; i++ );
		for(int j = index ; j!=i ; j--){ this->swap(j-1,j);}
		this->_insertSort_(index);
	}
}

//Descripcion: 	Intercambia dos elementos del arreglo
//Precondicion: los indices deben estar validados
//Postcondicion:
void Array::swap(const int index1,const int index2){
	if (index1 < 0 || index1 >= this->length || index2 < 0 || index2 >= this->length) return;
	int aux = this->pArray[index1];
	this->pArray[index1]=this->pArray[index2];
	this->pArray[index2]=aux;
}

//Descripcion: 	Metodo de ordenamiento mergesort recursivo.
//Precondicion:
//Postcondicion: arreglo ordenado
void Array::_mergeSort_(int first, int last){

	if( first < last )
	{
		int middle = (first+last)/2;
		//std::cout<< first <<" "<<middle<<" "<<last<<std::endl;
		this->_mergeSort_(first,middle);
		this->_mergeSort_(middle+1,last);
		this->_merge_(first,middle,last);
	}

}
void Array::_merge_(int first,int middle, int last){
	//static int counter=0;
	//std::cout<<"Llamado numero "<<counter++<<" Entre: "<<first<<" y "<< last<<std::endl;

	Array aux(this->length);
	bool reachEnd1 = false, reachEnd2 = false;
	int leftIndex = first;
	int rightIndex = middle+1;
	int endLeft = middle+1;
	int endRight = last +1;
	int auxIndex = first;
	do{
		if( this->pArray[leftIndex] <= this->pArray[rightIndex] ){
			aux.pArray[auxIndex++] = this->pArray[leftIndex++];
		}else{
			aux.pArray[auxIndex++] = this->pArray[rightIndex++ ];
		}
		if(leftIndex == endLeft) 	reachEnd1 = true;
		if(rightIndex == endRight) 	reachEnd2 = true;

	}while(reachEnd1 != true && reachEnd2 != true);

	if ( reachEnd1 ){
		do{
			aux.pArray[auxIndex++] = this->pArray[rightIndex++];
		}while(rightIndex < last);
	}else
	if (reachEnd2){
		do{
			aux.pArray[auxIndex++] = this->pArray[leftIndex++];
		}while(leftIndex < middle);
	}

	for(int i = first ; i < auxIndex ; i++)
	{
		 this->pArray[i]= aux.pArray[i];
	}
	//std::cout<<*(this)<<std::endl;
	//this->_swapArguments_(aux); % Preguntar

}



//Descripcion: 	Destructor
//Precondicion:
//Postcondicion:Debe liberar la memoria y poner a cero las variables
Array::~Array() {
	// TODO Auto-generated destructor stub
	//std::cout<<"Destructor Called"<<std::endl;
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
	int i = 0;
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


void Array::_swapArguments_(Array & other){

	Array aux(*(this));
	this->pArray = other.pArray;
	this->length = other.length;

	other.pArray = aux.pArray;
	other.length = aux.length;



}
