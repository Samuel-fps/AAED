//
//  colaCir.hpp
//  TAD Cola circular
//
//  Created by Guillermo Girón García on 1/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef colaCir_hpp
#define colaCir_hpp

#include <cassert>

template <typename T>
class Cola
{
    T *elementos;   //vector de elementos
    int Lmax;   //Tamaño del vector
    int inicio, fin;    //posiciones de los extremos de la cola
    
public:
    explicit Cola(size_t TamaMax);  //Constructor, requiere ctor. T()
    Cola(const Cola <T> &C);    //Constructor de copia, requiere constructor T()
    Cola<T> &operator =(const Cola <T> &C); //Asig. olas req. T()
    bool vacia() const;
    bool llena() const; //Requerida por la implementacion
    const T &frente() const;
    void pop();
    void push(const T &x);
    ~Cola();    //destructor
};

template <typename T>
Cola<T>::Cola(const Cola<T> &C) :

    elementos(new T[C.Lmax]),
    Lmax(C.Lmax),
    inicio(C.inicio),
    fin(C.fin)
{
        int i;
    
        if(!C.vacia())  //Copia el vector
            for(i = inicio; i != (fin + 1) % Lmax; i = (i + 1) % Lmax)
                elementos[i] = C.elementos[i];
}

template <typename T>
Cola<T>::Cola(size_t TamaMax) :
    elementos(new T[TamaMax + 1]),  //+1 para detectar cola llena
    Lmax(TamaMax + 1),
    inicio(0),
    fin(TamaMax)
{}

template <typename T>
Cola<T> &Cola<T>::operator=(const Cola<T> &C)
{
    int i;
    
    //Evitar autoasignacion
    
    if (this != &C)
    {
        //Destruir el vector y crear uno nuevo si es necesario
        
        if (Lmax != C.Lmax)
        {
            delete [] elementos;
            Lmax = C.Lmax;
            elementos = new T[Lmax];
        }
        
        //Copiar el vector
        
        inicio = C.inicio;
        fin = C.fin;
        
        if (!C.vacia())
        {
            for (i = inicio; i != (fin +1) % Lmax; i = (i + 1) % Lmax)
            {
                elementos[i] = C.elementos[i];
            }
        }
    }
    
    return *this;
}

template <typename T>
inline bool Cola<T>::vacia() const
{
    return ((fin + 1) % Lmax == inicio);
}

template <typename T>
inline bool Cola<T>::llena() const
{
    return ((fin + 2) % Lmax == inicio);
}

template <typename T>
inline const T &Cola<T>::frente() const
{
    assert(!vacia());
    
    return elementos[inicio];
}

template <typename T>
inline void Cola<T>::pop()
{
    assert(!vacia());
    inicio = (inicio + 1) % Lmax;
}

template <typename T>
inline void Cola<T>::push(const T &x)
{
    assert(!llena());
    
    fin = (fin +1) % Lmax;
    elementos[fin] = x;
}

template <typename T>
inline Cola<T>::~Cola()
{
    delete [] elementos;
}

#endif /* colaCir_hpp */
