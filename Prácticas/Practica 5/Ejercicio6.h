#ifndef EJERCICIO6_H_INCLUDED
#define EJERCICIO6_H_INCLUDED

enum tFigura {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};
enum tPalo {OROS, COPAS, ESPADAS, BASTOS};

typedef struct {
    tFigura f;
    tPalo p;
} tCarta;

typedef PilaD<tCarta> tBase;
typedef PilaD<tCarta> tMazo;
typedef PilaD<tCarta> tMonton;

bool solitario(tMazo mazo);

#endif // EJERCICIO6_H_INCLUDED
