#include <iostream>
#include <ctime>
#include <cstring>
#include <algorithm>

#include "ordenacion.hpp"

using namespace std;

#define N 3

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

bool prueba_ordena(int v[], int ordenado[], int longitud){
	int aux[longitud];

	for (unsigned i = 0; i < longitud; ++i) {
		aux[i ] = v[i ]; 
	}

	//intercambio(v, v + longitud);
	//seleccion(aux, aux + longitud);
	insercion(v, v + longitud);
	cout << "Prueba: ";
	printVect(aux, longitud);
	return (memcmp(aux, ordenado, longitud) == 0);
}

int main(){
	int ordenado[N],
		v[N],
		n = N;
	bool cont;

	for(int i = 1 ; i <= n ; i++){
		v[i-1] = i-1;
		//printVect(v, i);
		memcpy(ordenado, v, sizeof v);
		cout << "Permutaciones:" << endl;
		cont = true;
		do{
			printVect(v, i);
			if(!prueba_ordena(v, ordenado, i)){
				cout << "ERROR" << endl;
				printVect(v, i);
				printVect(ordenado, i);
				return 1;
			}
		}while(next_permutation(v, v+i));
	}
	
	cout << "Todo correcto";

	 return 0;
}
