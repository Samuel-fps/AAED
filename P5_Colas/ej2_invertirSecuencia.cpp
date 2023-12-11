#include "colaEnla.hpp"
#include "../P4_Pilas/pilaEnla.h"
#include <iostream>

using namespace std;

// Vuelca la pila en la cola
void pilaToCola(Pila<int>& p, Cola<int>& c){
    while(!p.vacia()){ // Vaciar la pila
        c.push(p.tope());
        p.pop();
    }
}

// Si a y b son iguales no se invertira ningún numero
// si b o se encuentra después de a se invierte desde a hasta el final de la cola
Cola<int> invertirSecuencia(Cola<int> cola, int a, int b){
    int elemento;
    Pila<int> pila;
    Cola<int> res;
    bool invertir = false;

    while(!cola.vacia()){
        elemento = cola.frente();
        cola.pop();

        if(elemento == a)
            invertir = true; // Hemos encontrado a
        if(elemento == b){
            invertir = false;
            pila.push(elemento); // Meto b en la pila
            pilaToCola(pila, cola); // vuelco la pila en la cola
        }

        if(invertir) // estoy invirtiendo meto en la pila
            pila.push(elemento);
        else // Si no inviero sigo metiendo en la cola
            res.push(elemento);
    }
    if(invertir) // No hemos encontrado b
        pilaToCola(pila, cola); // vuelco la pila en la cola

    return res;
}

// Vuelca el vector en una cola siendo v[0] el frente de la cola
void vectorToCola(int v[], Cola<int> c, int n){
    for(size_t i=0 ; i < n ; i++)
        c.push(v[i]);
}

// Vuelca la pila en la cola
void printCola(Cola<int> c){
    while(!c.vacia()){ // Vaciar la pila
        cout << c.frente() << " ";
        c.pop();
    }
    cout << endl;
}

int main(){
    int v[] = {4, 7, 8, 9, 9, 1, 8, 6, 7, 9, 6, 2, 4, 8, 9, 3, 2, 1, 0};
    Cola<int> cola;

    vectorToCola(v, cola, sizeof v / sizeof *v);
    printCola(cola);

    invertirSecuencia(cola, 1, 2);

    printCola(cola);

    return 0;
}