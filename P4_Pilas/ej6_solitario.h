#include "pilaEnla.h"

enum Palo {OROS, COPAS, ESPADAS, BASTOS};
enum Figura {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};

typedef struct tCarta {
    Palo palo;
    Figura figura;
};

typedef Pila<tCarta> tMazo;
typedef Pila<tCarta> tBase;
typedef Pila<tCarta> tMonton;

// Pre: Recibe un vector de tCarta con 40 elementos
bool solitario(tCarta cartas[], int n) {
    tMonton mazo, descartes;
    tBase oro, copa, espada, basto;

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
                    if(carta.figura == AS || carta.figura == oro.tope().figura + 1){
                        oro.push(carta);
                        descartes.pop();
                    }            
                    break;
                case COPAS:
                    if(carta.figura == AS || carta.figura == copa.tope().figura + 1){
                        copa.push(carta);
                        descartes.pop();
                    }            
                    break;
                case ESPADAS:
                    if(carta.figura == AS || carta.figura == espada.tope().figura + 1){
                        espada.push(carta);
                        descartes.pop();
                    }            
                    break;
                case BASTOS:
                    if(carta.figura == AS || carta.figura == basto.tope().figura + 1){
                        basto.push(carta);
                        descartes.pop();
                    }            
                    break;
            }
        }
    }
    return true;
}