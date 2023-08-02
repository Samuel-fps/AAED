#include <iostream>
#include <algorithm>
#define N 9

using namespace std;
/*
	EJERCICIO 1
	Programe los algoritmos de ordenación por intercambio directo, selección directa e inserción
	directa para vectores de enteros.
*/

//ORDENACION DIRECTA (BURBUJA)
void ordenacionDirecta(int* p, int* f){
	for(int* i=p ; i!=f ; i++){
		for(int* j=p ; j!=f-1 ; j++){
			if(*j > *(j+1))
				swap(*j, *(j+1));
		}
	}
}

void directOrder(int v[], int longitud){
	for(int i=0 ; i<longitud ; i++){
		for(int j=0 ; j<longitud-1 ; j++){
			if(v[j] > v[j+1]){
				swap(v[j], v[j+1]);
			}
		}
	}
}
////7/

//ORDENACION SELECCION DIRECTA
void ordenacionSeleccion(int* p, int* f){
	int* min = p;
	for(int* i=p ; i!=f-1 ; i++){
		int *p = min_element(i, f);
    	swap(*i, *p);
	}
}

//ORDENACION ISERCCION DIRECTA
void ordenacionInserccion(int* p, int* f){
	for(int* i=p ; i!=f ; i++){
		for(int* j=p ; j!=f-1 ; j++){
			if(*i > *(j+1))
				swap(*i, *(j));
		}
	}
}


//Muestra todos los elemntros de un vector
void printVect(int v[], int longitud){
	cout << " [ ";
	for(int i=0 ; i<longitud ; i++)
		cout << v[i] << " ";
	cout << "]" << endl;
}

int main(){
	int v[] = {4,2,5,7,3,1,9,8,6};
	int longitud=N;
	
	printVect(v,N);
	ordenacionInserccion(v, v+N);
	printVect(v,N);
	
	 return 0;
}
