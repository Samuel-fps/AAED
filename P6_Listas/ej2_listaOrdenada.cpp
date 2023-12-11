#include <iostream>

#include "listaOrdenada.h"
#include "listaenla.h" // Para tener tipo posicion
#define N 10

int main(){
    ListaOrdenada<int> orderedList;

    for(int i = N ; i > 0 ; i--)
        orderedList.insertar(i);

    Lista<int>::posicion p = orderedList.primera();
    while(p != orderedList.fin()){
        std::cout << orderedList.elemento(p) << " ";
        p = orderedList.siguiente(p);
    }
    std::cout << std::endl;

    return 0;
}