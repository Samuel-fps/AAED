#ifndef TADLISTADINAMICA_H_INCLUDED
#define TADLISTADINAMICA_H_INCLUDED
#include <cassert>

//LISTA DOBLEMENTE ENLAZADA CON CABECERA

template <typename T> class Lista {
    struct nodo; // declaración adelantada privada
    public:
        typedef nodo* posicion; // posición de un elemento
        Lista(); // constructor, requiere ctor. T()
        Lista(const Lista<T>& l); // constructor de copia, requier ctor. T()
        Lista<T>& operator =(const Lista<T>& l); // asignación entre listas
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const; // acceso a elto, lectura
        T& elemento(posicion p); // acceso a elto, lectura/escritura
        posicion buscar(const T& x) const; // T requiere operador ==
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        posicion primera() const;
        posicion fin() const; // posición después del último
        ~Lista(); // destructor
    private:
        struct nodo {
            T elto;
            nodo *ant, *sig;
            nodo(const T& e, nodo* a = 0, nodo* s = 0): elto(e), ant(a), sig(s) {}
        };
    nodo* L; // lista doblemente enlazada de nodos

    void copiar(const Lista<T>& l);
};

// Método privado
template <typename T> void Lista<T>::copiar(const Lista<T> &l) {
    L = new nodo(T()); // crear el nodo cabecera
    L->ant = L->sig = L; // estructura circular
    // Copiar elementos de l
    for (nodo* q = l.L->sig; q != l.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}

template <typename T> inline Lista<T>::Lista() : L(new nodo(T())) {
     L->ant = L->sig = L; // estructura circular
}

template <typename T> inline Lista<T>::Lista(const Lista<T>& l) {
     copiar(l);
}

template <typename T> Lista<T>& Lista<T>::operator =(const Lista<T>& l) {
    if (this != &l) { // evitar autoasignación
        this->~Lista(); // vaciar la lista actual
    copiar(l);
    }
    return *this;
}

template <typename T> void Lista<T>::insertar(const T& x, Lista<T>::posicion& p) {
    p->sig = p->sig->ant = new nodo(x, p, p->sig);
    // el nuevo nodo con x queda en la posición p
}

template <typename T> void Lista<T>::eliminar(Lista<T>::posicion& p) {
    assert(p->sig != L); // p no es ﬁn
    nodo* q = p->sig;
    p->sig = q->sig;
    p->sig->ant = p;
    delete q;
    // el nodo siguiente queda en la posición p
}

template <typename T> inline const T& Lista<T>::elemento(Lista<T>::posicion p) const {
    assert(p->sig != L); // p no es ﬁn
    return p->sig->elto;
}

template <typename T> inline T& Lista<T>::elemento(Lista<T>::posicion p) {
    assert(p->sig != L); // p no es ﬁn
    return p->sig->elto;
}

template <typename T> typename Lista<T>::posicion Lista<T>::buscar(const T& x) const {
    nodo* q = L;
    bool encontrado = false;
    while (q->sig != L && !encontrado)
    if (q->sig->elto == x)
    encontrado = true;
    else q = q->sig;
    return q;
}

template <typename T> inline typename Lista<T>::posicion Lista<T>::siguiente(Lista<T>::posicion p) const {
     assert(p->sig != L); // p no es ﬁn
     return p->sig;
}

template <typename T> inline typename Lista<T>::posicion Lista<T>::anterior(Lista<T>::posicion p) const {
    assert(p != L); // p no es la primera posición
    return p->ant;
}

template <typename T> inline typename Lista<T>::posicion Lista<T>::primera() const  {
    return L;
}

template <typename T> inline typename Lista<T>::posicion Lista<T>::fin() const {
    return L->ant;
}

// Destructor: Vacía la lista y destruye el nodo cabecera
template <typename T> Lista<T>::~Lista() {
    nodo* q;
    while (L->sig != L) {
        q = L->sig;
        L->sig = q->sig;
        delete q;
    }
    delete L;
}


#endif // TADLISTADINAMICA_H_INCLUDED
