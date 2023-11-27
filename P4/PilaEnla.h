#ifndef PILA_ENLA_H
#define PILA_ENLA_H
#include <cstddef> // size_t
#include <cassert>

template <typename T> class Pila {
public:
    Pila();
    bool vacia() const;
    size_t tama() const;
    const T& tope() const;
    void pop();
    void push(const T& x);
    Pila(const Pila& P); // Ctor. de copia
    Pila& operator =(const Pila& P); // Asignación entre pilas
    ~Pila(); // Destructor
private:
    struct nodo {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = nullptr) : elto(e), sig(p) {}
    };

    nodo* tope_;
    size_t n_eltos;

    void copiar(const Pila& P);
};

template <typename T>
inline bool Pila<T>::vacia() const
{
    return (n_eltos == 0); // Alternativa: return tope_ == nullptr;
}

template <typename T>
inline size_t Pila<T>::tama() const
{
    return n_eltos;
}

template <typename T>
inline const T& Pila<T>::tope() const
{
    assert(!vacia());
    return tope_->elto;
}

template <typename T>
inline void Pila<T>::pop()
{
    assert(!vacia());
    nodo* p = tope_;
    tope_ = p->sig;
    delete p;
    --n_eltos;
}

template <typename T>
inline void Pila<T>::push(const T& x)
{
    tope_ = new nodo(x, tope_);
    ++n_eltos;
}

template <typename T>
inline Pila<T>::Pila(const Pila& P) : Pila()
{
    copiar(P);
}

template <typename T>
Pila<T>& Pila<T>::operator =(const Pila& P)
{
    if (this != &P) { // Evitar autoasignación
        this->~Pila(); // Vaciar la pila actual
        copiar(P);
    }
    return *this;
}

template <typename T>
Pila<T>::~Pila()
{
    nodo* p;
    while (tope_) {
        p = tope_->sig;
        delete tope_;
        tope_ = p;
    }
    n_eltos = 0;
}
