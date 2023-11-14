#include "cronometro.h"
#include "ordenacion.h"

#include <iostream>
#include <algorithm>
#include <fstream> 
#include <random>

#define N 20000 // Longitud maxia del ejemplar
#define I 1000 // Incremento

double calcularTiempo(const int v[], int l, int nAlgoritmo);

int main() {
    int v[N], veces=0;
    double t1=0;

    std::ofstream file1("prueba-1.tmp");
    
    // Generaor para el shuffle
    std::random_device rd;
    std::mt19937 gen(rd());

    // generar ejemplares de rueba
    for(int i = 1000 ; i < N ; i += 1000){
        for(int j = 0 ; j < i ; j++)
            v[j] = j+1;
        veces++;

        std::shuffle(v, v+i, gen);

        t1 += calcularTiempo(v, i, 1);

        file1 << i << " " << t1 / veces << std::endl;
    }

    file1.close();
}

double calcularTiempo(const int v[], int l, int nAlgoritmo){
    int copia[N];
    std::copy(v, v+l, copia);
    cronometro c;
    c.activar();
    switch (nAlgoritmo){
        case 1:
            ordenacion_intercambio(copia, copia+l);
            break;
        case 2:
            ordenacion_insercion(copia, copia+l);
            break;
        case 3:
            ordenacion_seleccion(copia, copia+l);
            break;
    }
    c.parar();
    return c.tiempo();
}
