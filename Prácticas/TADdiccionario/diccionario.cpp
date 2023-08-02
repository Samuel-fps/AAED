#include "diccionario.h"

void Diccionario::insertarTraduccion(const char* trad, ListaD<ListaD<const char*> >::posicion pos)
{
    assert( dicc.primera() != dicc.fin() );     //No vacio

    bool insertado = false; //Bandera para saber si se ha insertado o no
    ListaD<const char*>::posicion actual = dicc.elemento(pos).siguiente(dicc.elemento(pos).primera());    //La primera es la palabra en inglés

    //dicc.elemento(pos).insertar(trad);
    while( actual != dicc.elemento(pos).fin() && !insertado)
    {
        if( strcmp(trad, dicc.elemento(pos).elemento(actual)) < 0 )     //Si es menor se inserta en la posicion actual
        {
            dicc.elemento(pos).insertar(trad, actual);
            insertado = true;
        }
        else if( strcmp(trad, dicc.elemento(pos).elemento(actual)) == 0 ) insertado = true;     //Si es igual es que ya estaba insertado
        else if( strcmp(trad, dicc.elemento(pos).elemento(actual)) > 0 ) actual = dicc.elemento(pos).siguiente(actual);     //Si es mayor pasa a comprobar la siguiente traduccion
    }
}

void Diccionario::eliminarTraduccion(const char* trad, ListaD<ListaD<const char*> >::posicion pos)
{
    assert( dicc.primera() != dicc.fin() );     //No vacio

    ListaD<const char*>::posicion actual = dicc.elemento(pos).buscar(trad);
    if( actual != nullptr )    //Si existe la traduccion en la palabra
        dicc.elemento(pos).eliminar(actual);
}

ListaD<const char*> Diccionario::consultarTodas(ListaD<ListaD<const char*> >::posicion pos)
{
    assert( dicc.primera() != dicc.fin() );   //No vacio

    ListaD<const char*> traducc;
    ListaD<const char*>::posicion actualTraducc = traducc.primera();
    ListaD<const char*>::posicion actual = dicc.elemento(pos).siguiente(dicc.elemento(pos).primera());

    while( actual != dicc.elemento(pos).fin() )
    {
        traducc.insertar(dicc.elemento(pos).elemento(actual), actualTraducc);

        actualTraducc = traducc.siguiente(actualTraducc);
        actual = dicc.elemento(pos).siguiente(actual);
    }

    return traducc;
}
