#include <iostream>
#include <stdlib.h>

#include "Ejercicio3.h"


void implista (const ListaCir<int>& lista){ //IMPRIME LISTA CIRCULAR

    ListaCir<int>::posicion i = lista.inipos();
    do{
        std::cout << lista.elemento(i) << " ";
        i = lista.siguiente(i);
    } while (i != lista.inipos());
    std::cout << std::endl;
}

void elim_ocu (ListaCir<int>& l, int x){

    while (l.buscar(x)){
        l.eliminar(l.buscar(x));
    }
}
