#ifndef TADLISTACIRCULAR_H_INCLUDED
#define TADLISTACIRCULAR_H_INCLUDED
#include <cassert>

//LISTA CIRCULAR DOBLEMENTE ENLAZADA

template <typename T> class ListaCir {
    struct nodo; // declaración adelantada privada
    public:
        typedef nodo* posicion; // posición de un elemento
        ListaCir(); // constructor, requiere ctor. T()
        ListaCir(const ListaCir<T>& l); // constructor de copia, requier ctor. T()
        ListaCir<T>& operator =(const ListaCir<T>& l); // asignación entre listas
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const; // acceso a elto, lectura
        T& elemento(posicion p); // acceso a elto, lectura/escritura
        posicion buscar(const T& x) const; // T requiere operador ==
        posicion inipos() const; // devuelve L
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        ~ListaCir(); // destructor
    private:
        struct nodo {
            T elto;
            nodo *ant, *sig;
            nodo(const T& e, nodo* a = 0, nodo* s = 0): elto(e), ant(a), sig(s) {}
        };
    nodo* L; // lista doblemente enlazada de nodos
    const posicion POS_NULA = 0;

    void copiar(const ListaCir<T>& l);
};

// Método privado
template <typename T> void ListaCir<T>::copiar(const ListaCir<T> &l) {
    // Copiar elementos de l
    for (nodo* q = l.L->sig; q != l.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}

template <typename T> inline ListaCir<T>::ListaCir() : L(0) {
}

template <typename T> inline ListaCir<T>::ListaCir(const ListaCir<T>& l) {
     copiar(l);
}

template <typename T> ListaCir<T>& ListaCir<T>::operator =(const ListaCir<T>& l) {
    if (this != &l) { // evitar autoasignación
        this->~ListaCir(); // vaciar la lista actual
        copiar(l);
    }
    return *this;
}

template <typename T> void ListaCir<T>::insertar(const T& x, ListaCir<T>::posicion p) {
    if (L == 0){
        L = new nodo(x);
        L->sig = L->ant = L;
    } else
        p->ant->sig = p->sig = new nodo(x, p, p->sig);
}

template <typename T> void ListaCir<T>::eliminar(ListaCir<T>::posicion p) {
    assert(p != POS_NULA);
    nodo* q = p->sig;
    p->sig = q->sig;
    p->sig->ant = p;
    delete q;
    // el nodo siguiente queda en la posición p
}

template <typename T> inline const T& ListaCir<T>::elemento(ListaCir<T>::posicion p) const {
    return p->sig->elto;
}

template <typename T> inline T& ListaCir<T>::elemento(ListaCir<T>::posicion p) {
    return p->sig->elto;
}

template <typename T> typename ListaCir<T>::posicion ListaCir<T>::buscar(const T& x) const {
   nodo* q = L;
    bool encontrado = false;
    while (q->sig != L && !encontrado){
        if (q->sig->elto == x)
            encontrado = true;
        else q = q->sig;
    }
    if (q->sig == L && q->elto != x) q = POS_NULA; //POS_NULA

    return q;
}

template <typename T> inline typename ListaCir<T>::posicion ListaCir<T>::inipos() const {
    return L;
}

template <typename T> inline typename ListaCir<T>::posicion ListaCir<T>::siguiente(ListaCir<T>::posicion p) const {
     return p->sig;
}

template <typename T> inline typename ListaCir<T>::posicion ListaCir<T>::anterior(ListaCir<T>::posicion p) const {
    return p->ant;
}

// Destructor: Vacía la lista y destruye el nodo cabecera
template <typename T> ListaCir<T>::~ListaCir() {
    nodo* q;
    while (L->sig != L) {
        q = L->sig;
        L->sig = q->sig;
        delete q;
    }
    delete L;
}


#endif // TADLISTACIRCULAR_H_INCLUDED
