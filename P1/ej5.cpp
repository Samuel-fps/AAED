/* EJERCCIO 5
    Escriba un programa que genere 10 000 000 de permutaciones pseudoaleatorias de los 6
    primeros números naturales e imprima cuántas de ellas están ordenadas.
*/

#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>

bool ordenado(int v[], int n){
    for(int j=0 ; j < n ; j++)
        if(v[j] != j+1)
            return false;
    return true;
}

int main(){
    int v[] = {1, 2, 3, 4, 5, 6},
        iter=10e6, ordenados=0;
    size_t n = sizeof v / sizeof *v; // Tamaño del vector

    std::random_device rd;
    std::mt19937 gen(rd());

    for(int i=0 ; i < iter ; i++){
        std::random_device rd;
        shuffle(v, v+n, gen);
        if(ordenado(v, n))
            ordenados++;
    }

    std::cout << "Se han generado " << static_cast<float>(ordenados)/iter << " vectores ordenados" << std::endl;

    return 0;
}