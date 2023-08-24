//
//  colaPse.hpp
//  TAD Cola circular
//
//  Created by Guillermo Girón García on 1/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef colaPse_hpp
#define colaPse_hpp

#include <cassert>

template <typename T>
class Cola
{
    T *elementos;   //Vector de elementos
    int Lmax;   //Tamaño del vector
    int fin;    //Posicion del ultimo
public:
    explicit Cola(size_t TamaMax);  //Constructor, requiere constructor T()
    Cola(const Cola<T> &C); //Constructor de copia, requiere constructor T()
    Cola<T> &operator =(const Cola<T> &C);  //Asignacion cola requerida T()
    bool vacia() const;
    bool llena() const; //Requerida por la implementacion
    const T &frente() const;
    void pop();
    void push(const T &x);
    ~Cola();    //destructor
};

template <typename T>
inline Cola<T>::Cola(size_t TamaMax) :
    elementos(new T[TamaMax]),
    Lmax(TamaMax),
    fin(-1)
{}

template <typename T>
Cola<T>::Cola(const Cola<T> &C) :
    elementos(new T[C.Lmax]),
    Lmax(C.Lmax),
    fin(C.fin)
{
    //copiar el veector
    
    for( i = 0; i <= fin; ++i)
        elementos[i] = C.elementos[i];
}

template <typename T>
Cola <T> &Cola<T>::operator = (const Cola<T> &C)
{
    //Evitar autoasignacion
    
    if(this != &C)
    {
        //Destruir el vector y crear uno nuevo si es necesario
        
        if(Lmax != C.Lmax)
        {
            delete[] elementos;
            Lmax = C.Lmax;
            elementos = new T[Lmax];
        }
    }
    
    return *this;
}

template <typename T>
inline bool Cola<T>::vacia() const
{
    return (fin == -1;)
}

template <typename T>
inline bool Cola<T>::llena()
{
    return (fin == Lmax - 1);
}



#endif /* colaPse_hpp */
