#ifndef CONJUNTO_H
#define CONJUNTO_H

template <typename T>
class Conjunto {
    public:
        Conjunto() : L(nullptr) {}
        bool vacio(){ return L == nullptr; }
        void insertar(const T& x);
        void eliminar(const T& x);
        friend void unir(const Conjunto& c1, const Conjunto& c2);
        friend void insertar(const Conjunto& c1, const Conjunto& c2);
        friend void diferencia(const Conjunto& c1, const Conjunto& c2);
    private:
        struct nodo{
            nodo* sig;
            T elto;
            nodo(const T& e = T(), nodo* n = nullptr) : elto(e), sig(n) {}
        };
        nodo* inicio, fin;

        bool buscar(const T& x);
};

template <typename T>
void insertar(const T& x){
    
    this->sig = new nodo(x, nullptr);
}

template <typename T>
void eliminar(const T& x){

}

template <typename T>
void unir(const Conjunto& c1, const Conjunto& c2){

}

template <typename T>
void insertar(const Conjunto& c1, const Conjunto& c2){

}

template <typename T>
void diferencia(const Conjunto& c1, const Conjunto& c2){

}

// Si devueve nullptr es el primero, si develve un puntero esta en el anterior
template <typename T>
Conjunto<T>::nodo* buscar(const T& x){

    while(){

    }
    return ;
}

#endif