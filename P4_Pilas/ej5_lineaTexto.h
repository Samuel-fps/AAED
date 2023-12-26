#include "pilaEnla.h"

/*
    DEFINICION

    OPERACIONES
        void next();
            Pre: El cursor no esta en el ultimo carcater de la lienea
            Post: El cursor pasa al siguiente caracter
        void back();
            Pre: El cursor no esta en el primer carcater de la lienea
            Post: El cursor pasa al caracter anterior
        void end();
            Post: El cursor pasa al ultimo caracter de la linea
        void begin();
            Post: El cursor pasa al primer caracter de la linea
        void deleteChar();
            Pre: El caracter actual no es vacio
            Post: Se elimina el caracter actual
        void deleteBack();
            Pre: Existe al menos un caracter anterior al caracter actual
            Post: Se elimina el caracter anterior al actual
        void overwrite(char c);
            Post: Se sobreescribe el caracter actual
*/

class LineaTexto {
    public:
        LineaTexto();
        void next();
        void back();
        void end();
        void begin();
        void deleteChar();
        void deleteBack();
        void overwrite(char c);
    private:
        Pila<char> L, R;
};

LineaTexto::LineaTexto(){

}

void LineaTexto::next(){
    if(!R.vacia()){
        L.push(R.tope());
        R.pop();
    }
}

void LineaTexto::back(){
    if(!L.vacia()){
        R.push(L.tope());
        L.pop();
    }
}

void LineaTexto::end(){
    while(!R.vacia())
        next();
}

void LineaTexto::begin(){
    while(!L.vacia())
        back();
}

void LineaTexto::deleteChar(){
    if(!R.vacia()){
        R.pop();
    }
}

void LineaTexto::deleteBack(){
    if(!L.vacia()){
        L.pop();
    }
}

void LineaTexto::overwrite(char c){
    if(R.vacia())
        R.push(c);
    else{
        R.pop();
        R.push(c);
    }
}

