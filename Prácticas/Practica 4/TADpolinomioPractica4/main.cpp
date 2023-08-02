#include <iostream>
#include <stdlib.h>
#include "polinomAlum.h"
#include "cabecera.h"

using namespace std;


int main()
{
    unsigned gradoMax = 3;
    polinomioAlum pAux(0);
    polinomioAlum p1(gradoMax);
    polinomioAlum p2(gradoMax);
    p1.coeficiente(0, 1);
    p1.coeficiente(1, 2);
    p1.coeficiente(2, 3);
    p1.coeficiente(3, 4);

    p2.coeficiente(0, 10);
    p2.coeficiente(1, 20);
    p2.coeficiente(2, 30);
    p2.coeficiente(3, 40);

    p1.imprime();/*
    p2.imprime();

    cout << endl << endl;

    cout << "p1 + p2 => ";
    pAux = p1 + p2;
    pAux.imprime();

    cout << "p1 - p2 => ";
    pAux = p1 - p2;
    pAux.imprime();

    cout << "p1 * p2 => ";
    pAux = p1 * p2;
    pAux.imprime();

    cout << "p1 += p2 => ";
    pAux = p1;
    pAux += p2;
    pAux.imprime();

    cout << "p1 -= p2 => ";
    pAux = p1;
    pAux -= p2;
    pAux.imprime();

    cout << "p1 *= p2 => ";
    pAux = p1;
    pAux *= p2;
    pAux.imprime();

    cout << "p1 != p2 => ";
    if(p1 != p2) cout << "distintos" << endl;
    else cout << "iguales" << endl;

    cout << "p1 <= p2 => ";
    if(p1 <= p2) cout << "son <=" << endl;
    else cout << "no son <=" << endl;

    cout << "p1 > p2 => ";
    if(p1 > p2) cout << "son >" << endl;
    else cout << "no son >" << endl;

    cout << "p1 >= p2 => ";
    if(p1 >= p2) cout << "son >=" << endl;
    else cout << "no son >=" << endl;
*/
    return 0;
}
