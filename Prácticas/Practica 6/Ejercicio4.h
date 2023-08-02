#ifndef PILAB_H_INCLUDED
#define PILAB_H_INCLUDED
#include <cassert>

#include "Ejercicio3.h"

template <typename tElemento> class PilaB {
public:
    explicit PilaB();                   /*Constructor*/
    PilaB(const PilaB<tElemento>& P);   /*Constructor de copia*/
    PilaB<tElemento>& operator= (const PilaB<tElemento>& P); //Asignación entre pilas
    bool vacia() const;
    const tElemento& tope() const;
    tElemento pop();
    void push(const tElemento& x);
    ~PilaB(); /*Destructor*/
private:
    BicolaD<tElemento> pila;
    void copiar(const PilaB<tElemento>& P);
};

template <typename tElemento> void PilaB<tElemento>::copiar(const PilaB<tElemento>& P){

    while(!pila.vacia()){
        pila.popIzq();
    }
    while(!P.vacia()){
        pila.pushIzq(P.pop());
    }
}

template <typename tElemento>
inline PilaB<tElemento>::PilaB() {}

template <typename tElemento>
PilaB<tElemento>::PilaB(const PilaB<tElemento>& P)
{
    copiar(P);
}

template <typename tElemento>
PilaB<tElemento>& PilaB<tElemento>::operator= (const PilaB<tElemento>& P)
{
    if(this != &P) {    //Evitar autoasignación
        this->~PilaB();  //Vaciar la pila actual
        copiar(P);
    }
    return *this;
}

template <typename tElemento>
inline bool PilaB<tElemento>::vacia() const
{
    return (pila.vacia());
}

template <typename tElemento>
inline const tElemento& PilaB<tElemento>::tope() const
{
    assert(!vacia());
    return pila.frenteIzq();
}

template <typename tElemento>
inline tElemento PilaB<tElemento>::pop()
{
    assert(!vacia());
    tElemento eltoAux = pila.frenteIzq();
    pila.popIzq();
    return eltoAux;
}

template <typename tElemento>
inline void PilaB<tElemento>::push(const tElemento& x)
{
    pila.pushIzq(x);
}

//Destructor: vacía la pila
template <typename tElemento>
PilaB<tElemento>::~PilaB()
{
    pila.~BicolaD();
}













template <typename T> class ColaB {
    public:
        ColaB(); // constructor
        ColaB(const ColaB<T>& C); // ctor. de copia
        ColaB<T>& operator =(const ColaB<T>& C); // asignación de colas
        bool vacia() const;
        const T& frente() const;
        void pop();
        void push(const T& x);
        ~ColaB(); // destructor

    private:
        BicolaD<T> cola;
        void copiar(const ColaB<T>& C);
        };

        // Método privado
template <typename T>
void ColaB<T>::copiar(const ColaB<T>& C) {
    while(!cola.vacia()){
        cola.popIzq();
    }
    while(!C.vacia()){
        cola.pushDer(C.frente());
        C.pop();
    }
}

template <typename T> inline ColaB<T>::ColaB() {}

template <typename T> inline ColaB<T>::ColaB(const ColaB<T>& C) {
    copiar(C);
}

template <typename T> inline ColaB<T>& ColaB<T>::operator =(const ColaB<T>& C) {
    if (this != &C) { // evitar autoasignación
        this->~ColaB(); // vaciar la cola actual
        copiar(C);
    }
    return *this;
}

template <typename T> inline bool ColaB<T>::vacia() const {
    return (cola.vacia());
}

template <typename T> inline const T& ColaB<T>::frente() const {
    assert(!vacia());
    return cola.frenteIzq();
}

template <typename T> inline void ColaB<T>::pop() {
    assert(!vacia());
    cola.popIzq();
}

template <typename T> inline void ColaB<T>::push(const T& x) {
    cola.pushDer(x);
}

// Destructor: vacía la cola
template <typename T> ColaB<T>::~ColaB() {
    cola.~BicolaD();
}


#endif // PILAB_H_INCLUDED
