#include "Ejercicio8.h"

Binario::Binario(const char* cad)
{
    ListaD<bool>::posicion pos = digitos.primera();
    int i = 0;
    while( cad[i] != '\0' ) ++i;

    for( int j = i - 1; j >= 0; --j )
    {
        if ( cad[j] == '0' ) digitos.insertar( 0, pos );
        else if ( cad[j] == '1' ) digitos.insertar( 1, pos );
        else exit(1);   //Si hay algo distinto a 0 ó 1, entonces se termina el programa

        pos = digitos.siguiente(pos);
    }
}

Binario operator ~(Binario bin)
{
    for ( ListaD<bool>::posicion pos = bin.digitos.primera(); pos != bin.digitos.fin(); pos = bin.digitos.siguiente(pos) )
    {
        bin.digitos.elemento(pos) = !(bin.digitos.elemento(pos));
    }
    return bin;
}

bool operator &(Binario bin1, Binario bin2)
{
    ListaD<bool>::posicion pos1 = bin1.digitos.primera();
    ListaD<bool>::posicion pos2 = bin2.digitos.primera();
    bool res = true;

    while ( res && pos1 != bin1.digitos.fin() && pos2 != bin2.digitos.fin() )
    {
        if ( bin1.digitos.elemento(pos1) != 1 || bin2.digitos.elemento(pos2) != 1 )
            res = false;

        pos1 = bin1.digitos.siguiente(pos1);
        pos2 = bin2.digitos.siguiente(pos2);
    }
    return res;
}

bool operator |(Binario bin1, Binario bin2)
{
    ListaD<bool>::posicion pos1 = bin1.digitos.primera();
    ListaD<bool>::posicion pos2 = bin2.digitos.primera();
    bool res1 = true;
    bool res2 = true;

    while ( (res1 || res2) && pos1 != bin1.digitos.fin() && pos2 != bin2.digitos.fin() )
    {
        if ( res1 && bin1.digitos.elemento(pos1) != 1 ) res1 = false;

        if ( res2 && bin2.digitos.elemento(pos2) != 1 ) res2 = false;

        pos1 = bin1.digitos.siguiente(pos1);
        pos2 = bin2.digitos.siguiente(pos2);
    }
    return ( res1 || res2 );
}

bool operator ^(Binario bin1, Binario bin2)
{
    ListaD<bool>::posicion pos1 = bin1.digitos.primera();
    ListaD<bool>::posicion pos2 = bin2.digitos.primera();
    bool res1 = true;
    bool res2 = true;
    bool res = true;

    while ( (res1 || res2) && pos1 != bin1.digitos.fin() && pos2 != bin2.digitos.fin() )
    {
        if ( res1 && bin1.digitos.elemento(pos1) != 1 ) res1 = false;

        if ( res2 && bin2.digitos.elemento(pos2) != 1 ) res2 = false;

        pos1 = bin1.digitos.siguiente(pos1);
        pos2 = bin2.digitos.siguiente(pos2);
    }
    if ( res1 && res2 ) res = false;
    else if ( !res1 && !res2 ) res = false;

    return res;
}

Binario operator <<(Binario bin, unsigned num)
{
    ListaD<bool>::posicion pos = bin.digitos.primera();

    for ( unsigned i = 0; i != num; ++i )   //Obtener la posicion del último digito del nuevo Binario
        pos = bin.digitos.siguiente(pos);

    int j = 0;  //Obtener tamaño de la nueva cadena
    ListaD<bool>::posicion posAux = bin.digitos.primera();
    for ( ; posAux != bin.digitos.fin(); posAux = bin.digitos.siguiente(posAux) )
        ++j;

    posAux = pos;   //Se guarda la posicion del ultimo digito del nuevo Binario

    char cad[j + 1];    //+1 por el terminador
    j = 0;
    while ( pos != bin.digitos.fin() )
    {
        cad[j] = static_cast<char>(bin.digitos.elemento(pos));
        ++j;
    }

    for ( pos = posAux; pos != bin.digitos.fin(); pos = bin.digitos.siguiente(pos) )
    {
        cad[j] = '0';
        ++j;
    }

    cad[j] = '\0';

    return Binario(cad);
}

Binario operator >>(Binario bin, unsigned num)
{
    ListaD<bool>::posicion fin = bin.digitos.primera();

    unsigned i = 0;
    for ( ; i != num; ++i )   //Obtener la posicion del primer digito del nuevo Binario
        fin = bin.digitos.siguiente(fin);

    char cad[i + 1];    //+1 por el terminador
    i = 0;
    for ( ListaD<bool>::posicion pos = bin.digitos.primera(); pos != fin; pos = bin.digitos.siguiente(pos) )
    {
        cad[i] = '0';
        ++i;
    }
    cad[i] = '\0';

    return Binario(cad);
}
