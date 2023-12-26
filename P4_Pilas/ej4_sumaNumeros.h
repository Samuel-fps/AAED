/*  EJERCICIO 4
    Implemente una función que dado un fichero de texto, que almacena dos enteros de longitud
    arbitraria en las dos primeras líneas del fichero, lo modifique añadiendo una tercera línea
    que contenga la suma de ambos números.*/

//#ifdef SUMA_NUMEROS_H
//#define SUMA_NUMEROS_H

#include <fstream>
#include <string>
#include "pilaEnla.h"

using namespace std;
    
void sumaNumeros(string nombre_f){
    fstream f(nombre_f); // Abrir el fichero en modo lectura/escritura y
    // asociarlo al flujo f .
    Pila<int> P, Q, R;
    f >> P >> Q; // Extraer de f los números (pilas) P y Q

    // Calcular el resultado en la pila R
    bool acarreo = false; // false = 0 y true = 1
    int suma=0;
    while (!P.vacia() || !Q.vacia()){ // Hasta vaciar las dos pilas
        if(!P.vacia() && !Q.vacia()){ // Ambas pilas no estan vavias
            suma = P.tope() + Q.tope();
            P.pop();
            Q.pop();
        }
        else if(!P.vacia()){ // Aun quedan numeros en P
            suma = P.tope();
            P.pop();
        }
        else if(!Q.vacia()){ // Aun quedan numeros en Q
            suma = Q.tope();
            Q.pop();
        }

        R.push((suma + acarreo) % 9);
        acarreo = suma > 9; // establecemos el acarreo a true(1) o false(0) para el siguiente digito
    }
    if(acarreo){ // Si nos queda acarreo debemos añadir uno a la izquierda del numero
        R.push(acarreo);
    }
    
    f << R;    // Insertar en f el número (pila) R
    f.close(); // Cerrar el fichero asociado a f
}

// OPERADORES NECESARIOS ENTRADA SALIDA

    // Apila en P los valores númericos de los dígitos
    // extraídos del flujo de entrada fe
fstream& operator>>(fstream& fe, Pila<int>& P)
{
    char cifra;
    while (fe.get(cifra) && cifra != '\n') // leer caracteres hasta fin de línea
        P.push(cifra -= '0');              // convierte un dígito en su valor numérico
    return fe;
}
// Inserta en el flujo de salida fs la pila P
fstream &operator<<(fstream &fs, Pila<int> P)
{
    while (!P.vacia())
{
        fs << P.tope();
        P.pop();
    }
    fs << endl;
    return fs;
}

//#endif