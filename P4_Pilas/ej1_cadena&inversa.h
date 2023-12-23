#include "PilaVec.h"

#include <iostream>
#include <cstring>
#include <vector>

/*	EJERCICIO 1
	Escriba una función que determine y devuelva si una secuencia de caracteres de entrada
    es de la forma X&Y , donde X es una cadena de caracteres e Y es la cadena inversa,
    separadas por el carácter ‘&’.
*/

// Devuelve TRUE --> cadena&anedac
// Devuelve FALSE --> Cualquier otra cadena (cad&cadena, davwve)
bool XandY(char cad[]){
    size_t len = strlen(cad);
    Pila<char> pila((len-1)/2);
    int i=0;

    while(cad[i] != '&' && !pila.llena()) // Meter la primera cadena en la pila
        pila.push(cad[i++]);
    if(cad[i] != '&') // Se ha llenado la pila sin llegar a & --> Las cadena x e Y no son del mismo tamaño
        return false;
    i++; // Para pasar el caracter &

    while(i < len && !pila.vacia()){
        if(cad[i] != pila.tope()) // Comprobamos si son iguales
            return false;
        pila.pop();
        i++;
    }
    return true;
}

