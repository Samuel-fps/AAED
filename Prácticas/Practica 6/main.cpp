#include <iostream>
#include <stdlib.h>
#include <string>

#include "PilaD.h"
#include "ColaD.h"
#include "ColaE.h"

//#include "Ejercicio1.h"
//#include "Ejercicio2.h"
//#include "Ejercicio3.h"
//#include "Ejercicio4.h"
//#include "Ejercicio5.h"
#include "Ejercicio6.h"

using namespace std;

int main(){

///////////EJERCICIO 1///////////
/*
    PilaD<int> pAux;
    ColaD<int> cAux;

    pAux.push(1);
    pAux.push(0);
    pAux.push(2);
    pAux.push(0);
    pAux.push(3);
    pAux.push(0);

    cAux.push(0);
    cAux.push(1);
    cAux.push(0);
    cAux.push(2);
    cAux.push(0);
    cAux.push(3);

    if(isomorfa(pAux, cAux)) cout << "Son isomorfas" << endl;
    else cout << "No son isomorfas" << endl;
*/


///////////EJERCICIO 2///////////
/*
    ColaD<int> cAux;

    cAux.push(1);
    cAux.push(2);
    cAux.push(3);
    cAux.push(4);
    cAux.push(5);
    cAux.push(6);
    cAux.push(7);
    cAux.push(8);
    cAux.push(9);
    cAux.push(0);

    cAux = invSecuencia(cAux, 4, 7);

    while(!cAux.vacia()){
        cout << cAux.frente();
        cAux.pop();
    } cout << endl;
*/


///////////EJERCICIO 5///////////
/*
    const unsigned TamAero = 12;
    ColaE<string> aero(TamAero);

    aerodromo(aero, 'E', "AAAA123");
*/


///////////EJERCICIO 6///////////
    ColaD<tCarta> baraja;
    if(solitarioReyes(baraja)) cout << "VICTORIA" << endl;
    else cout << "DERROTA" << endl;

    return 0;
}
