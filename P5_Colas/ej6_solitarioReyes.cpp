#include "pilaEnla.h"

enum Palo {OROS, COPAS, ESPADAS, BASTOS};
enum Figura {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};

typedef struct {
    Palo palo;
    Figura figura;
} tCarta;