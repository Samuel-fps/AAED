//
//  colaEnla.hpp
//  TAD Cola circular
//
//  Created by Guillermo Girón García on 1/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef colaEnla_hpp
#define colaEnla_hpp

#include <cassert>

template <typename T>
class Cola
{
    struct nodo
    {
        T elto;
        nodo *sig;
        nodo(const T &e, nodo *P = 0) :
        elto(e),
        sig(p)
        {}
    };
    
    nodo *inicio, *fin; //extremos de la cola
    
    void copiar(const Cola<T> &C);
    
public:
    Cola(); //Constructor
    Cola(const Cola<T> &C); //Constructor de copia
    Cola<T> &operator = (const Cola<T> &C); //Asignacion d colas
    bool vacia() const;
    const T &frente() const;
    void pop();
    void push(const T &x);
    ~Cola();    //destructor
};

//Metodo privado

template <typename T>
void Cola<T>::copiar(const Cola<T> &C)
{
    nodo *p;
    
    //C no esta vacia
    
    if (C.incio)
    {
        //Copiar el primer elemento
        
        inicio = fin = new nodo(C.inicio -> elto);
        
        //Copiar el resto de elementos hasta el final de la cola
        
        for (*p = C.inicio -> sig; p; p = p -> sig)
        {
            fin -> sig = new nodo(p -> elto);
            fin = fin -> sig;
        }
    }
}

template <typename T>
inline Cola<T>::Cola() : inicio(0), fin(0)
{}

template <typename T>
inline Cola<T>::Cola(const Cola<T> &C) : inicio(0), fin(0)
{
    copiar(C);
}

template <typename T>
inline Cola<T> &Cola<T>::operator = (const Cola<T> &C)
{
    //Evitar autoasignacion
    
    if (this != &C)
    {
        //Vaciar la cola actual
        
        this ->~Cola();
        copiar(C);
    }
    
    return *this;
}

template <typename T>
inline bool Cola<T>:vacia() const
{
    return (inicio == 0);
}

template <typename T>
inline const T &Cola<T>::frente() const
{
    assert(!vacia());
    
    return inicio -> elto;
}

template <typename T>
inline void Cola<T>::pop()
{
    assert(!vacia());
    
    nodo *p = inicio;
    inicio = p -> sig;
    
    if(!inicio)
        fin = 0;
    
    delete p;
}

template <typename T>
inline void Cola<T>::push(const T &x)
{
    nodo *p = new nodo(x);
    
    //Cola vacia
    
    if(inicio == 0)
        inicio = fin = p;
    else
        fin = fin ->sig = p;
}

//Destructor: vacia la cola

template <typename T>
Cola<T>::~Cola()
{
    nodo *p;
    while (inicio)
    {
        p = inicio -> sig;
        
        delete incio;
        
        inicio = p;
    }
    
    fin = 0;
}

#endif /* colaEnla_hpp */
