/*2. Escriba una función que determine y devuelva si una secuencia
de caracteres de entrada es de la forma A#B#C#D...,
donde A, B, C, D,...son de la forma X&Y, que a su vez están
separados por el caráter ‘#’.*/

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "PilaD.h"
#include "PilaE.h"

#include "Ejercicio1.h"

using namespace std;

bool secCadenaAlm (char *cadAux, int const lCad){
    bool res = 1;

    cout << "Introduce una cadena de caracteres: A#B#C#D..." << endl;
    cin >> cadAux;  //Se supone que llega inicializada como parametro de entrada

    PilaD<char> pila;

    int i = 0;
    int j = 0;
    while(i < lCad &&  res){
                cout << "while 1" << endl;
        while(j < lCad && cadAux[j] != '#'){
                cout << "while 2" << endl;
            pila.push(cadAux[j]);
            cout << "pila = " << pila.tope();
            j++;
        } cout << endl;

        if(cadAux[j] == '#'){
            if(!secCadenaAmp2(pila)) res = 0;
        }else res = 0;
        i++;
    }

    pila.~PilaD();
    return res;
}
