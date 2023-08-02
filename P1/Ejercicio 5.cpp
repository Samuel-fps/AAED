#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>

#define N 10000000
#define V 6

using namespace std;

/*	EJERCICIO 5
	Escriba un programa que genere 10000000 de permutaciones pseudoaleatorias de los 6
	primeros números naturales e imprima cuántas de ellas están ordenadas.
*/

int main(){
	int iPermutaciones=N, iOrdenados=0;
	int aVector[V] = {1,2,3,4,5,6}, aOrdenado[V] = {1,2,3,4,5,6};
	bool bIguales;
	
	for(int i=0 ; i<iPermutaciones ; i++){
		random_shuffle(aVector, aVector+V); // Vector aleatorio
		
		bIguales = true;
		for(int j=0 ; j<V ; j++)
			if(aVector[j] != aOrdenado[j])
				bIguales=false;
		if(bIguales)
			iOrdenados++;
	}
	cout << "Vectores ordenados:" << iOrdenados  << endl;
	return 0;
}

