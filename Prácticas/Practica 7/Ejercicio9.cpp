#include "Ejercicio9.h"

ListaCir<int>::posicion juegocircular(ListaCir<int> lisC, ListaCir<int>::posicion inicio)
{
    ListaCir<int>::posicion actual = inicio;
    ListaCir<int>::posicion previo = inicio;
    int i = 0;

    do
    {
        i = lisC.elemento(actual);

        if ( lisC.elemento(actual) % 2 == 0 )
        {
            actual = lisC.siguiente(actual);
            previo = lisC.siguiente(actual);

            lisC.eliminar(previo);
            while( i != 0 )
            {
                actual = lisC.siguiente(actual);
                --i;
            }
        }
        else
        {
            actual = lisC.anterior(actual);
            previo = lisC.anterior(actual);

            lisC.eliminar(previo);
            while( i != 0 )
            {
                actual = lisC.anterior(actual);
                --i;
            }
        }

    } while( actual != lisC.siguiente(actual) );

    return actual;
}
