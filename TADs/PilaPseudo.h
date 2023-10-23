#ifndef PILA_VEC_H
#define PILA_VEC_H

#include <cassert>

template <typename tElemento>
class Pila {
    public:
        explicit Pila(unsigned TamaMax); // Constructor, requiere constructor de tElemento()
        Pila(const Pila& P); // Constructor de copia
        Pila& operator=(const Pila& P); // Asignación entre pilas
        bool vacia() const;
        bool llena() const; // Requerida por la implementación
        const tElemento& tope() const;
        void pop();
        void push(const tElemento& x);
        ~Pila(); // Destructor

    private:
        tElemento *elementos; // Vector de elementos
        unsigned Lmax; // Tamaño del vector
        unsigned n_eltos; // Tamaño de la pila
};

template <typename tElemento>
inline Pila<tElemento>::Pila(unsigned TamaMax) :
    elementos(new tElemento[TamaMax]),
    Lmax(TamaMax),
    n_eltos(0)
{}

template <typename tElemento>
Pila<tElemento>::Pila(const Pila<tElemento>& P) :
    elementos(new tElemento[P.Lmax]),
    Lmax(P.Lmax),
    n_eltos(P.n_eltos)
{
    for (unsigned i = 0; i < n_eltos; ++i) // Copiar elementos
        elementos[i] = P.elementos[i];
}


template <typename tElemento>
Pila<tElemento>& Pila<tElemento>::operator=(const Pila<tElemento>& P) {
    if (this != &P) { // Evitar autoasignación
        // Destruir el vector y crear uno nuevo si es necesario
        if (Lmax != P.Lmax) {
            delete[] elementos;
            Lmax = P.Lmax;
            elementos = new tElemento[Lmax];
        }
        n_eltos = P.n_eltos;
        // Copiar elementos
        for (unsigned i = 0; i < n_eltos; ++i) {
            elementos[i] = P.elementos[i];
        }
    }
    return *this; // Devuelve una referencia a la instancia actual
}

template <typename tElemento>
inline bool Pila<tElemento>::vacia() const {
    return (n_eltos == 0);
}

template <typename tElemento>
inline bool Pila<tElemento>::llena() const {
    return (n_eltos == Lmax);
}

template <typename tElemento>
inline const tElemento& Pila<tElemento>::tope() const {
    assert(!vacia());
    return elementos[n_eltos - 1];
}


template <typename tElemento>
inline void Pila<tElemento>::pop() {
    assert(!vacia());
    --n_eltos;
}

template <typename tElemento>
inline void Pila<tElemento>::push(const tElemento& x) {
    assert(!llena());
    elementos[n_eltos] = x;
    ++n_eltos;
}

template <typename tElemento>
inline Pila<tElemento>::~Pila() {
    delete[] elementos;
}

#endif