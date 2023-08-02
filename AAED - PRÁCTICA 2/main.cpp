#include <iostream>
#include <ctime>

#include "ordenacion.h"

/*	
	EJERCICIO 2
	Realice pruebas de caja negra sobre los algoritmos del ejercicio anterior con las t�cnicas
	explicadas en la pr�ctica 2. Utilice como bater�a de pruebas vectores de n enteros: var�e n
	desde 1 hasta 9 y pruebe todas las permutaciones de cada vector.	
*/

int main(){
	int aVector[] = {1,2,3,4,5,6,7,8,9};
	
	cronometro c;
	for(int i=0 ; i<iPermutaciones ; i++){
		random_shuffle(aVector, aVector+V); // Vector aleatorio
		c.activar();
		
		c.parar();
	}
	return 0;
}
