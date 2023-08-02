#include <iostream>
#include <stdlib.h>

//#include "ListaD.h"
//#include "ListaE.h"
//#include "ListaCir.h"

//#include "Ejercicio1.h"
//#include "Ejercicio2.h"
//#include "Ejercicio3.h"
//#include "Ejercicio4.h"
//#include "Ejercicio5.h"
//#include "Ejercicio6.h"
#include "Ejercicio6v2.h"
//#include "Ejercicio7.h"
//#include "Ejercicio8.h"
//#include "Ejercicio9.h"

#define N 10

using namespace std;

int main()
{
/*
    ListaD<int> li;
    ListaD<int>::posicion i = li.primera();
    li.insertar(1, i);
    i = li.siguiente(i);
    li.insertar(1, i);
    i = li.siguiente(i);
    li.insertar(6, i);
    i = li.siguiente(i);
    li.insertar(4, i);
    i = li.siguiente(i);
    li.insertar(1, i);
    i = li.siguiente(i);
    li.insertar(2, i);
    i = li.siguiente(i);
    li.insertar(9, i);
    i = li.siguiente(i);
    li.insertar(6, i);
    i = li.siguiente(i);

    for(i = li.primera(); i != li.fin(); i = li.siguiente(i)){
        cout << li.elemento(i) << " ";
    } cout << endl;

    li.eliminar(li.buscar(9));

    for(i = li.primera(); i != li.fin(); i = li.siguiente(i)){
        cout << li.elemento(i) << " ";
    } cout << endl;
*/
////////////////EJERCICIO 1////////////////

////////////////EJERCICIO 2////////////////
/*
    ListaOrd<int> lista;
    lista.insertar(1);
    lista.insertar(6);
    lista.insertar(43);
    lista.insertar(17);
    lista.insertar(2);
    lista.insertar(9);
    lista.insertar(66);

    for(ListaOrd<int>::posicion i = lista.primera(); i != lista.fin(); i = lista.siguiente(i)){
        cout << lista.elemento(i) << " ";
    } cout << endl;
*/
////////////////EJERCICIO 3////////////////
/*
    ListaCir<int> lista;
    lista.insertar(7, lista.inipos());
    lista.insertar(1, lista.inipos());
    lista.insertar(6, lista.inipos());
    lista.insertar(4, lista.inipos());
    lista.insertar(1, lista.inipos());
    lista.insertar(2, lista.inipos());
    lista.insertar(9, lista.inipos());
    lista.insertar(6, lista.inipos());

    implista(lista);

    //cout << lista.elemento(lista.anterior(lista.inipos())) << endl;
    elim_ocu(lista, 7);

    implista(lista);
*/
////////////////EJERCICIO 4////////////////
/*
    ListaOrd<int> lista1;
    lista1.insertar(1);
    lista1.insertar(6);
    lista1.insertar(4);
    lista1.insertar(7);
    lista1.insertar(2);
    lista1.insertar(9);
    lista1.insertar(6);

    for(ListaOrd<int>::posicion i = lista1.primera(); i != lista1.fin(); i = lista1.siguiente(i)){
        cout << lista1.elemento(i) << " ";
    } cout << endl;

    ListaOrd<int> lista2;
    lista2.insertar(8);
    lista2.insertar(6);
    lista2.insertar(2);
    lista2.insertar(8);
    lista2.insertar(9);
    lista2.insertar(1);
    lista2.insertar(5);

    for(ListaOrd<int>::posicion i = lista2.primera(); i != lista2.fin(); i = lista2.siguiente(i)){
        cout << lista2.elemento(i) << " ";
    } cout << endl;

    ListaOrd<int> l3;

    l3 = concatenar(lista1, lista2);

    for(ListaOrd<int>::posicion i = l3.primera(); i != l3.fin(); i = l3.siguiente(i)){
        cout << l3.elemento(i) << " ";
    } cout << endl;
*/
////////////////EJERCICIO 5////////////////
/*
    ListaE<int> lista(N);
    for(int p = 0; p < N; p++){
        lista.insertar(p, p);
    }

    impNormal(lista, 0);

    impInverso(lista, 4);
*/
////////////////EJERCICIO 6////////////////
/*
    Conjunto<int> cAux;

    Conjunto<int> con1;
    con1.insertar(1);
    con1.insertar(1);
    con1.insertar(3);
    con1.insertar(2);
    con1.insertar(9);
    con1.insertar(7);
    system("PAUSE");

    Conjunto<int> con2;
    con2.insertar(4);
    con2.insertar(1);
    con2.insertar(5);
    con2.insertar(3);
    con2.insertar(9);
    con2.insertar(7);
    system("PAUSE");

    cAux = con1 + con2;
    cAux.mostrar();

    cAux = con1 / con2;
    cAux.mostrar();

    cAux = con1 - con2;
    cAux.mostrar();

    //cout << con.elemento(con.buscar(2)) << endl;

*/
    return 0;
}
