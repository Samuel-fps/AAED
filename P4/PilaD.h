#ifndef PILAD_H
#define PILAD_H
#include <cassert>

template <typename tElemento> class Pila {
public:
    explicit Pila();                   /*Constructor*/
    Pila(const Pila<tElemento>& P);   /*Constructor de copia*/
    Pila<tElemento>& operator= (const Pila<tElemento>& P); //Asignaci�n entre pilas
    bool vacia() const;
    const tElemento& tope() const;
    tElemento pop();
    void push(const tElemento& x);
    ~Pila(); /*Destructor*/
private:
    struct nodo {
        tElemento elto;
        nodo* sig;
        nodo (const tElemento& e, nodo* p = 0): elto(e), sig(p) {}
    };
    nodo* tope_; //Posici�n del tope
    void copiar(const Pila<tElemento>& P);
};

template <typename tElemento>
inline Pila<tElemento>::Pila() : tope_(0) {}

template <typename tElemento>
Pila<tElemento>::Pila(const Pila<tElemento>& P) : tope_(0)
{
    copiar(P);
}

template <typename tElemento>
Pila<tElemento>& Pila<tElemento>::operator= (const Pila<tElemento>& P)
{
    if(this != &P) {    //Evitar autoasignaci�n
        this->~Pila();  //Vaciar la pila actual
        copiar(P);
    }
    return *this;
}

template <typename tElemento>
inline bool Pila<tElemento>::vacia() const
{
    return (!tope_);
}

template <typename tElemento>
inline const tElemento& Pila<tElemento>::tope() const
{
    assert(!vacia());
    return tope_->elto;
}

template <typename tElemento>
inline tElemento Pila<tElemento>::pop()
{
    assert(!vacia());
    nodo* p = tope_;
    tope_ = p->sig;
    tElemento eltoAux = p->elto;
    delete p;
    return eltoAux;
}

template <typename tElemento>
inline void Pila<tElemento>::push(const tElemento& x)
{
    tope_ = new nodo(x, tope_);
}

//Destructor: vac�a la pila
template <typename tElemento>
Pila<tElemento>::~Pila()
{
    nodo* p;
    while(tope_) {
        p = tope_->sig;
        delete tope_;
        tope_ = p;
    }
}

template <typename tElemento> void Pila<tElemento>::copiar(const Pila<tElemento>& P){
    if (!P.vacia()) {
        tope_ = new nodo(P.tope()); //Copiar el primer elto
        //Copiar el resto de elementos hasta el fondo de la pila
        nodo* p = tope_; //Recorre la pila destino
        nodo* q = P.tope_->sig; //2� nodo, recorre la pila origen
        while(q) {
            p->sig = new nodo (q->elto);
            p = p->sig;
            q = q->sig;
        }
    }
}

#endif // TADPILAINAMICA_H
