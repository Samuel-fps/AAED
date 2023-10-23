
#include <cassert>

template <typename T>
    class Lista {
    public:
        typedef size_t posicion; // Posición de un elemento
        explicit Lista(size_t TamaMax); // Constructor, req. ctor. T()
        Lista(const Lista<T>& L); // Ctor. de copia, requiere ctor. T()
        Lista<T>& operator=(const Lista<T>& L); // Asig, req. ctor. T()
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const; // Lec. elto. en Lista const
        T& elemento(posicion p); // Lec/Esc elto. en Lista no−const
        posicion buscar(const T& x) const; // Req. operador == para T
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        posicion primera() const;
        posicion fin() const; // Posición después del último
        ~Lista(); // Destructor

    private:
        T* elementos; // Vector de elementos
        size_t Lmax; // Tamaño del vector
        size_t n; // Número de elementos
};


// Constructor: Inicializa la lista con el tamaño máximo TamaMax
template <typename T>
inline Lista<T>::Lista(size_t TamaMax) :
    elementos(new T[TamaMax]),
    Lmax(TamaMax),
    n(0)
{}


// Constructor de copia: crea una copia de la lista L
template <typename T>
Lista<T>::Lista(const Lista<T>& L) :
    elementos(new T[L.Lmax]),
    Lmax(L.Lmax),
    n(L.n)
{
    for (Lista<T>::posicion p = 0; p < n; ++p) // Copiar elementos.
        elementos[p] = L.elementos[p];
}


// Operador de asignación: asigna una copia de la lista L a la lista actual
template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& L) {
    if (this != &L) { // Evitar autoasignación
        // Destruir el vector y crear uno nuevo si es necesario
        if (Lmax != L.Lmax) {
            delete[] elementos;
            Lmax = L.Lmax;
            elementos = new T[Lmax];
        }
        n = L.n;
        // Copiar elementos
        for (Lista<T>::posicion p = 0; p < n; ++p)
            elementos[p] = L.elementos[p];
    }
    return *this;
}


// Insertar elemento x en la posición p
template <typename T>
void Lista<T>::insertar(const T& x, Lista<T>::posicion p) {
    assert(p >= 0 && p <= n); // Posición válida
    assert(n < Lmax); // Lista no llena
    // Desplazar los elementos en p, p+1,..., n−1, a la siguiente posición
    for (Lista<T>::posicion q = n; q > p; --q)
        elementos[q] = elementos[q - 1];
    elementos[p] = x;
    ++n;
}

// Eliminar el elemento en la posición p
template <typename T>
void Lista<T>::eliminar(Lista<T>::posicion p) {
    assert(p >= 0 && p < n); // Posición válida
    --n;
    // Desplazar los elementos en p+1, p+2,...,n a la posición anterior
    for (Lista<T>::posicion q = p; q < n; ++q)
        elementos[q] = elementos[q + 1];
}


// Acceder al elemento en la posición p (constante)
template <typename T>
inline const T& Lista<T>::elemento(Lista<T>::posicion p) const {
    assert(p >= 0 && p < n); // Posición válida
    return elementos[p];
}

// Acceder al elemento en la posición p (mutable)
template <typename T>
inline T& Lista<T>::elemento(Lista<T>::posicion p) {
    assert(p >= 0 && p < n); // Posición válida
    return elementos[p];
}


// Buscar el elemento x en la lista y devolver su posición (si se encuentra)
template <typename T>
typename Lista<T>::posicion Lista<T>::buscar(const T& x) const {
    Lista<T>::posicion q = 0;
    bool encontrado = false;
    while (q < n && !encontrado) {
        if (elementos[q] == x)
            encontrado = true;
        else
            ++q;
    }
    return q;
}

// Obtener la posición siguiente a la posición p
template <typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(Lista<T>::posicion p) const {
    assert(p >= 0 && p < n); // Posición válida
    return p + 1;
}


// Obtener la posición anterior a la posición p
template <typename T>
inline typename Lista<T>::posicion Lista<T>::anterior(Lista<T>::posicion p) const {
    assert(p > 0 && p <= n); // Posición válida
    return p - 1;
}

// Obtener la posición de primer elemento de la lista
template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const {
    return 0;
}

// Obtener la posición después del último elemento de la lista
template <typename T>
inline typename Lista<T>::posicion Lista<T>::fin() const {
    return n;
}

// Destructor: liberar la memoria utilizada por la lista
template <typename T>
inline Lista<T>::~Lista() {
    delete[] elementos;
}
