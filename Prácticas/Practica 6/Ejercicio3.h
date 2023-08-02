#ifndef EJERCICIO3_H_INCLUDED
#define EJERCICIO3_H_INCLUDED
#include <cassert>

template <typename T> class BicolaD {
    public:
        BicolaD(); // constructor
        BicolaD(const BicolaD<T>& C); // ctor. de copia
        BicolaD<T>& operator =(const BicolaD<T>& C); // asignación de colas
        bool vacia() const;
        const T& frenteIzq() const;
        const T& frenteDer() const;
        void popIzq();
        void pushIzq(const T& x);
        void popDer();
        void pushDer(const T& x);
        ~BicolaD(); // destructor

    private:
        struct nodo {
            T elto;
            nodo* sig;
            nodo* ant;
            nodo(const T& e, nodo* s = 0, nodo* a = 0): elto(e), sig(s), ant(a) {}
        };
        nodo *izq, *der; // extremos de la cola
        void copiar(const BicolaD<T>& C);
        };

        // Método privado
template <typename T>
void BicolaD<T>::copiar(const BicolaD<T>& C) {
    if (C.izq) { // C no está vacía
        // Copiar el primer elto.
        izq = der = new nodo(C.izq->elto);
        // Copiar el resto de elementos hasta el ﬁnal de la cola.
        for (nodo *p = C.izq->sig; p; p = p->sig) {
            der->sig = new nodo(p->elto);
            der = der->sig;
        }
    }
}

template <typename T> inline BicolaD<T>::BicolaD() : izq(0), der(0) {}

template <typename T> inline BicolaD<T>::BicolaD(const BicolaD<T>& C) : izq(0), der(0) {
    copiar(C);
}

template <typename T> inline BicolaD<T>& BicolaD<T>::operator =(const BicolaD<T>& C) {
    if (this != &C) { // evitar autoasignación
        this->~BicolaD(); // vaciar la cola actual
        copiar(C);
    }
    return *this;
}

template <typename T> inline bool BicolaD<T>::vacia() const {
    return (izq == der == 0);
}

template <typename T> inline const T& BicolaD<T>::frenteIzq() const {
    assert(!vacia());
    return izq->elto;
}

template <typename T> inline const T& BicolaD<T>::frenteDer() const {
    assert(!vacia());
    return der->elto;
}

template <typename T> inline void BicolaD<T>::popIzq() {
    assert(!vacia());
    nodo* p = izq;
    izq = p->sig;
    if (!izq) der = 0;
    delete p;
}

template <typename T> inline void BicolaD<T>::popDer() {
    assert(!vacia());
    nodo* p = der;
    der = p->ant;
    if (!der) izq = 0;
    delete p;
}

template <typename T> inline void BicolaD<T>::pushDer(const T& x) {
    nodo* p = new nodo(x);
    if (izq == 0) // bicola vacía
        izq = der = p;
    else {  p->sig = 0;
            p->ant = der;
            der = der->sig = p;
        }
}

template <typename T> inline void BicolaD<T>::pushIzq(const T& x) {
    nodo* p = new nodo(x);
    if (der == 0) // bicola vacía
        der = izq = p;
    else {  p->ant = 0;
            p->sig = izq;
            izq = izq->ant = p;
        }
}

// Destructor: vacía la bicola
template <typename T> BicolaD<T>::~BicolaD() {
    nodo* p;
    while (izq) {
        p = izq->sig;
        delete izq;
        izq = p;
    }
    der = 0;
}

#endif // EJERCICIO3_H_INCLUDED
