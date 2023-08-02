#include <iostream>
#include <algorithm>
#include <ctime>
#include "cronometro.h"

#define N 10
#define pruebas 1000000

using namespace std;

void intercambio_directo(int*, int*);
void seleccion_directa(int*, int*);
void insercion_directa(int*, int*);

int main (){

    cronometro c;
    int v[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    srand(clock());
    const size_t n = sizeof v / sizeof *v;

    c.activar();
    for (int i = 0; i < pruebas; i++){
        random_shuffle(v, v + n);

/*ELIMINE "//" PARA ESCOGER MÉTODO DE ORDENACIÓN*/
        //intercambio_directo(v, v+N);
        //seleccion_directa(v, v+N);
        //insercion_directa(v, v+N);
/*ELIMINE "//" PARA ESCOGER MÉTODO DE ORDENACIÓN*/
    }
    c.parar();
    double t = c.tiempo();
    cout << (double)t << endl;
    return 0;
}

void intercambio_directo(int* p, int* f)
{
    for (int* i = p; i != f; ++i) {

    for (int* j = p; j != f; ++j){
        if ( *i < *j) {
            swap(*i, *j);
        }
        //cout << *j;
    } //cout << endl;

    }
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

void insercion_directa(int* p, int* f)
{
    for (int* i = p; i != f; ++i) {
        for(int* j = i-1; j >= p; --j){
            //cout << *i << "<?" << *j;
            if(*i < *j) {
                //cout << "  CAMBIA  ";
                swap(*i, *j);
                i--;
            }
            //cout << endl;
        }
    }
}
