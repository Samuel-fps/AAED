#include "listaOrdenada.h"

template <typename T>
void mezclarListas(ListaOrdenada<T> l1, ListaOrdenada<T> l2){
    ListaOrdenada<T> res(l1);

    Lista<T>::posicion p = l2.primera();
    while(p != fin()){
        res.insertar(l2.elemento(p));
        p = l2.siguiente(p);
    }

}