#include <iostream>
#include <algorithm>

#define N 10

using namespace std;

void intercambio_directo(int*, int*);
void seleccion_directa(int*, int*);
void insercion_directa(int*, int*);

int main (){
    int v[N] = {4, 2, 3, 1, 7, 9, 8, 5, 6, 0};

    //intercambio_directo(v, v+N);

    //seleccion_directa(v, v+N);

    //insercion_directa(v, v+N);

    for (int i = 0; i < N; i++){
        cout << v[i];
    } cout << endl;


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
