#ifndef EJERCICIO1_H_INCLUDED
#define EJERCICIO1_H_INCLUDED

//Precondicion: cadAux está inicializada y lCad contiene la longitud de cadAux
//Postcondicion: devuelve 1 si hay una cadena del tipo X&Y, 0 en caso contrario
bool secCadenaAmp (char *cadAux, int const lCad);

//Precondicion: p es una pila de tipo char no vacía
//Postcondicion: devuelve 1 si hay una cadena del tipo A#B#C#D, 0 en caso contrario
bool secCadenaAmp2 (PilaD<char>& p);

#endif // EJERCICIO1_H_INCLUDED
