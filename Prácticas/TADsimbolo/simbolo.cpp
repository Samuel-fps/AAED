#include "simbolo.h"

void Simbolo::insertar(Simbolo::Trazo t)
{
    trazos.push(t);
}

void Simbolo::deshacer(unsigned n)
{
    for( unsigned i = 0; i != n && !trazos.vacia(); i++)
        trazos.pop();
}

Simbolo Simbolo::simetriaX()
{
    Simbolo simAux(*this);
    Simbolo simRes;
    Trazo t;

    while( !simAux.trazos.vacia() )
    {
        switch( simAux.trazos.frente() )
        {
            case Simbolo::Arr: {t = Simbolo::Aba; break;}
            case Simbolo::Aba: {t = Simbolo::Arr; break;}
        }
        simRes.trazos.push(t);
        simAux.trazos.pop();
    }
    return simRes;
}

Simbolo Simbolo::simetriaY()
{
    Simbolo simAux(*this);
    Simbolo simRes;
    Trazo t;

    while( !simAux.trazos.vacia() )
    {
        switch( simAux.trazos.frente() )
        {
            case Simbolo::Izq: {t = Simbolo::Der; break;}
            case Simbolo::Der: {t = Simbolo::Izq; break;}
        }
        simRes.trazos.push(t);
        simAux.trazos.pop();
    }
    return simRes;
}

Simbolo Simbolo::simetriaXY()
{
    Simbolo simAux(*this);
    Simbolo simRes;
    Trazo t;

    while( !simAux.trazos.vacia() )
    {
        switch( simAux.trazos.frente() )
        {
            case Simbolo::Arr: {t = Simbolo::Aba; break;}
            case Simbolo::Aba: {t = Simbolo::Arr; break;}
            case Simbolo::Izq: {t = Simbolo::Der; break;}
            case Simbolo::Der: {t = Simbolo::Izq; break;}
        }
        simRes.trazos.push(t);
        simAux.trazos.pop();
    }
    return simRes;
}
