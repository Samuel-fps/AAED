#ifndef TADDICCIONARIO_H_INCLUDED
#define TADDICCIONARIO_H_INCLUDED
#include <cassert>

#include <cstring>

#include "ListaD.h"

class Diccionario{
public:

    void insertarTraduccion(const char* trad, ListaD<ListaD<const char*> >::posicion pos);
    void eliminarTraduccion(const char* trad, ListaD<ListaD<const char*> >::posicion pos);

    ListaD<const char*> consultarTodas(ListaD<ListaD<const char*> >::posicion pos);

private:
    ListaD<ListaD<const char*> > dicc;
};

#endif // TADDICCIONARIO_H_INCLUDED
