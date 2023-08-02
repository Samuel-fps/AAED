#include <algorithm>

void intercambio(int* p, int* f){
    for(int* j = f ; j > p ; j--)
        for (int* i = p ; i < j ; i++) 
            if(*i > *(i+1))
                std::swap(*i, *(i+1));
}

void seleccion(int* p, int* f){
    int* min_element;
    for(int* i = p ; i != f ; i++){ // Recorre el vector
        min_element = i;
        for(int* j = i ; j != f ; j++) // Busca el elemento minimo
            if(*j < *min_element)
                min_element = j;
        std::swap(*i, *min_element);
    }
}

void insercion(int* p, int* f){
    for(int* i = p+1 ; i != f ; i++){
        int* j = i;
        while (j != p && *(j - 1) > *j) { // mientras se termine el vector && el elemento de la izquierda sea mayor que ele elemento
            std::swap(*(j - 1), *j);
            j--;
        }
    }
}
