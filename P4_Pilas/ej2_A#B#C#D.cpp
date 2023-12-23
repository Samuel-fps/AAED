/*  EJERCICIO 2
    Escriba una función que determine y devuelva si una secuencia de caracteres de entrada
    es de la forma A#B#C#D..., donde A, B, C, D,... son de la forma X&Y , que a su vez
    están separados por el caráter ‘#’.
*/
#include <string>
#include "pilaEnla.h"
#include "ej1_cadena&inversa.h"

bool cadenasInvertidas(char cad[]){
    char* aux = new char[1];

    for(size_t i = 0; i < strlen(cad) ; i++){
        if(cad[i] != '#')
            aux[i] = cad[i];
        else{
            if(!XandY(aux))
                return false;
            delete[] aux;
            aux = new char[1];  
        }
    }
    delete[] aux;
    return true;
}