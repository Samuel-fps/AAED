#include "polinomio.h"

#include <iostream>

using namespace std;

int main(){
    int op;

    polinomio p1(10), p2(10);
    p1.coeficiente(3, 5); // 5x³
    p1.coeficiente(0, 3); // + 3

    p2.coeficiente(5, 6); // 6x⁵
    p2.coeficiente(1, 2); // + 2x

    std::cout << "Grado: " << p1.grado() << endl;
/*
    for(int i=0 ; i < p1.grado() ; i++)
        p1.coeficiente(i, i+1);
*/
    printPolinom(p1);

    // p1 = p1 * p1;
    p1 = p1/p1;

    printPolinom(p1);
    
    return 0;
}

