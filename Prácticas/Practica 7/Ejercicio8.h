#ifndef EJERCICIO8_H_INCLUDED
#define EJERCICIO8_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#include "ListaD.h"

class Binario {
public:
    Binario(const char* cad);

    friend Binario operator ~(Binario bin);
    friend bool operator &(Binario bin, Binario bin2);
    friend bool operator |(Binario bin, Binario bin2);
    friend bool operator ^(Binario bin, Binario bin2);
    friend Binario operator <<(Binario bin, unsigned num);
    friend Binario operator >>(Binario bin, unsigned num);

private:
    ListaD<bool> digitos;
};

#endif // EJERCICIO8_H_INCLUDED
