/*  EJERCICIO 3
    Escriba una función que dados dos elementos a y b y una pila, invierta la secuencia delimitada por ambos dentro de ella.
    Dado que la pila puede tener elementos repetidos, se invertirá la secuencia delimitada por
    la primera ocurrencia de a y de b.
*/

#include "PilaEnla.h"

void invertirSecuencia(int a, int b, Pila<int> p){
    Pila<int> aux;
    Pila<int> sol;

    while(!p.vacia()){
        if(p.tope() == a){
            while(!p.vacia() && p.tope() != b){ // Meter la secuencia en una pila para invertirlos
                aux.push(p.tope());
                p.pop();
            }
            while(!aux.vacia()){ // Metemos en la pila solucion los numeros invertidos, ahora la pila está a l reves, es decir esta invertida menos el tramo a-b
                sol.push(aux.tope());
                aux.pop();
            }
        }
        sol.push(p.tope());
        p.pop();
    }

    // Introducir los numeros reordenados en la pila original
    while(!sol.vacia()){
        p.push(sol.tope());
        sol.pop();
    }
}