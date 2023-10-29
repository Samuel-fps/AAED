#include <iostream>
#include <cstdlib>

#define N 100

using namespace std;

/*	EJERCICIO 1
	Utilizando rand(), escriba una funci�n que genere un n�mero pseudoaleatorio entero en el
	intervalo discreto [a, b].

	EJERCICIO 2
	Escriba un programa que simule 10 000 000 de tiradas de un dado. Imprima las frecuencias
	relativas que se obtienen para cada una de las caras. Emplee la funci�n del ejercicio anterior
*/

int randomInt(int a, int b){
	return a + rand() % b - a + 1; // Sumamos 1 porque hacemos modulo de a-b nunca se podria dar el valor de b
}

int main(){
	int n=N, i, num;
	float d1=0, d2=0, d3=0, d4=0, d5=0, d6=0;
	
	for(i=0 ; i<n ; i++){
		num = randomInt(1,6);
		switch (num){
			case 1: d1++; break;
			case 2: d2++; break;
			case 3: d3++; break;
			case 4: d4++; break;
			case 5: d5++; break;
			case 6: d6++; break;
		}
	}
	cout << "(1) F: " << d1 << endl;
	cout << "(2) F: " << d2 << endl;
	cout << "(3) F: " << d3 << endl;
	cout << "(4) F: " << d4 << endl;
	cout << "(5) F: " << d5 << endl;
	cout << "(6) F: " << d6 << endl;
}
