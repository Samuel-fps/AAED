#include <iostream>
#include <algorithm>
#include <ctime>
#include "cronometro.h"

#define pruebas 100000

using namespace std;

void intercambio_directo(int*, int*);

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

        intercambio_directo(v, v+n);

        c.parar();
        double t = c.tiempo();
        cout << (double)t << endl;
    }
    return 0;
}

void intercambio_directo(int* p, int* f)
{
    for (int* i = p; i != f; ++i){

    for (int* j = p; j != f; ++j){
        if ( *i < *j) {
            swap(*i, *j);
        }
        //cout << *j;
    } //cout << endl;

    }
}
