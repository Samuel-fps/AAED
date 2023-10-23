#ifndef COCINA_HPP
#define COCINA_HPP

#include "../TADs/ListaPseudo.h"

#include <cassert>

/*
DEFINICION
    Cocina: Una cocina es un conjunto de M colocados en una pared de x longitud.

    Mueble: Un mueble se coloca en una posicion de la cocina y tienen una anchura determinada.

ESPECIFICACION
    Cocina(unsigned l)
        Post: Crea una Cocina vacia.
    bool colocable(const mueble& m)
        Pre:  El mueble m tiene una posicion y una anchura.
        Post: Devuelve verdadero si se puede colocar en la cocina o falso si no puede.
    void colocar(const mueble& m)
        Pre:  El mueble tiene posicion, altura y es colocable en la cocina.
        Post: Se coloca el mueble en su posicion.
    const Mueble& mueble(int i)
        Pre:  Existe un mueble en la posicion i.
        Post: Devuelve el mueble colocado en la posicion i.
    void eliminarMueble(int i)
        Pre:  Existe un mueble en la posicion i.
        Post: Se elimina el mueble situado en la posicion i.
    void moverMueble()
        Pre:  Existe un mueble en la posicion i.
        Post: Se mueve el mueble en la posicion i hacia la derecha hasta llegar 
              al mueble i-1 o hasta el extremo izquierdo de la pared.
    ~Cocina()
        Post: Elimina la cocina.
    
TADS CONOCIDOS (Lista representacion vectorial)
    class Lista {
        private:
            T* elementos; // Vector de elementos
            size_t Lmax; // Tamaño del vector
            size_t n; // Número de elementos
    };
    template <typename T> Lista();
    template <typename T> T& elemento(Lista<T>::posicion p);
    template <typename T> void insertar(const T& x, Lista<T>::posicion);
    template <typename T> void eliminar(Lista<T>::posicion);
    template <typename T> bool vacia();
    template <typename T> Lista<T>::posicion primera();
    template <typename T> Lista<T>::posicion fin();
    template <typename T> Lista<T>::posicion siguiente();
    template <typename T> Lista<T>::posicion anterior();

*/

struct Mueble {
    Mueble(size_t p, unsigned a) : pos(p), anchura(a) {}
    size_t pMueble;
    unsigned anchura;
};

class Cocina {
    public:
        typedef Lista<Mueble>::posicion PosMueble;

        Cocina(size_t l);
        bool colocable(const Mueble& m);
        void colocar(const Mueble& m);
        const Mueble& mueble(size_t i);
        void eliminarMueble(size_t i);
        void moverMueble(size_t i);
        ~Cocina();

    private:
        size_t longitud;
        Lista<Mueble> M;
};

Cocina::Cocina(size_t l) : longitud(l), M(l) {}

bool Cocina::colocable(const Mueble& m){
    bool posible = true;
    if(M.primera() == M.fin() && m.pMueble + m.anchura <= longitud) // Si la lista esta vacia y cabe el objeto se devuelve true
        return true;

    PosMueble pos = M.primera();
    while(pos != M.fin() && posible){ // Recorremos en busca de la posicion del mueble
        if(m.pMueble == M.elemento(pos).pMueble && m.pMueble + m.anchura > M.elemento(M.siguiente(pos)).pMueble)
            posible = false; 
        pos = M.siguiente(pos);
    }
    return posible;
}

void Cocina::colocar(const Mueble& m){
    assert(colocable(m));
    M.insertar(m, m.pMueble);
}

const Mueble& Cocina::mueble(size_t i){
    return M.elemento(i); 
}

void Cocina::eliminarMueble(size_t i){ // (Lista<Mueble>::posicion i)
    M.eliminar(i);
}

void Cocina::moverMueble(size_t i){ // (Lista<Mueble>::posicion i)
    Mueble muebleIzq =  M.elemento(M.anterior(i));
    M.elemento(i).pMueble = muebleIzq.pMueble + muebleIzq.anchura;
}

Cocina::~Cocina(){}

#endif