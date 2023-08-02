#ifndef EJERCICIO6V2_H_INCLUDED
#define EJERCICIO6V2_H_INCLUDED

#include "ListaD.h"

template <typename T> class Conjunto{
public:
    bool vacio();
    void insertar(T ele);
    void eliminar(T ele);

    operator +(Conjunto<T> con);  //Unión
    operator /(Conjunto<T> con);  //Intersección
    operator -(Conjunto<T> con);  //Diferencia

private:
    ListaD<T> elementos;
};


template <typename T> bool Conjunto<T>::vacio()
{
    return (elementos.primera() == elementos.fin());
}

template <typename T> void Conjunto<T>::insertar(T ele)
{
    if( elementos.buscar(ele) != nullptr ) elementos.insertar(ele, elementos.primera());
}

template <typename T> void Conjunto<T>::eliminar(T ele)
{
    typename ListaD<T>::posicion pos = elementos.buscar(ele);
    if( pos != nullptr ) elementos.eliminar(pos);
}

template <typename T> Conjunto<T>::operator +(Conjunto<T> con)     //Unión
{
    Conjunto<T> conAux(*this);

    for( typename ListaD<T>::posicion pos = con.primera(); pos != con.fin(); pos = con.siguiente(pos) )
    {
        conAux.elementos.insertar(con.elementos.elemento(pos), conAux.elementos.primera());
    }
    return conAux;
}

template <typename T> Conjunto<T>::operator /(Conjunto<T> con)     //Intersección
{
    Conjunto<T> conAux;

    for( typename ListaD<T>::posicion pos = con.primera(); pos != con.fin(); pos = con.siguiente(pos) )
    {
        typename ListaD<T>::posicion pos2 = *this.elementos.buscar(conAux.elementos.elemento(pos));
        if( pos2 != nullptr )
            conAux.elementos.insertar(con.elementos.elemento(pos), conAux.elementos.primera());
    }
    return conAux;
}

template <typename T> Conjunto<T>::operator -(Conjunto<T> con)     //Diferencia
{
    Conjunto<T> conAux;

    for( typename ListaD<T>::posicion pos = con.primera(); pos != con.fin(); pos = con.siguiente(pos) )
    {
        typename ListaD<T>::posicion pos2 = *this.elementos.buscar(conAux.elementos.elemento(pos));
        if( pos2 == nullptr )
            conAux.elementos.insertar(con.elementos.elemento(pos), conAux.elementos.primera());
    }
    return conAux;
}

#endif // EJERCICIO6V2_H_INCLUDED
