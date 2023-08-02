#include <iostream>
#include <stdlib.h>

#include "Ejercicio5.h"

void impInverso (const ListaE<int>& lista, int p){

    while(p > lista.primera()){
        std::cout << lista.elemento(p) << " ";
        p = lista.anterior(p);
    }
    std::cout << lista.elemento(p) << " " << std::endl;

    return;
}

void impNormal (const ListaE<int>& lista, int p){

    while(p < lista.fin()-1){
        std::cout << lista.elemento(p) << " ";
        p = lista.siguiente(p);
    }
    std::cout << lista.elemento(p) << " " << std::endl;

    return;
}
