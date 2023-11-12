#include "cronometro.h"
#include "ordenacion.h"

#include <iostream>
#include <algorithm>
#include <random>

#define N 20000 // Longitud maxia del ejemplar
#define I 1000 // Incremento

using namespace std;

int main() {
    int v[N], veces=0;
    double t1=0;
    cronometro c;

    // Generaor para el shuffle
    random_device rd;
    mt19937 gen(rd());

    // generar ejemplares de rueba
    for(int i=1000 ; i < N ; i += 1000){
        for(int j = 0 ; j < i ; j++)
            v[j] = j+1;
        veces++;

        shuffle(v, v+i, gen);

        c.activar();
            ordenacion_intercambio(v, v+i);
        c.parar();
        t1 += c.tiempo();
    }
    cout << veces << " Tiempo: " << t1 << endl; 
    t1 = t1/veces; // divido el tiempo entre las veces que se ha ejecutado

    std::cout << "Intercambio tarda " << t1 << " segundos en el caso promedio." << endl;
}