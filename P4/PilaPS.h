#ifndef PILAPS_H
#define PILAPS_H
#include <cassert>

template <typename tElemento> class Pila {
public:
    explicit Pila(unsigned TamaMax); /*Constructor*/
    Pila(const Pila& P); /*Constructor de copia*/
    Pila& operator= (const Pila& P); //Asignaci�n entre pilas
    bool vacia() const;
    bool llena() const; //Requerida por la implementaci�n
    const tElemento& tope() const;
    void pop();
    void push(const tElemento& x);
    ~Pila(); /*Destructor*/
private:
    tElemento *elementos; //Vector de elementos
    int Lmax; //Tama�o del vector
    int tope_; //Posici�n del tope
};

template <typename tElemento>
inline Pila<tElemento>::Pila(unsigned TamaMax) :
    elementos(new tElemento[TamaMax]),
    Lmax(TamaMax),
    tope_(-1)
{}

template <typename tElemento>
Pila<tElemento>::Pila(const Pila<tElemento>& P) :
    elementos(new tElemento[P.Lmax]),
    Lmax(P.Lmax),
    tope_(P.tope_)
{
    for (int i = 0; i <= tope_; i++) //Copia del vector
        elementos[i] = P.elementos[i];
}

template <typename tElemento>
Pila<tElemento>& Pila<tElemento>::operator= (const Pila<tElemento>& P)
{
    if(this != &P) { //Evitar autoasignaci�n
        //Destruir el vector y crear uno nuevo si es necesario
        if (Lmax != P.Lmax) {
            delete[] elementos;
            Lmax = P.Lmax;
            elementos = new tElemento[Lmax];
        }
        //Copiar el vector
        tope_ = P.tope_;
        for (int i = 0; i<= tope_; i++)
            elementos[i] = P.elementos[i];
    }
    return *this;
}

template <typename tElemento>
inline bool Pila<tElemento>::vacia() const
{
    return (tope_ == -1);
}

template <typename tElemento>
inline bool Pila<tElemento>::llena() const
{
    return (tope_ == Lmax - 1);
}

template <typename tElemento>
inline const tElemento& Pila<tElemento>::tope() const
{
    assert(!vacia());
    return elementos[tope_];
}

template <typename tElemento>
inline void Pila<tElemento>::pop()
{
    assert(!vacia());
    --tope_;
}

template <typename tElemento>
inline void Pila<tElemento>::push(const tElemento& x)
{
    assert(!llena());
    ++tope_;
    elementos[tope_] = x;
}

template <typename tElemento>
inline Pila<tElemento>::~Pila()
{
    delete[] elementos;
}

#endif 
