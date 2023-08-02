#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#define N 10000000

using namespace std;

/*	EJERCICIO 3
	Utilizando rand(), escriba una función que genere un número pseudoaleatorio de coma
	flotante y precisión doble en el intervalo continuo [a, b].

	EJERCICIO 4
	Escriba un programa que genere 10 000 000 de números pseudoaleatorios de precisión doble
	en el intervalo [0, 1] e imprima la media de los valores y = 4*sqrt(1-pow(x,2)) correspondientes a
	cada número x. Emplee la función del ejercicio anterior.
*/

float randomFloat(int iInferior, int iSuperior);

float randomFloat(int iInferior, int iSuperior){
	return iInferior + static_cast<float>(rand()) * static_cast<float>(iSuperior-iInferior) / RAND_MAX;
}

int main(){
	int iIter=N;
	float fMedia=0;
	
	for(int i ; i<iIter ; i++){
		fMedia += 4 * sqrt(1 - pow(randomFloat(0,1),2));
		//cout << fixed << setprecision(2) << randomFloat(0,1) << endl;
	}
	fMedia = fMedia / iIter;
	cout << "La media es " << fMedia;
	
	return 0;
}
