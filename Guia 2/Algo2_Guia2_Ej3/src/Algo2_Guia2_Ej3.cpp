//============================================================================
// Name        : Algo2_Guia2_Ej3.cpp
// Author      : Ramiro
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int det(int ** pMatrix, int size);
int ** eliminarFila1Columna(int ** outMatrix,int ** inMatrix,int i, int size);
void mostrarMatriz(int ** pMatrix, int size);
int ** getMatrix(int * pSize);

int main() {
	int size;
	int** matrix = getMatrix(&size);
	mostrarMatriz(matrix,size);

	int detValue = det(matrix,size);

	for (int i = 0; i < size ; ++i)
		delete [] matrix[i];
	delete [] matrix;

	cout << "El determinantes es :" << detValue << endl; // prints
	return 0;
}

//************************************************************//

int det(int ** pMatrix , int size)
{
	int detValue;
	int cof;
	if(size == 2)
		return (pMatrix[0][0]*pMatrix[1][1]-pMatrix[1][0]*pMatrix[0][1]);
	else{
		int det_aux = 0;
		for(int i =0 ; i < size; i++){

			int** auxMatrix = new int*[size-1];
			for (int j = 0; j < size-1; ++j){auxMatrix[j] = new int[size-1];}

			detValue = det(eliminarFila1Columna(auxMatrix,pMatrix,i,size), size -1);
			cof = pow(-1,i);
			cout<<"Determinantes: "<<detValue<<endl;
			cout<<"Cofactor : "<<cof<<endl;
			//det_aux += pow(-1,i)*det(eliminarFila1Columna(auxMatrix,pMatrix,i,size), size -1);
			det_aux += pMatrix[0][i]*cof*detValue;

			for (int i = 0; i < size-1 ; ++i)
			    delete [] auxMatrix[i];
			delete [] auxMatrix;
		}
		return det_aux;
	}
}

int ** eliminarFila1Columna(int ** outMatrix,int ** inMatrix,int k,int size ){

	int m =0, n=0;
	for(int i = 0 ; i < size ; i++){
		for(int j = 0; j < size ; j++){
			if(i == 0 || j == k) continue;
			else{
				if(n<size-1){
					outMatrix[m][n++]=inMatrix[i][j];
				}else{
					n=0;
					outMatrix[++m][n++]=inMatrix[i][j];
				}
			}
		}
	}
	mostrarMatriz(outMatrix,size-1);
	return outMatrix;
}

void mostrarMatriz(int ** pMatrix, int size){
	cout<<"--------------------"<<endl;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(j==0) cout<<"|";
			if(j==size-1)
				cout<< pMatrix[i][j]<<"|"<<endl;
			else
				cout<< pMatrix[i][j]<<", ";
		}

	}
}

int ** getMatrix(int * pSize){
	int size;
	int num;
	cout<<"Ingresar dimension de matriz nxn"<<endl;
	cin>>size;

	int** matrix = new int*[size];
	for(int i = 0; i < size; ++i)
	    matrix[i] = new int[size];

	for(int i=0;i<size;i++) {
	    for(int j=0;j<size;j++) {
	        cout<<"Enter the "<<i+1<<"*"<<j+1<<" entry :";
	        cin>>num;
			matrix[i][j]=(int)num;
	    }
	}
	*(pSize)=size;

	return matrix;
}
