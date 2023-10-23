#ifndef ESCALONADA_HPP
#define ESCALONADO_HPP

#include "../TADs/ListaDoble.h"

struct Funcion {
    Funcion(int x1, int x2, int y);
    int x1, x2, y;
};

class Escalonada {
    public:
        Escalonada();
        void agregarSalto(const Funcion& p);
        void eliminarEscalon(int x);
        int f(int x);
        int min();
        int max();
        ~Escalonada() = default;
    private:
        Lista<Funcion> lFun;
        static int minimo, maximo;
        int nSaltos;
};

Escalonada::Escalonada() : nSaltos(0){}

void Escalonada::agregarSalto(const Funcion& fun){

    lFun.insertar(fun, lFun.primera());

    if(fun.y > maximo)
        maximo = fun.y;
    if(fun.y > minimo)
        minimo = fun.y;
}

void Escalonada::eliminarEscalon(int x){
    Lista<Funcion>::posicion pos = lFun.primera();
    while(pos != lFun.fin()){
        if(lFun.elemento(pos).x1 < x && lFun.elemento(pos).x2 > x)
            lFun.eliminar(pos);
        pos = lFun.siguiente(pos);
    }
    if(lFun.elemento(pos).y = maximo)
        redefinirMax()
    if(lFun.elemento(pos).y = minimo)
}

int Escalonada::f(int x){
    Lista<Funcion>::posicion pos = lFun.primera();
    int yi = 0;
    while(pos != lFun.fin()){
        if(lFun.elemento(pos).x == x)
            yi = lFun.elemento(pos).y;
        pos = lFun.siguiente(pos);
    }
    return yi;
}

int Escalonada::min(){ return minimo; }

int Escalonada::max(){ return maximo; }

void redefinirMaxMin(){
    Lista<Funcion>::posicion pos = lFun.primera();
    int altura, max = lFun.elemento(pos).y;

    while(pos != lFun.fin()){
        altura = lFun.elemento(pos).y;
        if(altura > )
    }
       
}

#endif