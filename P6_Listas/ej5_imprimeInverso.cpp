/*  EJERCICIO 5
    Implemente una función ImprimeInverso() que imprima los elementos de una lista simple-
    mente enlazada de enteros en orden inverso a partir de la posición p.
*/

#include "listaEnla.h"
#include "../P4_Pilas/pilaEnla.h"

template <typename T>
void ImprimeInverso(const Lista<T> l, Lista<T>::posicion p) {
    Pila<T> aux;
    bool invertir = false;

    Lista<T>::posicion i = l.primera();
    while(i != l.fin()){
        if(i == p)
            invertir = true;
        if(invertir)
            aux.push(elemento(i));
        i = l.siguiente(i);
    }

    while(!aux.vacia()){
        std::cout << aux.tope() << " ";
        aux.pop();
    }
}
