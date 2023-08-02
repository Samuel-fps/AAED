#ifndef EJERCICIO7_H_INCLUDED
#define EJERCICIO7_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#include "ListaD.h"

template<typename T>  ListaD<T> concatenarLInic(ListaD<ListaD<T> > LInic)
{
    ListaD<T> LConcat;

    for( typename ListaD<ListaD<T> >::posicion i = LInic.primera(); i != LInic.fin(); i = LInic.siguiente(i) )
    {
        typename ListaD<T>::posicion pos = LConcat.primera();
        for( typename ListaD<T>::posicion j = LInic.elemento(i).primera(); j != LInic.elemento(i).fin(); j = LInic.elemento(i).siguiente(j) )
        {
            LConcat.insertar(LInic.elemento(i).elemento(j), pos);
            pos = LConcat.siguiente(pos);
        }
    }
    return LConcat;
}

#endif // EJERCICIO7_H_INCLUDED
