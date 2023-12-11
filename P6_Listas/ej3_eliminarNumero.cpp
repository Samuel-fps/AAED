#include "listaEnla.h"
/*  EJERCICIO 3
    Implemente una función que tenga como entrada una lista de enteros y un entero x, de
    forma que devuelva la lista modificada mediante la eliminación de todas las ocurrencias
    de x en la lista.
*/

void eliminarnumero(Lista<int> L, int x){
    Lista<int>::posicion p = L.primera();
    while(p != L.fin()){
        if(L.elemento(p) == x)
            L.eliminar(p);
        else // Si lo elimino no paso al siguiente
            p = L.siguiente(p);
    }
}