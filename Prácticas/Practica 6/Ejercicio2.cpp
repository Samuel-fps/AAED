#include <iostream>
#include <stdlib.h>

#include "PilaD.h"
#include "ColaD.h"

#include "Ejercicio2.h"

using namespace std;

ColaD<int> invSecuencia (ColaD<int> cola, int inicio, int fin){
    ColaD<int> cAux;
    PilaD<int> pSec;

    while(cola.frente() != inicio && !cola.vacia()){
        cAux.push(cola.frente());
        cola.pop();
    }

    while(cola.frente() != fin && !cola.vacia()){
        pSec.push(cola.frente());
        cola.pop();
    } pSec.push(cola.frente());
        cola.pop(); //Un pop extra para mover el elemento fin

    while(!pSec.vacia()){
        cAux.push(pSec.pop());
    }

    while(!cola.vacia()){
        cAux.push(cola.frente());
        cola.pop();
    }

    while(!cAux.vacia()){
        cola.push(cAux.frente());
        cAux.pop();
    }

    cAux.~ColaD();
    return cola;
}
