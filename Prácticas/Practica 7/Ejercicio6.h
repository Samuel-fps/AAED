#ifndef TADCONJUNTO_H_INCLUDED
#define TADCONJUNTO_H_INCLUDED
#include <cassert>
#include <stdlib.h>

//CONJUNTO SIMPLEMENTE ENLAZADO CON CABECERA

template <typename T> class Conjunto {
    struct nodo; // declaración adelantada privada
    public:
        typedef nodo* posicion; // posición de un elemento
        Conjunto(); // constructor, requiere ctor. T()
        Conjunto(const Conjunto<T>& l); // constructor de copia, requier ctor. T()
        Conjunto<T>& operator =(const Conjunto<T>& l); // asignación entre listas
        void insertar(const T& x);
        void eliminar(const T& x);
        const T& elemento(posicion p) const; // acceso a elto, lectura
        T& elemento(posicion p); // acceso a elto, lectura/escritura
        posicion buscar(const T& x) const; // T requiere operador ==
        posicion primera() const;
        posicion fin() const; // posición después del último
        Conjunto<T>& operator +(const Conjunto<T>& c1);  //Unión
        Conjunto<T>& operator /(const Conjunto<T>& c1);  //Intersección
        Conjunto<T>& operator -(const Conjunto<T>& c1);  //Diferencia
        void mostrar();
        ~Conjunto(); // destructor
    private:
        struct nodo {
            T elto;
            nodo *sig;
            nodo(const T& e, nodo* s = 0): elto(e), sig(s) {}
        };
        nodo* L; // lista simplemente enlazada de nodos

        void copiar(const Conjunto<T>& l);
};

// Método privado
template <typename T> void Conjunto<T>::copiar(const Conjunto<T> &l) {
    L = new nodo(T()); // crear el nodo cabecera
    //L->sig = L; // estructura circular
    // Copiar elementos de l
    for (nodo* q = l.L->sig; q != l.L; q = q->sig)
        L->sig = new nodo(q->elto, L);
}

template <typename T> inline Conjunto<T>::Conjunto() : L(new nodo(T())) {
     L->sig = L; // estructura circular
}

template <typename T> inline Conjunto<T>::Conjunto(const Conjunto<T>& l) {
     copiar(l);
}

template <typename T> Conjunto<T>& Conjunto<T>::operator =(const Conjunto<T>& l) {
    if (this != &l) { // evitar autoasignación
        this->~Conjunto(); // vaciar la lista actual
    copiar(l);
    }
    return *this;
}

template <typename T> void Conjunto<T>::insertar(const T& x) {
    nodo* p;
    for(p = L; p->sig != L; p = p->sig)
        if(p->elto == x) return;

    L->sig = new nodo(x, L->sig);
    // el nuevo nodo con x queda en la posición p
}

template <typename T> void Conjunto<T>::eliminar(const T& x) {
    nodo* p;
    for(p = L; p->sig; p = p->sig)
        if(p->elto == x) {
            nodo* q = p->sig;
            p->sig = q->sig;
            delete q;
        }
    // el nodo siguiente queda en la posición p
}

template <typename T> inline const T& Conjunto<T>::elemento(Conjunto<T>::posicion p) const {
    assert(p->sig != L); // p no es fin
    return p->sig->elto;
}

template <typename T> inline T& Conjunto<T>::elemento(Conjunto<T>::posicion p) {
    assert(p->sig != L); // p no es fin
    return p->sig->elto;
}

template <typename T> typename Conjunto<T>::posicion Conjunto<T>::buscar(const T& x) const {
    nodo* q = L;
    bool encontrado = false;

    while (q->sig != L && !encontrado)
        if (q->sig->elto == x)
            encontrado = true;
        else q = q->sig;

    return q;
}

template <typename T> inline typename Conjunto<T>::posicion Conjunto<T>::primera() const  {
    return L;
}

template <typename T> inline typename Conjunto<T>::posicion Conjunto<T>::fin() const {
    nodo* p;
    for(p = L; p->sig; p = p->sig);
    return p;
}

template <typename T> Conjunto<T>& operator +(const Conjunto<T>& c1){
    Conjunto<T> c3(this);
    posicion p;

    for( p = c1.L; p->sig != c1.L; p = p->sig ){
        if( !this.buscar(c1.elemento(p))) c3.insertar(c1.elemento(p));
    }

    return c3;
}

template <typename T> Conjunto<T>& operator /(const Conjunto<T>& c1){
    Conjunto<T> c3();
    posicion p;

    for( p = c1.L; p->sig != c1.L; p = p->sig ){
        if( this.buscar(c1.elemento(p)) ) c3.insertar(c1.elemento(p));
    }

    return c3;
}

template <typename T> Conjunto<T>& operator -(const Conjunto<T>& c1){
    Conjunto<T> c3();
    posicion p;

    for( p = c1.L; p->sig != c1.L; p = p->sig ){
        if( !this.buscar(c1.elemento(p)) ) c3.insertar(c1.elemento(p));
    }
    for( p = this.L; p->sig != this.L; p = p->sig ){
        if( !c1.buscar(this.elemento(p)) ) c3.insertar(this.elemento(p));
    }

    return c3;
}

template <typename T> void Conjunto<T>::mostrar (){
    posicion p;
    for( p = L; p->sig != L; p = p->sig )
        std::cout << p->sig->elto << " ";

    std::cout << std::endl;

}

// Destructor: Vacía la lista y destruye el nodo cabecera
template <typename T> Conjunto<T>::~Conjunto() {
    nodo* q;
    while (L->sig != L) {
        q = L->sig;
        L->sig = q->sig;
        delete q;
    }
    delete L;
}


#endif // TADCONJUNTO_H_INCLUDED
