#ifndef PILA_VEC0_H
#define PILA_VEC0_H

#include <cassert>

class Pila {
public:
    typedef int tElemento; // Por ejemplo

    Pila();
    bool vacia() const;
    bool llena() const; // Requerida por la implementación
    const tElemento& tope() const;
    void pop();
    void push(const tElemento& x);

private:
    static const unsigned Lmax = 100; // Longitud máx. de una pila
    tElemento elementos[Lmax]; // Vector de elementos
    unsigned n_eltos; // Número de elementos
};

Pila::Pila() : n_eltos(0) {}

bool Pila::vacia() const {
    return (n_eltos == 0);
}

bool Pila::llena() const {
    return (n_eltos == Lmax);
}

const Pila::tElemento& Pila::tope() const {
    assert(!vacia());
    return elementos[n_eltos - 1];
}

void Pila::pop() {
    assert(!vacia());
    --n_eltos;
}

void Pila::push(const tElemento& x) {
    assert(!llena());
    elementos[n_eltos] = x;
    ++n_eltos;
}

#endif