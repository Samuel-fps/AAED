#include <iostream>
#include <vector>
#include <stdlib.h>

#include "PilaD.h"
//#include "PilaE.h"

#include "Ejercicio6.h"

using namespace std;

bool solitario(tMazo mazo){

    //En todo momento sólo es accesible la carta situada en la parte superior de cada uno de los elementos del juego.
    tCarta* mano = new tCarta[2];
    tBase oros, copas, espadas, bastos; // Cuatro, una por palo, en las que se van colocando las cartas (boca arriba) de cada palo, en orden creciente.
    tMonton monton; // Contiene las cartas (boca arriba) en proceso de colocación.

    /*Se van tomando las cartas del mazo, por parejas,
    y se van colocando en el montón de descartes,
    de forma que la carta extraída en primer lugar
    quede por debajo de la segunda en el montón de
    descartes (es decir, que la pareja que se saca
    se le da la vuelta, quedando invertido su orden).
    Si el número de cartas del mazo es impar,
    en la última extracción sólo se tomará una carta.*/
    bool fin;
    do{
        fin = 1;
        int i = 0;
        while(i < 2 && !mazo.vacia()){
            mano[i] = mazo.pop();
            i++;
        }

        monton.push(mano[0]);
        monton.push(mano[1]);

    /*Tras llevar dos cartas al montón de descartes,
    se accede a la carta de la cima de este montón
    (la de arriba) y se intenta colocar sobre la
    base que le corresponda. Se continúa pasando
    cartas del montón de descartes a sus bases
    correspondientes mientras sea posible. En este
    instante, se vuelven a extraer dos cartas del
    mazo y a llevarlas al montón de descartes,
    iniciándose de nuevo el ciclo.*/

        bool colocar = 1;
        while(!monton.vacia() && colocar){
            tCarta cAux = monton.tope();
            switch(monton.tope().p){
            case OROS:
                if(oros.vacia() && cAux.f == AS) {
                        oros.push(monton.pop()); //Evidentemente, al comienzo del juego las bases estarán vacías y sólo podrán colocarse los ases, en caso de que las extracciones del mazo así lo permitan.
                        fin = 0;
                }
                else { if(!oros.vacia() && oros.tope().f + 1 == cAux.f) {
                        oros.push(monton.pop());
                        fin = 0;
                }
                        else colocar = 0;
                }
                break;
            case COPAS:
                if(copas.vacia() && cAux.f == AS) {
                        copas.push(monton.pop());
                        fin = 0;
                }
                else { if(!copas.vacia() && copas.tope().f + 1 == cAux.f) {
                        copas.push(monton.pop());
                        fin = 0;
                }
                        else colocar = 0;
                }
                break;
            case ESPADAS:
                if(espadas.vacia() && cAux.f == AS) {
                        espadas.push(monton.pop());
                        fin = 0;
                }
                else { if(!espadas.vacia() && espadas.tope().f + 1 == cAux.f) {
                        espadas.push(monton.pop());
                        fin = 0;
                }
                        else colocar = 0;
                }
                break;
            case BASTOS:
                if(bastos.vacia() && cAux.f == AS) {
                        bastos.push(monton.pop());
                        fin = 0;
                }
                else { if(!bastos.vacia() && bastos.tope().f + 1 == cAux.f) {
                        bastos.push(monton.pop());
                        fin = 0;
                }
                        else colocar = 0;
                }
                break;
            }
        }

    /*Cuando se agoten las cartas que hay en el mazo,
    se vuelven las cartas del montón de descartes al mazo,
    sin barajar (simplemente, se les da la vuelta y se
    devuelven al mazo, con lo que el orden se invierte),
    y se repite de nuevo el proceso de extracción de parejas del mazo.*/

        if(mazo.vacia()){
            while(!monton.vacia()){
                mazo.push(monton.pop());
            }
        }

        if(mazo.vacia() && monton.vacia()) fin = 1; //Condición de victoria

    /*El juego termina con éxito si se consigue situar
    todo el mazo sobre las bases, o con fracaso
    cuando se realicen todas las extracciones del mazo
    sin haber conseguido situar ninguna carta sobre las bases.*/
    }while(!fin);

    bool res;
    mazo.vacia() && monton.vacia() ? res = 1 : res = 0; //Devuelve 1 si termina con éxito, 0 en caso contrario

    return 0;
}
