#include "polinom.h"
#include "operadores.h"

#include <iostream>

using namespace std;

int main(){
    int op;

    polinomio p1(3), p2(3);

    std::cout << "Grado: " << p1.grado();

    for(int i=0 ; i < p1.grado() ; i++)
        p1.coeficiente(i, i+1);

    printPolinom(p1);

    p1 = p1 + p1;

    printPolinom(p1);
    
    return 0;
}

