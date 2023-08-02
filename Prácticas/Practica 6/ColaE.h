#ifndef TADCOLAESTATICA_H_INCLUDED
#define TADCOLAESTATICA_H_INCLUDED
#include <cassert>

template <typename T> class ColaE {
    public:
        explicit ColaE(size_t TamaMax); // constructor, requiere ctor. T()
        ColaE(const ColaE<T>& C); // ctor. de copia, requiere ctor. T()
        ColaE<T>& operator =(const ColaE<T>& C); // asignación de colas, requiere ctor. T()
        bool vacia() const;
        bool llena() const; //Requerida por la implementación
        const T& frente() const;
        void pop();
        void push(const T& x);
        ~ColaE();    //Destructor

    private:
        T *elementos;   //Vecotr de elementos
        int Lmax;       //Tamaño del vector
        int inicio, fin;    //Posiciones de los extremos de la cola
        };

template <typename T>
ColaE<T>::ColaE(size_t TamaMax) :
    elementos(new T[TamaMax +1]),   //+1 para dectectar cola llena
    Lmax(TamaMax + 1),
    inicio(0),
    fin(TamaMax)
{}

template <typename T>
ColaE<T>::ColaE(const ColaE<T>& C):
    elementos(new T[C.Lmax]),   //+1 para dectectar cola llena
    Lmax(C.Lmax),
    inicio(C.inicio),
    fin(C.fin)
{
    if(!C.vacia())  //Copiar el vector
        for (int i = inicio; i != (fin +1) % Lmax; i =  (i + 1) % Lmax)
            elementos[i] = C.elementos[i];

}

template <typename T>
 ColaE<T>& ColaE<T>::operator =(const ColaE<T>& C) {
    if (this != &C) { // evitar autoasignación
        //Destruir el vector y crear uno nuevo si es necesario
        if (Lmax != C.Lmax){
            delete[] elementos;
            Lmax = C.Lmax;
            elementos = new T[Lmax];
        }
        //Copiar el vector
        inicio = C.inicio;
        fin = C.fin;
        if (!C.vacia())
            for(int i = inicio; i != (fin + 1) % Lmax; i = (i + i) % Lmax)
                elementos[i] = C.elementos[i];
    }
    return *this;
}

template <typename T> inline bool ColaE<T>::vacia() const {
    return ((fin + 1) % Lmax == inicio);
}

template <typename T> inline bool ColaE<T>::llena() const {
    return ((fin + 2) % Lmax == inicio);
}

template <typename T> inline const T& ColaE<T>::frente() const {
    assert(!vacia());
    return elementos[inicio];
}

template <typename T> inline void ColaE<T>::pop() {
    assert(!vacia());
    inicio = (inicio + 1) % Lmax;
}

template <typename T> inline void ColaE<T>::push(const T& x) {
    assert(!llena());
    fin = (fin + 1) % Lmax;
    elementos[fin] = x;
}

// Destructor: vacía la cola
template <typename T> inline ColaE<T>::~ColaE() {
    delete[] elementos;
}

#endif // TADCOLAESTATICA_H_INCLUDED
