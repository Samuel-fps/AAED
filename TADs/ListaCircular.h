#ifndef LISTACULAR_H_INCLUDED
#define LISTACULAR_H_INCLUDED
#include <cassert>

//LISTA CIRCULAR SIMPLEMENTE ENLAZADA

template <typename T> class Lista {
    struct nodo; // declaraci�n adelantada privada
    public:
        typedef nodo* posicion; // posici�n de un elemento
        Lista(); // constructor, requiere ctor. T()
        Lista(const Lista<T>& l); // constructor de copia, requier ctor. T()
        Lista<T>& operator =(const Lista<T>& l); // asignaci�n entre listas
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const; // acceso a elto, lectura
        T& elemento(posicion p); // acceso a elto, lectura/escritura
        posicion buscar(const T& x) const; // T requiere operador ==
        posicion inipos() const; // devuelve L
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        ~Lista(); // destructor
    private:
        struct nodo {
            T elto;
            nodo *sig;
            nodo(const T& e, nodo* s = 0): elto(e), sig(s) {}
        };
    nodo* L; // lista doblemente enlazada de nodos
    const posicion POS_NULA = 0;

    void copiar(const Lista<T>& l);
};

// M�todo privado
template <typename T> void Lista<T>::copiar(const Lista<T> &l) {
    // Copiar elementos de l
    nodo* q = L;
    for (nodo* r = l.L->sig; r; r = r->sig) {
        q-> sig =new nodo (r->elto);
        q = q->sig;
    }
}

template <typename T> inline Lista<T>::Lista() : L(0) {
}

template <typename T> inline Lista<T>::Lista(const Lista<T>& l) {
     copiar(l);
}

template <typename T> Lista<T>& Lista<T>::operator =(const Lista<T>& l) {
    if (this != &l) { // evitar autoasignaci�n
        this->~Lista(); // vaciar la lista actual
        copiar(l);
    }
    return *this;
}

template <typename T> void Lista<T>::insertar(const T& x, Lista<T>::posicion p) {
    if (L == 0){
        L = new nodo(T());
        L->sig = L;
        L->elto = x;
    } else
        p->sig = new nodo(x, p->sig);
}

template <typename T> void Lista<T>::eliminar(Lista<T>::posicion p) {
    assert(p != POS_NULA);
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
    // el nodo siguiente queda en la posici�n p
}

template <typename T> inline const T& Lista<T>::elemento(Lista<T>::posicion p) const {
    return p->sig->elto;
}

template <typename T> inline T& Lista<T>::elemento(Lista<T>::posicion p) {
    return p->sig->elto;
}

template <typename T> typename Lista<T>::posicion Lista<T>::buscar(const T& x) const {
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

template <typename T> inline typename Lista<T>::posicion Lista<T>::inipos() const {
    return L;
}

template <typename T> inline typename Lista<T>::posicion Lista<T>::siguiente(Lista<T>::posicion p) const {
     return p->sig;
}

template <typename T> inline typename Lista<T>::posicion Lista<T>::anterior(Lista<T>::posicion p) const {
    nodo *q;

    for (q = L; q->sig != p; q = q->sig);
    return q;
}

// Destructor: Vac�a la lista y destruye el nodo cabecera
template <typename T> Lista<T>::~Lista() {
    nodo* q;
    while (L->sig != L) {
        q = L->sig;
        L->sig = q->sig;
        delete q;
    }
    delete L;
}


#endif
