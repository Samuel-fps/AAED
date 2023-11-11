/* EJERCICIO 3
    Utilizando rand(), escriba una función que genere un número pseudoaleatorio de coma
    flotante y precisión doble en el intervalo continuo [a, b].
*/

#include <cstdlib>
#include <iostream>
#include <ctime>

double genNumero(double a, double b){
    double num = static_cast<double>(rand()) / RAND_MAX;
    return a + num * (b - a);
}

int main(){
    std::srand(std::time(nullptr));
    std::cout << genNumero(1.0,10.0) << std::endl;
    return 0;
}