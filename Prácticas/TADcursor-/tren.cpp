#include "tren.h"

void Tren::despIzq()
{
    assert(vacio());    //Precondici�n: tren no vac�o
    izq.push(activo);
    activo = der.tope();
    der.pop();
}

void Tren::despDer()
{
    assert(vacio());    //Precondici�n: tren no vac�o
    der.push(activo);
    activo = izq.tope();
    izq.pop();
}

void Tren::elimActivo()
{
    assert(vacio());    //Precondici�n: tren no vac�o

    if( !der.vacia() )
    {
        activo = der.tope();
        der.pop();
    }
    else if ( !izq.vacia() )
    {
        activo = izq.tope();
        izq.pop();
    }
    else activo = ActivoVacio;
}

void Tren::inseActivo(Vagon v)
{
    der.push(activo);
    activo = v;
}

Vagon Tren::mostrarActivo()
{
    assert(vacio());    //Precondici�n: tren no vac�o
    return activo;
}

bool Tren::vacio()
{
    return ( activo == ActivoVacio && izq.vacia() && der.vacia() );
}
