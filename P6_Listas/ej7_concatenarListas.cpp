#include "listaEnla.h"
#include <iostream>

template <typename T>
Lista<T> concatLista(const Lista<Lista<T>>& l){
    Lista<T> concat;
    Lista<T> lAux;
    typename Lista<Lista<T>>::posicion p = l.primera();
    typename Lista<T>::posicion pAux;

    while(p != l.fin()){
        lAux = l.elemento(p); // Leemos la lista de la lista de listas
        pAux = lAux.primera(); // Inicializamos pAux con la primara posicion de la lista leida

        while(pAux != lAux.fin()){ // Recorremos la lista leida
            concat.insertar(lAux.elemento(pAux), concat.fin());
            pAux = lAux.siguiente(pAux);
        }
        p = l.siguiente(p);
    }

    return concat;
}

int main() {
    // Supongamos que tienes una Lista de Listas de enteros
    Lista<Lista<int>> listaDeListas;

    // Llenamos algunas listas para probar
    Lista<int> lista1, lista2, lista3;

    lista1.insertar(1, lista1.fin());
    lista1.insertar(2, lista1.fin());
    lista1.insertar(3, lista1.fin());

    lista2.insertar(4, lista2.fin());
    lista2.insertar(5, lista2.fin());

    lista3.insertar(6, lista3.fin());
    lista3.insertar(7, lista3.fin());
    lista3.insertar(8, lista3.fin());
    lista3.insertar(9, lista3.fin());

    listaDeListas.insertar(lista1, listaDeListas.fin());
    listaDeListas.insertar(lista2, listaDeListas.fin());
    listaDeListas.insertar(lista3, listaDeListas.fin());

    // Llamamos a la función para concatenar las listas
    Lista<int> listaConcatenada = concatLista(listaDeListas);

    // Imprimimos la lista concatenada
    Lista<int>::posicion pConcatenada = listaConcatenada.primera();

    std::cout << "Lista concatenada: ";
    while (pConcatenada != listaConcatenada.fin()) {
        std::cout << listaConcatenada.elemento(pConcatenada) << " ";
        pConcatenada = listaConcatenada.siguiente(pConcatenada);
    }

    std::cout << std::endl;

    return 0;
}
