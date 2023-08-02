#include <iostream>
#include <stdlib.h>
#include <new>
#include <algorithm>

#include "ColaD.h"
#include "ColaE.h"

#include "Ejercicio6.h"

int intervalo_aleatorio (int, int);

bool solitarioReyes(ColaD<tCarta>& baraja){
    bool res = 1;
    bool fin = 0;
    tMonton montonAux;

    /*Se reparten las cartas de la baraja española
    en diez montones de cuatro cartas cada uno.
    Cada montón se corresponde con una de las diez
    figuras de la baraja.*/

    tMonton *montones = new tMonton[9];
    do{
    int i = 0;
    while(!baraja.vacia()){
        montones[i].push(baraja.frente());
        baraja.pop();

        if(i + 1 > REY) i = AS;
        else i++;
    }

    /* Se escoge uno de los montones al azar y se
    extrae la carta de dicho montón que esté en la cima. */

    int act = intervalo_aleatorio(AS, REY);
    tCarta cartaAux = montones[act].frente();
    montones[act].pop();

    /*Esta carta se coloca al final del montón
    correspondiente a la figura que represente,
    extrayéndose ahora la primera carta de este montón.*/

    act = cartaAux.f;
    montones[act].push(cartaAux);
    cartaAux = montones[act].frente();
    montones[act].pop();

    /*Este ciclo se repite hasta llegar a un montón
    en el que las cuatro cartas de la figura
    correspondiente han sido colocadas. */

    int cont = 0;
    while(res && !montones[act].vacia()){
        if(montones[act].frente().f != act) cont++;
        montonAux.push(montones[act].frente());
        montones[act].pop();
    }
    if(cont == 4 && act == REY) {res = 1; fin = 1;}
    if(cont == 4 && act != REY) {res = 0; fin = 1;}

    while(!fin && !montonAux.vacia()){
        montones[act].push(montonAux.frente());
        montonAux.pop();
    }
    }while(!fin);

    while(!baraja.vacia()){
        baraja.pop();
    }
    while(!montonAux.vacia()){
        baraja.push(montones[REY].frente());
        montones[REY].pop();
    }

    return res;
}


int intervalo_aleatorio (int a, int b){

    int aux = rand();

    if (a>b){
        int aux2 = a;
        a = b;
        b = aux2;
    }

    while(!(aux <= b && aux >= a)){
        aux = a + aux % (b-a+1);
    }
    return aux;
}
