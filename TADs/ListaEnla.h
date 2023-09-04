#ifndef LISTA_ENLA_H
#define LISTA_ENLA_H

#include <cassert>

template <typename T>
class Lista {
private:
    struct nodo; // Declaración adelantada privada
public:
    typedef nodo* posicion; // Posición de un elemento

    Lista(); // Constructor, requiere ctor. T()
    Lista(const Lista<T>& Lis); // Ctor. de copia, requiere ctor. T()
    Lista<T>& operator=(const Lista<T>& Lis); // Asig. de listas
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const; // Lec. elto. en Lista const
    T& elemento(posicion p); // Lec/Esc elto. en Lista no−const
    posicion Lista<T>::buscar(const T& x) const;
    posicion Lista<T>::siguiente(Lista<T>::posicion p) const;
    posicion Lista<T>::anterior(Lista<T>::posicion p) const;
    posicion Lista<T>::primera() const;
    posicion Lista<T>::fin() const;
    ~Lista();

private:
    struct nodo {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = nullptr) : elto(e), sig(p) {}
    };

    nodo* L; // Lista enlazada

    void copiar(const Lista<T>& Lis);
};

// Método privado para copiar una lista en otra
template <typename T>
void Lista<T>::copiar(const Lista<T> &Lis) {
    L = new nodo(T()); // Crear el nodo cabecera
    nodo* q = L;
    for (nodo* r = Lis.L->sig; r; r = r->sig) {
        q->sig = new nodo(r->elto);
        q = q->sig;
    }
}

// Constructor por defecto: crear una lista vacía con un nodo cabecera
template <typename T>
inline Lista<T>::Lista() : L(new nodo(T())) {}

// Constructor de copia: crear una nueva lista a partir de otra
template <typename T>
inline Lista<T>::Lista(const Lista<T>& Lis) {
    copiar(Lis);
}

// Operador de asignación: asignar una lista a otra
template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& Lis) {
    if (this != &Lis) { // Evitar autoasignación
        this->~Lista(); // Vaciar la lista actual
        copiar(Lis);
    }
    return *this;
}

// Destructor: liberar la memoria utilizada por la lista
template <typename T>
Lista<T>::~Lista() {
    while (L) {
        nodo* q = L;
        L = L->sig;
        delete q;
    }
}

// Insertar un elemento en una posición dada
template <typename T>
inline void Lista<T>::insertar(const T& x, Lista<T>::posicion p) {
    p->sig = new nodo(x, p->sig);
    // El nuevo nodo con x queda en la posición p
}

// Eliminar un elemento de una posición dada
template <typename T>
inline void Lista<T>::eliminar(Lista<T>::posicion p) {
    assert(p->sig); // p no es fin
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
    // El nodo siguiente queda en la posición p
}

// Obtener una referencia al elemento en una posición dada (const)
template <typename T>
inline const T& Lista<T>::elemento(Lista<T>::posicion p) const {
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

// Obtener una referencia al elemento en una posición dada (no-const)
template <typename T>
inline T& Lista<T>::elemento(Lista<T>::posicion p) {
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

// Buscar un elemento en la lista
template <typename T>
typename Lista<T>::posicion Lista<T>::buscar(const T& x) const {
    nodo* q = L;
    bool encontrado = false;
    while (q->sig && !encontrado) {
        if (q->sig->elto == x) {
            encontrado = true;
        } else {
            q = q->sig;
        }
    }
    return q;
}

// Obtener la posición siguiente a una posición dada
template <typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(Lista<T>::posicion p) const {
    assert(p->sig); // p no es fin
    return p->sig;
}

// Obtener la posición anterior a una posición dada
template <typename T>
typename Lista<T>::posicion Lista<T>::anterior(Lista<T>::posicion p) const {
    nodo* q;
    assert(p != L); // p no es la primera posición
    for (q = L; q->sig != p; q = q->sig);
    return q;
}

// Obtener la primera posición de la lista
template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const {
    return L;
}

// Obtener la posición después del último elemento
template <typename T>
typename Lista<T>::posicion Lista<T>::fin() const {
    nodo* p;
    for (p = L; p->sig; p = p->sig);
    return p;
}

// Destructor: destruye el nodo cabecera y vacía la lista
template <typename T>
Lista<T>::~Lista() {
    nodo* q;
    while (L) {
        q = L->sig;
        delete L;
        L = q;
    }
}

#endif