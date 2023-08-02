#include <iostream>
#include <stdlib.h>

#include "Ejercicio4.h"


ListaOrd<int> concatenar (const ListaOrd<int>& l1, const ListaOrd<int>& l2){

    ListaOrd<int> l3(l1);

    for(ListaOrd<int>::posicion i = l2.primera(); i != l2.fin(); i = l2.siguiente(i)){
        l3.insertar(l2.elemento(i));
    }

return l3;
}
