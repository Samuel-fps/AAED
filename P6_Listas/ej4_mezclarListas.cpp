/*  EJERCICIO 4
    Dadas dos listas de enteros ordenadas, implemente una función que devuelva una tercera
    lista ordenada con la mezcla de las dos listas de entrada.
*/

#include "listaOrdenada.h"

template <typename T>
ListaOrdenada<T> mezclarListas(const ListaOrdenada<T>& l1, const ListaOrdenada<T>& l2){
    ListaOrdenada<T> res(l1);

    Lista<T>::posicion p = l2.primera();
    while(p != fin()){
        res.insertar(l2.elemento(p));
        p = l2.siguiente(p);
    }
    return res;
}