#include <iostream>
#include <stdlib.h>
#include <string>

#include "ColaE.h"

#include "Ejercicio5.h"

using namespace std;

void aerodromo (ColaE<string> aero, char code, string matricula){
    const unsigned TamAero = 12;
    ColaE<string> cAux(TamAero);

    if(!aero.llena()){
        if(code == 'E'){
            aero.push(matricula);
        } else
            if (code == 'S'){
            while(aero.frente() != matricula && !aero.vacia()){
                cAux.push(aero.frente());
                aero.pop();
            }
            if(aero.vacia()) exit(1);
            else aero.pop();
            while(!cAux.vacia()){
                aero.push(cAux.frente());
                cAux.pop();
            }
        }
    }
}
