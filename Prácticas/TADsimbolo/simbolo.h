#ifndef TADSIMBOLO_H_INCLUDED
#define TADSIMBOLO_H_INCLUDED

#include <cassert>

#include "TADColaDinamica.h"

class Simbolo {
public:
    enum Trazo{Arr, Aba, Izq, Der};

    //Constructor predeterminado

    void insertar(Trazo t);
    void deshacer(unsigned n);

    Simbolo simetriaX();
    Simbolo simetriaY();
    Simbolo simetriaXY();

private:
    Cola<Trazo> trazos;
};

#endif // TADSIMBOLO_H_INCLUDED
