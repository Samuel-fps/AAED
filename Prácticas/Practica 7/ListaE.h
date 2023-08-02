#ifndef TADLISTAESTATICA_H_INCLUDED
#define TADLISTAESTATICA_H_INCLUDED
#include <cassert>

template <typename T> class ListaE {
    public:
        typedef int posicion; // posición de un elto
        explicit ListaE<T>(size_t TamaMax); // constructor
        ListaE(const ListaE<T>& l); // ctor. de copia
        ListaE& operator =(const ListaE<T>& l); // asignación entre listas
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const; // acceso a elto, lectura
        T& elemento(posicion p); // acceso a elto, lectura/escritura
        posicion buscar(const T& x) const; // requiere operador == para el tipo T
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        posicion primera() const;
        posicion fin() const; // posición después del último
        ~ListaE(); // destructor
    private:
        T *elementos; // vector de elementos
        int Lmax; // tamaño del vector
        int n; // longitud de la lista
};

/* clase ListaE genérica: vector pseudo−estático.
Una lista de longitud n se almacena en celdas
consecutivas del vector, desde 0 hasta n−1. La
posición de un elemento es el índice de la celda
en que se almacena.*/

// Implementación de operaciones
template <typename T> inline ListaE<T>::ListaE(size_t TamaMax) : elementos(new T[TamaMax]), Lmax(TamaMax), n(0) {}

template <typename T> ListaE<T>::ListaE(const ListaE<T>& l) : elementos(new T[l.Lmax]), Lmax(l.Lmax), n(l.n) {
    for (ListaE<T>::posicion p = 0; p < n; p++) // copiar el vector
    elementos[p] = l.elementos[p];
}
template <typename T> ListaE<T>& ListaE<T>::operator =(const ListaE<T>& l) {
    if (this != &l) { // evitar autoasignación
    // Destruir el vector y crear uno nuevo si es necesario
        if (Lmax != l.Lmax) {
            delete[] elementos;
            Lmax = l.Lmax;
            elementos = new T[Lmax];
        }
        // Copiar el vector
        n = l.n;
        for (ListaE<T>::posicion p = 0; p < n; p++)
            elementos[p] = l.elementos[p];
    }
    return *this;
}

template <typename T> void ListaE<T>::insertar(const T& x, ListaE<T>::posicion p) {
    assert(p >= 0 && p <= n); // posición válida
    assert(n < Lmax); // lista no llena
    for (ListaE<T>::posicion q = n; q > p; q--)
        // desplazar los eltos. en p, p+1, ...
        elementos[q] = elementos[q-1]; // a la siguiente posición
    elementos[p] = x;
    n++;
}

template <typename T> void ListaE<T>::eliminar(ListaE<T>::posicion p) {
        assert(p >= 0 && p < n); // posición válida
        n--;
        for (ListaE<T>::posicion q = p; q < n; q++)
        //desplazar los eltos. en p+1, p+2, ...
        elementos[q] = elementos[q+1]; // a la posición anterior
}

template <typename T> inline const T& ListaE<T>::elemento(ListaE<T>::posicion p) const {
    assert(p >= 0 && p < n); // posición válida
    return elementos[p];
}

template <typename T> inline T& ListaE<T>::elemento(ListaE<T>::posicion p) {
    assert(p >= 0 && p < n); // posición válida
    return elementos[p];
}

template <typename T> typename ListaE<T>::posicion ListaE<T>::buscar(const T& x) const {
    ListaE<T>::posicion q = 0;
    bool encontrado = false;
    while (q < n && !encontrado)
    if (elementos[q] == x)
    encontrado = true;
    else q++;
    return q;
}

template <typename T> inline typename ListaE<T>::posicion ListaE<T>::siguiente(ListaE<T>::posicion p) const {
    assert(p >= 0 && p < n); // posición válida
    return p+1;
}

template <typename T> inline typename ListaE<T>::posicion ListaE<T>::anterior(ListaE<T>::posicion p) const {
    assert(p > 0 && p <= n); // posición válida
    return p-1;
}

template <typename T> inline typename ListaE<T>::posicion ListaE<T>::primera() const {
    return 0;
}

template <typename T> inline typename ListaE<T>::posicion ListaE<T>::fin() const {
    return n;
}

template <typename T> inline ListaE<T>::~ListaE() {
    delete[] elementos;
}


#endif // TADLISTAESTATICA_H_INCLUDED
