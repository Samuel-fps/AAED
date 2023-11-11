/* EJERCICIO 2
    Escriba un programa que simule 10 000 000 de tiradas de un dado. Imprima las frecuencias
    relativas que se obtienen para cada una de las caras. Emplee la función del ejercicio anterior.
*/

#include <cstdlib>
#include <iostream>
#include <ctime>

#define N 10e7

int genNumero(int a, int b){
    return a + rand() % (b - a + 1);
}

int main(){
    std::srand(std::time(nullptr));

    int n=N , num;
	float res[6] = {0};
	
	for(int i=0 ; i < n ; i++){
        num = genNumero(1,6);
        res[num-1]++;
	}

    for(int i=0 ; i < 6 ; i++)
        std::cout << "Freceuncia [" << i+1 << "] -> "<< res[i]/n << std::endl;

    return 0;
}