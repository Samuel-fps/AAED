#include "tren.hpp"

Tren::Tren(){}

void Tren::desplazarIzq(){

}

void Tren::desplazarDrch(){

}

void Tren::eliminarVagon(){
    derecha.pop():
}

const Vagon& Tren::vagonActivo() const {
    return derecha.tope();
}

bool Tren::vacio() const { 
    return izquierda.vacia() && derecha.vacia();
}