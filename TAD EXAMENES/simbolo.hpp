#include "../TADs/PilaDinamica.h"

typedef enum Trazo {L, R, U, D};


class Simbolo {
    public:
        Simbolo();
        void agregarTrazo(const Trazo& t);
        void deshacer(unsigned n);
        Simbolo simetriaX() const;
        Simbolo simetriaY() const;
        Simbolo simetriaXY() const;
    private:
        Pila<Trazo> trazos;
};

void Simbolo::agregarTrazo(const Trazo& t){
    trazos.push(t);
}

void Simbolo::deshacer(unsigned n){
    for(int i = 1 ; i <= n ; i++)
        if(!trazos.vacia())
            trazos.pop();
}

Simbolo Simbolo::simetriaX() const {
    Simbolo copia{*this}, res;
    while(!copia.trazos.vacia()){
        Trazo sentido = copia.trazos.tope();
        switch (sentido){
            case L: 
                res.trazos.push(R);
                break;
            case R:
                res.trazos.push(L);
                break;
            default:
                res.trazos.push(sentido);
        }
        copia.trazos.pop();
    }
    return res;
}

Simbolo Simbolo::simetriaY() const {
    Simbolo copia{*this}, res;
    while(!copia.trazos.vacia()){
        Trazo sentido = copia.trazos.tope();
        switch (sentido){
            case U: 
                res.trazos.push(D);
                break;
            case D:
                res.trazos.push(U);
                break;
            default:
                res.trazos.push(sentido);
        }
        copia.trazos.pop();
    }
    return res;
}

Simbolo Simbolo::simetriaXY() const {
    return ((*this).simetriaY()).simetriaX();
}