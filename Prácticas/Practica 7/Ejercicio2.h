#ifndef TADLISTAORDENADA_H_INCLUDED
#define TADLISTAORDENADA_H_INCLUDED
#include <cassert>

#include <stdio.h>

//LISTA ORDENADA DOBLEMENTE ENLAZADA CON CABECERA

template <typename T> class ListaOrd {
    struct nodo; // declaración adelantada privada
    public:
        typedef nodo* posicion; // posición de un elemento
        ListaOrd(); // constructor, requiere ctor. T()
        ListaOrd(const ListaOrd<T>& l); // constructor de copia, requier ctor. T()
        ListaOrd<T>& operator =(const ListaOrd<T>& l); // asignación entre listas
        void insertar(const T& x);  //Requiere el operador < de T
        void eliminar(posicion p);
        const T& elemento(posicion p) const; // acceso a elto, lectura
        T& elemento(posicion p); // acceso a elto, lectura/escritura
        posicion buscar(const T& x) const; // T requiere operador ==
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        posicion primera() const;
        posicion fin() const; // posición después del último
        ~ListaOrd(); // destructor
    private:
        struct nodo {
            T elto;
            nodo *ant, *sig;
            nodo(const T& e, nodo* a = 0, nodo* s = 0): elto(e), ant(a), sig(s) {}
        };
    nodo* L; // lista doblemente enlazada de nodos

    void copiar(const ListaOrd<T>& l);
};

// Método privado
template <typename T> void ListaOrd<T>::copiar(const ListaOrd<T> &l) {
    L = new nodo(T()); // crear el nodo cabecera
    L->ant = L->sig = L; // estructura circular
    // Copiar elementos de l
    for (nodo* q = l.L->sig; q != l.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}

template <typename T> inline ListaOrd<T>::ListaOrd() : L(new nodo(T())) {
     L->ant = L->sig = L; // estructura circular
}

template <typename T> inline ListaOrd<T>::ListaOrd(const ListaOrd<T>& l) {
     copiar(l);
}

template <typename T> ListaOrd<T>& ListaOrd<T>::operator =(const ListaOrd<T>& l) {
    if (this != &l) { // evitar autoasignación
        this->~ListaOrd(); // vaciar la lista actual
    copiar(l);
    }
    return *this;
}

template <typename T> void ListaOrd<T>::insertar(const T& x) {
    nodo* p;
    /*if (L->sig == L) {
        p = L;
        p->sig = p->sig->ant = new nodo(x, p, p->sig);
    } else*/
    for(p = L; p->sig->elto < x && p->sig && p->sig != L; p = p->sig);
    p->sig = p->sig->ant = new nodo(x, p, p->sig);
    // el nuevo nodo con x queda en la posición p

}

template <typename T> void ListaOrd<T>::eliminar(ListaOrd<T>::posicion p) {
    assert(p->sig != L); // p no es fin
    nodo* q = p->sig;
    p->sig = q->sig;
    p->sig->ant = p;
    delete q;
    // el nodo siguiente queda en la posición p
}

template <typename T> inline const T& ListaOrd<T>::elemento(ListaOrd<T>::posicion p) const {
    assert(p->sig != L); // p no es fin
    return p->sig->elto;
}

template <typename T> inline T& ListaOrd<T>::elemento(ListaOrd<T>::posicion p) {
    assert(p->sig != L); // p no es fin
    return p->sig->elto;
}

template <typename T> typename ListaOrd<T>::posicion ListaOrd<T>::buscar(const T& x) const {
    nodo* q = L;
    bool encontrado = false;
    while (q->sig != L && !encontrado)
        if (q->sig->elto == x)
            encontrado = true;
        else q = q->sig;
    return q;
}

template <typename T> inline typename ListaOrd<T>::posicion ListaOrd<T>::siguiente(ListaOrd<T>::posicion p) const {
     assert(p->sig != L); // p no es fin
     return p->sig;
}

template <typename T> inline typename ListaOrd<T>::posicion ListaOrd<T>::anterior(ListaOrd<T>::posicion p) const {
    assert(p != L); // p no es la primera posición
    return p->ant;
}

template <typename T> inline typename ListaOrd<T>::posicion ListaOrd<T>::primera() const  {
    return L;
}

template <typename T> inline typename ListaOrd<T>::posicion ListaOrd<T>::fin() const {
    return L->ant;
}

// Destructor: Vacía la lista y destruye el nodo cabecera
template <typename T> ListaOrd<T>::~ListaOrd() {
    nodo* q;
    while (L->sig != L) {
        q = L->sig;
        L->sig = q->sig;
        delete q;
    }
    delete L;
}


#endif // TADLISTAORDENADA_H_INCLUDED
