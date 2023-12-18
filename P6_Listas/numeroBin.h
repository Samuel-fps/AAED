#include <string>
#include "listaenla.h"

/*
Binario(const string& bin);
    Pre: La cadena se compone de caracters '0' o '1'
    Post:
operator ~

operator &

operatr |

operator ^

operator <<

operator >>

recondicion ¿Hay algun binario que no se le pueda aplicar esta operacion?
*/

using namespace std;

class Binario {
    public:
        Binario(const string& bin);
        Binario operator ~();
        friend Binario operator &(const Binario& b1, const Binario& b2);
        friend Binario operator |(const Binario& b1, const Binario& b2);
        friend Binario operator ^(const Binario& b1, const Binario& b2);
        Binario operator <<(int desp);
        Binario operator >>(int desp);
    private:
        Lista<bool> B;
};

Binario operator &(const Binario& b1, const Binario& b2){
    Binario bin("");

    Lista<bool>::posicion p1 = b1.B.primera();
    Lista<bool>::posicion p2 = b2.B.primera();

    while(p1 != b1.B.fin() && p2 != b2.B.fin()){
        bin.B.insertar(b1.B.elemento(p1) & b2.B.elemento(p2), p1);
    }
    return bin;
}

Binario operator |(const Binario& b1, const Binario& b2){
    
}

Binario operator ^(const Binario& b1, const Binario& b2){

}

Binario Binario::operator <<(int desp){
    for(int i = 0 ; i < desp ; i++){
        B.eliminar(B.fin());
        B.insertar(false, B.primera());
    }
}

Binario Binario::operator >>(int desp){
    for(int i = 0 ; i < desp ; i++){
        B.eliminar(B.primera());
        B.insertar(false, B.fin());
    }
}