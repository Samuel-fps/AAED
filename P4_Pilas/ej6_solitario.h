#include "pilaEnla.h"

enum Palo {OROS, COPAS, ESPADAS, BASTOS};
enum Figura {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};

typedef struct tCarta {
    Palo palo;
    Figura figura;
};

typedef Pila<tCarta> tMazo;
typedef tCarta tBase;
typedef Pila<tCarta> tMonton;

// Pre: Recibe un vector de tCarta con 40 elementos y su longitud
// Post: Devuelve un vector con las de bases con las últimas cartas de cada palo en cada posicion
bool solitario(tCarta cartas[], int n) {
    tMonton mazo, descartes;
    tBase oro, copa, espada, basto;

    tBase* bases = new tBase[4];

    for(int i = 0 ; i < n ; i++)
        mazo.push(cartas[i]);

    while(!mazo.vacia()){
        descartes.push(mazo.tope());
        mazo.pop();
        descartes.push(mazo.tope());
        mazo.pop();
        while(!descartes.vacia()){
            tCarta carta = descartes.tope();
            switch (carta.palo){
                case OROS:
                    if(carta.figura == AS || carta.figura == bases[0].figura + 1){
                        bases[0].figura = carta.figura;
                        descartes.pop();
                    }            
                    break;
                case COPAS:
                    if(carta.figura == AS || carta.figura == bases[1].figura + 1){
                        bases[1].figura = carta.figura;
                        descartes.pop();
                    }            
                    break;
                case ESPADAS:
                    if(carta.figura == AS || carta.figura == bases[2].figura + 1){
                        bases[2].figura = carta.figura;
                        descartes.pop();
                    }            
                    break;
                case BASTOS:
                    if(carta.figura == AS || carta.figura == bases[3].figura + 1){
                        bases[3].figura = carta.figura;
                        descartes.pop();
                    }            
                    break;
            }
        }
    }
    return bases;
}