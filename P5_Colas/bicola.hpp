#include "colaEnla.hpp"

template <typename T>
class Bicola {
    public:
        // void Bicola(); No es necesario definirlo
        void pushFin(T);
        void pushFrente(T){ cola.push(T); }
        void popFin();
        void popFrente(){ cola.pop(); }
        T frente(){ return cola.frente(); }
        T fin();
    private:
        struct nodo {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = nullptr) : elto(e), sig(p) {}
    };

    nodo *fin; // Extremos de la cola
    size_t n_eltos; // Tamaño de la cola

    void copiar(const Cola& C);
};

template <typename T>
void pushFin(T){
    
}

template <typename T>
void popFin(){

}

template <typename T>
inline Cola<T>::Cola() :
    inicio(nullptr),
    n_eltos(0)
{}

template <typename T>
inline bool Cola<T>::vacia() const
{
    return inicio == nullptr;
}

template <typename T>
inline size_t Cola<T>::tama() const
{
    return n_eltos;
}

template <typename T>
inline const T& Cola<T>::frente() const
{
    assert(!vacia());
    return inicio->elto;
}

template <typename T>
inline void Cola<T>::pop()
{
    assert(!vacia());
    nodo* p = inicio;
    inicio = p->sig;
    delete p;
    --n_eltos;
}

template <typename T>
inline void Cola<T>::push(const T& x)
{
    if (vacia())
        inicio = fin = new nodo(x);
    else
        fin = fin->sig = new nodo(x);
    ++n_eltos;
}

// Constructor de copia
template <typename T>
inline Cola<T>::Cola(const Cola& C) : Cola()
{
    copiar(C);
}

// Asignación entre colas
template <typename T>
inline Cola<T>& Cola<T>::operator =(const Cola& C)
{
    if (this != &C) { // Evitar autoasignación
        this->~Cola(); // Vaciar la cola actual
        copiar(C);
    }
    return *this;
}

// Destructor: vacía la cola
template <typename T>
Cola<T>::~Cola()
{
    nodo* p;
    while (inicio) {
        p = inicio->sig;
        delete inicio;
        inicio = p;
    }
    n_eltos = 0;
}

// Método privado
template <typename T>
void Cola<T>::copiar(const Cola& C)
{
    if (!C.vacia()) {
        // Copiar el primer elto.
        inicio = fin = new nodo(C.inicio->elto);
        n_eltos = 1;
        // Copiar el resto de elementos hasta el final de C.
        for (nodo* p = C.inicio->sig; p; p = p->sig, ++n_eltos)
            fin = fin->sig = new nodo(p->elto);
    }
}
