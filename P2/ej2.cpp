// Ejercicio 2 Prueba caja negra de algoritmos de ordenación

#include <iostream>
#include <cstring>
#include <algorithm>

#include "ordenacion.h"

#define N 5 // Tamann maximo de la prueba

using namespace std;

bool prueba_ordena(int v[], int o[], unsigned n, int nAlgoritmo);

int main(){
    int v[N];
    int o[N];
    int nAlgoritmo=3;

    // Generar el vector
    for(int n=1 ; n <= N ; n++){
        v[n-1] = n - 1;
        memcpy(o, v, sizeof v);
        
        // Generar todas las permutaciones
        do {
            if(!prueba_ordena(v, o, n, nAlgoritmo)){} // Comprobar si está bien ordenada
                //return 1; // no son iguales
        } while(std::next_permutation(v, v+n));
    }
    cout << "Funciona correctamente." << endl;
}

bool prueba_ordena(int v[], int o[], unsigned n, int nAlgoritmo){
    int copia[N];

    for(unsigned i=0 ; i < n ; i++)
        copia[i] = v[i];
    switch(nAlgoritmo){ // Llamar al algoritmo elegido
        case 1: ordenacion_intercambio(copia, copia+n);   break;
        case 2: ordenacion_seleccion(copia, copia+n);     break;
        case 3: ordenacion_insercion(copia, copia+n);     break;
        default: std::cout << "El numero de algoritmo no es valido (numeros validos 1, 2, 3)";
    }
    return (memcmp(copia, o, n) == 0);
}

/*
void ordenacion_intercambio(int* p, int* f);
void ordenacion_seleccion(int* p, int* f);
void ordenacion_insercion(int* p, int* f);
*/