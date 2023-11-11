/* EJERCICIO 4
    Escriba un programa que genere 10 000 000 de números pseudoaleatorios de precisión doble
    en el intervalo [0, 1] e imprima la media de los valores y = 4·√(1 − x^2) correspondientes a
    cada número x. Emplee la función del ejercicio anterior.
*/

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

double genNumero(double a, double b){
    double num = static_cast<double>(rand()) / RAND_MAX;
    return a + num * (b - a);
}

int main(){
    srand(time(nullptr));
    int n=10e7;
    double suma=0;

    for(int i=0 ; i < n ; i++)
        suma += 4 * sqrt(1-pow(genNumero(0.0,1.0), 2));
    
    cout << "Media: " << suma/n << endl;

    return 0;
}