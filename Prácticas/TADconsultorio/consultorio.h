#ifndef TADCOLADINAMICA_H_INCLUDED
#define TADCOLADINAMICA_H_INCLUDED
#include <cassert>
#include <string>

//#include "TADColaDinamica.h"
#include "TADListaDinamica.h"
//template <typename T> class ColaD;


template <typename T> class ColaD {
    public:
        ColaD(); // constructor
        ColaD(const ColaD<T>& C); // ctor. de copia
        ColaD<T>& operator =(const ColaD<T>& C); // asignaci�n de colas
        bool vacia() const;
        const T& frente() const;
        void pop();
        void push(const T& x);
        ~ColaD(); // destructor

    private:
        struct nodo {
            T elto;
            nodo* sig;
            nodo(const T& e, nodo* p = 0): elto(e), sig(p) {}
        };
        nodo *inicio, *fin; // extremos de la cola
        void copiar(const ColaD<T>& C);
        };

        // M�todo privado
template <typename T>
void ColaD<T>::copiar(const ColaD<T>& C) {
    if (C.inicio) { // C no est� vac�a
        // Copiar el primer elto.
        inicio = fin = new nodo(C.inicio->elto);
        // Copiar el resto de elementos hasta el final de la cola.
        for (nodo *p = C.inicio->sig; p; p = p->sig) {
            fin->sig = new nodo(p->elto);
            fin = fin->sig;
        }
    }
}

template <typename T> inline ColaD<T>::ColaD() : inicio(0), fin(0) {}

template <typename T> inline ColaD<T>::ColaD(const ColaD<T>& C) : inicio(0), fin(0) {
    copiar(C);
}

template <typename T> inline ColaD<T>& ColaD<T>::operator =(const ColaD<T>& C) {
    if (this != &C) { // evitar autoasignaci�n
        this->~ColaD(); // vaciar la cola actual
        copiar(C);
    }
    return *this;
}

template <typename T> inline bool ColaD<T>::vacia() const {
    return (inicio == 0);
}

template <typename T> inline const T& ColaD<T>::frente() const {
    assert(!vacia());
    return inicio->elto;
}

template <typename T> inline void ColaD<T>::pop() {
    assert(!vacia());
    nodo* p = inicio;
    inicio = p->sig;
    if (!inicio) fin = 0;
    delete p;
}

template <typename T> inline void ColaD<T>::push(const T& x) {
    nodo* p = new nodo(x);
    if (inicio == 0) // cola vac�a
        inicio = fin = p;
    else fin = fin->sig = p;
}

// Destructor: vac�a la cola
template <typename T> ColaD<T>::~ColaD() {
    nodo* p;
    while (inicio) {
        p = inicio->sig;
        delete inicio;
        inicio = p;
    }
    fin = 0;
}













class Consultorio{
public:
    //Constructor por defecto

    void insertarMedico(ListaD<ColaD<std::string> >::posicion& pos);
    void eliminarMedico(ListaD<ColaD<std::string> >::posicion& pos);

    void nuevoPaciente(std::string pac, ListaD<ColaD<std::string> >::posicion& pos);
    std::string siguientePaciente(ListaD<ColaD<std::string> >::posicion& pos);
    bool esperaVacia(ListaD<ColaD<std::string> >::posicion& pos);

private:
    ListaD<ColaD<std::string> > medicos;

};

#endif // TADCOLADINAMICA_H_INCLUDED
