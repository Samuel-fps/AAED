#include <iostream>
#include <ctime>

#include "ordenacion.hpp"

using namespace std;

#define N 9;

/*	
	EJERCICIO 2
	Realice pruebas de caja negra sobre los algoritmos del ejercicio anterior con las t�cnicas
	explicadas en la pr�ctica 2. Utilice como bater�a de pruebas vectores de n enteros: var�e n
	desde 1 hasta 9 y pruebe todas las permutaciones de cada vector.	
*/

//Muestra todos los elemntros de un vector
void printVect(int v[], int longitud){
	cout << " [ ";
	for(int i=0 ; i<longitud ; i++)
		cout << v[i] << " ";
	cout << "]" << endl;
}

int main(){
	int ordenado[] = {1,2,3,4,5,6,7,8,9};
	int n = N;
	int v[n];
	
	std::copy(ordenado, ordenado + n, v);
	do{
		printVect(v, n);
	}while(next_permutation(v, v+n));
	
	 return 0;
}
