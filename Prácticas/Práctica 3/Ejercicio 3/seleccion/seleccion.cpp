#include <iostream>
#include <algorithm>
#include <ctime>
#include "cronometro.h"

#define pruebas 100000

using namespace std;

void seleccion_directa(int*, int*);

int main (){

    cronometro c;

    for(int n = 1000; n < 20000; n += 1000){
        int v[n];
        int j = 0;
        for(int i = n; i < n + 1000; i++){
            v[j] = i;
            j++;
        }
        c.activar();

        seleccion_directa(v, v+n);

        c.parar();
        double t = c.tiempo();
        cout << (double)t << endl;
    }
    return 0;
}


void seleccion_directa(int* p, int* f)
{
    for (int* i = p; i != f; ++i) {
        int* auxmin = min_element(i, f);
        //cout << *i << " " << *auxmin << endl;
        if (*auxmin < *i) swap(*i, *auxmin);
        //cout << *i << endl;
    }
}
