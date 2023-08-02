/*1. Escriba una función que determine y devuelva si una secuencia de caracteres de
entrada es de la forma X&Y, donde X es una cadena de caracteres e Y es la cadena
inversa, separadas por el carácter ‘&’.*/

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "PilaD.h"
#include "PilaE.h"

using namespace std;

bool secCadenaAmp (char *cadAux, int const lCad){
    bool res = 1;

    //cout << "Introduce una cadena de caracteres: X&Y" << endl;
    //cin >> cadAux;  //Se supone que llega inicializada como parametro de entrada

    PilaD<char> pila1;
    PilaD<char> pila2;

    int i = 0;
    while(i <= (lCad-1)/2 && cadAux[i] != '&'){
        pila1.push(cadAux[i]);
        i++;
    }

    if(cadAux[i] == '&' && (i + i) <= lCad){
        int j = i + i;
        while(j >= (i+i-1)/2 && cadAux[j] != '&'){
            pila2.push(cadAux[j]);
            j--;
        }

        i = (lCad/2) + 1;
        while(!pila1.vacia() && !pila2.vacia() && res != 0){
            if(pila1.pop() != pila2.pop()) res = 0;
            i++;
        }
    } else res = 0;

    pila1.~PilaD();
    pila2.~PilaD();
    return res;
}

bool secCadenaAmp2 (PilaD<char> &pila){
    bool res = 1;

    std::vector<char> cadAux;

    int i = 0;
    while(!pila.vacia()){
            cout << pila.tope() << " ";
        cadAux.resize(cadAux.size() + 1);
        cadAux[i] = pila.pop();
        i++;
    } cout << endl;
    int lCad = cadAux.size();

    //cout << "Introduce una cadena de caracteres: X&Y" << endl;
    //cin >> cadAux;  //Se supone que llega inicializada como parametro de entrada

    PilaD<char> pila1;
    PilaD<char> pila2;

    i = 0;
    while(i <= (lCad-1)/2 && cadAux[i] != '&'){
        pila1.push(cadAux[i]);
        i++;
    }

    if(cadAux[i] == '&' && (i + i) <= lCad){
        int j = i + i;
        while(j >= (i+i-1)/2 && cadAux[j] != '&'){
            pila2.push(cadAux[j]);
            j--;
        }

        i = (lCad/2) + 1;
        while(!pila1.vacia() && !pila2.vacia() && res != 0){
            if(pila1.pop() != pila2.pop()) res = 0;
            i++;
        }
    } else res = 0;

    pila1.~PilaD();
    pila2.~PilaD();
    return res;
}
