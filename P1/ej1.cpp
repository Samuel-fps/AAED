/* EJERCICIO 1
    Utilizando rand(), escriba una función que genere un número pseudoaleatorio entero en el
    intervalo discreto [a, b].
*/

#include <cstdlib>
#include <iostream>


int genNumero(int a, int b){
    return a + rand() % (b - a + 1);
}


int main(){
    std::cout << genNumero(2,3) << std::endl;
    
    return 0;
}