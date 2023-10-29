// Ejercicio 2 Prueba caja negra de algoritmos de ordenación

#include <iostream>
#include <cstring>
#include <algorithm>

#include "ordenacion.h"

#define N 5 // Tamann maximo de la prueba

using namespace std;

bool prueba_ordena(int);

int main(){
    if(prueba_ordena(2))
        std::cout << "El orden por intercambio es correcto." << std::endl;
    else
        std::cout << "El orden por intercambio NO es correcto." << std::endl;
    return 0;
}

bool prueba_ordena(int nAlgoritmo){
    int v[N];
    int o[N];

    // Generar el vector
    for(int tam = 1 ; tam <= N ; tam++){
        v[tam-1] = tam-1;
        std::memcpy(o, v, sizeof v);
        // Generar todas las permutaciones
        do {
            switch(nAlgoritmo){ // Llamar al algoritmo elegido
                case 1: ordenacion_intercambio(v, v+tam);   break;
                case 2: cout << "Probando seleccion..."   << endl; ordenacion_seleccion(v, v+tam);     break;
                case 3: cout << "Probando insercion..."   << endl; ordenacion_insercion(v, v+tam);     break;
                default: std::cout << "El numero de algoritmo no es valido (numeros validos 1, 2, 3)";
            }

            std::cout << "[";
            for(int i = 0 ; i < tam ; i++)
                std::cout << o[i] << " ";
            std::cout << "]" << std::endl;

            std::cout << "[";
            for(int i = 0 ; i < tam ; i++)
                std::cout << v[i] << " ";
            std::cout << "]" << tam << std::endl;
            //std::cout << std::memcmp(v, o, tam) << std::endl;

            if(memcmp(v, o, tam)) // Comprobar si está bien ordenada
                return false; // no son iguales
        } while(next_permutation(v, v+tam));
    }
    return true;
}

/*
void ordenacion_intercambio(int* p, int* f);
void ordenacion_seleccion(int* p, int* f);
void ordenacion_insercion(int* p, int* f);
*/