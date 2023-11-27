#include "colaVec.hpp"
#include "../P4/PilaEnla.h"

#include <iostream>

#define N 5 // Tamaño de la cola

using namespace std;

// devuelve true si la cola y la ila son isomorficas
// devuelve false en caso que no lo sean, o queden elementos sin comprobar en una de ellas
bool isomorfica(Cola<int> C, Pila<int> P){
    P.pop(); // tope = elemento par
    while(!C.vacia() && !P.vacia()){
        cout << C.frente() << " " << P.tope() << endl;
        if(C.frente() != P.tope()) 
            return false; // No son isometricas
        P.pop(); // tope = elemento impar
        P.pop(); // tope = elemento par
        C.pop(); // frente = elemento par
        C.pop(); // frente = elemento impar
    }
    if(!C.vacia() && P.vacia())// || (C.vacia() && !P.vacia()))
        cout << "una de las dos es vacia " << C.frente() << endl; // Quean elementos que no podemos comparar
    return true;
}

int main(){
    Pila<int> pilaIso, pila;
    Cola<int> colaIso(N), cola(N);

    // creamos dos pares de jemplares de prueba uno pasitivo y otro negativo
    for(int i=1 ; i <= N ; i++){
        // ejemplar isomorfico
        colaIso.push(i); // 1, 2, 3, 4, 5
        pilaIso.push(N-i+1); // 0, 1, 2, 3, 4, 5
        // ejemplar no isomorfico
        cola.push(i); // 1, 2, 3, 4, 5
        pila.push(i); // 1, 2, 3, 4, 5
    }
    pilaIso.push(1);


    if(isomorfica(colaIso, pilaIso))
        cout << "Detecta isomorficas." << endl;
    if(!isomorfica(cola, pila))  
        cout << "No da falsos positivos." << endl;
    cout << "Prueba terminada" << endl;
    return 0;
}