#ifndef EJERCICIO6_H_INCLUDED
#define EJERCICIO6_H_INCLUDED

#include "ColaD.h"
#include "ColaE.h"

enum tFigura {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};
enum tPalo {OROS, COPAS, ESPADAS, BASTOS};

typedef struct{
    tFigura f;
    tPalo p;
} tCarta;

typedef ColaD<tCarta> tMonton;

bool solitarioReyes(ColaD<tCarta>& baraja);

#endif // EJERCICIO6_H_INCLUDED
