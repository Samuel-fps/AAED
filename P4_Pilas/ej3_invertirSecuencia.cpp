/*  EJERCICIO 3
    Escriba una función que dados dos elementos a y b y una pila, invierta la secuencia delimitada por ambos dentro de ella.
    Dado que la pila puede tener elementos repetidos, se invertirá la secuencia delimitada por la primera ocurrencia de a y de b.
*/

#include "PilaEnla.h"

Pila<int> invertirSecuencia(int a, int b, Pila<int> p){
    Pila<int> aux;
    Pila<int> invertida;

    while(!p.vacia()){
        if(p.tope() == a){
            while(p.tope() != b && !p.vacia()){ // Meter la secuencia en una pila para invertirlos
                aux.push(p.tope());
                p.pop();
            }
            while(!aux.vacia()){ // Metemos en la pila solucion los numeros invertidos, ahora la pila está al reves, es decir esta invertida menos el tramo a-b
                invertida.push(aux.tope());
                aux.pop();
            }
        }
        invertida.push(p.tope());
        p.pop();
    }

    // Introducir los numeros reordenados en la pila original
    while(!invertida.vacia()){
        p.push(invertida.tope());
        invertida.pop();
    }
    return p;
}