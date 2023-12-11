#include "listaEnla.h"

template <typename T>
class ListaOrdenada {
    public:
        bool vacia() const { return L.vacia(); }
        size_t tama() const { return L.tama(); }
        void insertar(const T& x);
        void eliminar(typename Lista<T>::posicion p) { L.eliminar(p); }
        const T& elemento(typename Lista<T>::posicion p) const { return L.elemento(p); }
        typename Lista<T>::posicion siguiente(typename Lista<T>::posicion p) const { return L.siguiente(p); }
        typename Lista<T>::posicion anterior(typename Lista<T>::posicion p) const { return L.anterior(p); }
        typename Lista<T>::posicion primera() const { return L.primera(); }
        typename Lista<T>::posicion fin() const{ return L.fin(); }
    private:
        Lista<T> L;
};


template <typename T>
void ListaOrdenada<T>::insertar(const T& x){
    typename Lista<T>::posicion p = L.primera();

    if(L.vacia())
        L.insertar(x, p);
    else{
        while(p != L.fin() && L.elemento(p) < x)
            p = L.siguiente(p);    
        L.insertar(x, p);
        
    }
}
