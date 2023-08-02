#include <iostream>

#include "PilaD.h"
#include "ColaD.h"

#include "Ejercicio1.h"

using namespace std;

bool isomorfa(PilaD<int> pila, ColaD<int> cola){
    bool res = 1;
    PilaD<int> pAux;
    ColaD<int> cAux;

    while(!pila.vacia()){
        pAux.push(pila.pop());
    }

    while(!pAux.vacia()){
        cAux.push(pAux.pop());
    }

//Los elementos situados en posiciones pares de la pila coinciden con los situados en posiciones impares de la cola.
    while(res && !cAux.vacia() && !cola.vacia()){
        cola.pop();
        if(cAux.frente() == cola.frente()){
            cola.pop();
            cAux.pop();
            cAux.pop();
        }else res = 0;
    }

    return res;
}
