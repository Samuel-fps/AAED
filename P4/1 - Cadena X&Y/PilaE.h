#ifndef TADPILAPSEUDOESTATICA_H
#define TADPILAPSEUDOESTATICA_H
#include <cassert>

template <typename tElemento> class PilaE {
public:
    explicit PilaE(unsigned TamaMax); /*Constructor*/
    PilaE(const PilaE& P); /*Constructor de copia*/
    PilaE& operator= (const PilaE& P); //Asignación entre pilas
    bool vacia() const;
    bool llena() const; //Requerida por la implementación
    const tElemento& tope() const;
    void pop();
    void push(const tElemento& x);
    ~PilaE(); /*Destructor*/
private:
    tElemento *elementos; //Vector de elementos
    int Lmax; //Tamaño del vector
    int tope_; //Posición del tope
};

template <typename tElemento>
inline PilaE<tElemento>::PilaE(unsigned TamaMax) :
    elementos(new tElemento[TamaMax]),
    Lmax(TamaMax),
    tope_(-1)
{}

template <typename tElemento>
PilaE<tElemento>::PilaE(const PilaE<tElemento>& P) :
    elementos(new tElemento[P.Lmax]),
    Lmax(P.Lmax),
    tope_(P.tope_)
{
    for (int i = 0; i <= tope_; i++) //Copia del vector
        elementos[i] = P.elementos[i];
}

template <typename tElemento>
PilaE<tElemento>& PilaE<tElemento>::operator= (const PilaE<tElemento>& P)
{
    if(this != &P) { //Evitar autoasignación
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
inline bool PilaE<tElemento>::vacia() const
{
    return (tope_ == -1);
}

template <typename tElemento>
inline bool PilaE<tElemento>::llena() const
{
    return (tope_ == Lmax - 1);
}

template <typename tElemento>
inline const tElemento& PilaE<tElemento>::tope() const
{
    assert(!vacia());
    return elementos[tope_];
}

template <typename tElemento>
inline void PilaE<tElemento>::pop()
{
    assert(!vacia());
    --tope_;
}

template <typename tElemento>
inline void PilaE<tElemento>::push(const tElemento& x)
{
    assert(!llena());
    ++tope_;
    elementos[tope_] = x;
}

template <typename tElemento>
inline PilaE<tElemento>::~PilaE()
{
    delete[] elementos;
}

#endif // TADPILAPSEUDOESTATICA_H
