#include "colaVec.hpp"

typedef Cola<int> Aerodromo;
typedef enum Codigo {E, S};

void estacionarAvion(Aerodromo& a, Codigo cod, int matricula){
    Aerodromo aux{a.tamaMax()};

    if(cod == E){
        if(a.tama() != a.tamaMax()) // si hay hueco mete el avion
            a.push(matricula);
    }
    else if(cod == S){
        if(!a.vacia()){
            while(!a.vacia()){ // Quitar avion de la cola O(n)
                if(a.frente() != matricula)
                    aux.push(a.frente());
                aux.pop();
            }
            while(aux.vacia()){ // Reconstruir lista sin el avion O(n)
                a.push(aux.frente());
                aux.pop();
            }
        }
    }
    else{
        
    }

}