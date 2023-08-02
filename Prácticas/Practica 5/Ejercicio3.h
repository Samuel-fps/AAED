/*Escriba una función que dados dos elementos a y b y una pila,
invierta la secuencia delimitada por ambos dentro de ella.
Dado que la pila puede tener elementos repetidos, se invertirá
la secuencia delimitada por la primera ocurrencia de a y de b. */

#ifndef EJERCICIO3_H_INCLUDED
#define EJERCICIO3_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#include "PilaD.h"

//Precondicion: inicio y fin deben pertenecer a pilaO y pilaO debe tener al menos 2 elementos
//Postcondicion: devuelve una pila cuyos elementos entre inicio y fin quedan invertidos, ambos inclusive
template <typename tElemento> PilaD<tElemento> invSecuencia (tElemento inicio, tElemento fin, PilaD<tElemento> pilaO);

template <typename tElemento>
PilaD<tElemento> invSecuencia (tElemento inicio, tElemento fin, PilaD<tElemento> pilaO){
    PilaD<tElemento> pilaAux;
    PilaD<tElemento> pilaF;


    //Recorre la pila origen desde el tope hasta el último elemento (fin) que se quiere invertir
    while(pilaO.tope() != fin){
        pilaF.push(pilaO.pop());
    }

    //Recorre la pila origen desde el último elemento (fin) que se quiere invertir hasta el primero (inicio) y lo guarda en una pila auxiliar
    while(pilaO.tope() != inicio){
        pilaAux.push(pilaO.pop());
    }   pilaAux.push(pilaO.pop()); //Se hace una vez extra para guardar el primer elemento (inicio) que se quiere invertir

    //Introduce los elementos invertidos en la pila final
    while(!pilaAux.vacia()){
        pilaF.push(pilaAux.pop());
    }

    //Recorre la pila origen desde el primer elemento (inicio) que se quiere invertir hasta el final de la pila
    while(!pilaO.vacia()){
        pilaF.push(pilaO.pop());
    }

    //Como todos los elementos de la pila final están invertidos se guardan en la pila origen
    //para que recuperen su orden original pero con los elementos marcados invertidos
    while(!pilaF.vacia()){
        std::cout << pilaF.tope() << " ";
        pilaO.push(pilaF.pop());
    }std::cout << std::endl;

    pilaAux.~PilaD();
    pilaF.~PilaD();

    return pilaO;
}

#endif // EJERCICIO3_H_INCLUDED
