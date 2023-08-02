#ifndef EJERCICIO5_H_INCLUDED
#define EJERCICIO5_H_INCLUDED

#include "PilaD.h"

class simText{
public:
    explicit simText();     /*Constructor*/
    simText(const simText&);  /*Constructor de copia*/

    void avanzarCursor(simText& text);
    void retrasarCursor(simText& text);

    void finalLinea(simText& text);
    void principioLinea(simText& text);

    void borrarChar(simText& text);
    void borrarCharAnt(simText& text);

    void insertarChar(simText& text, char cAux);
    void sobreescribirChar(simText& text, char cAux);


private:
    PilaD<char> Sup, Inf;
};

void simText::avanzarCursor(simText& text){
    text.Sup.push(text.Inf.pop());
}
void simText::retrasarCursor(simText& text){
    text.Inf.push(text.Sup.pop());
}

void simText::finalLinea(simText& text){
    while(!text.Inf.vacia()){
        text.Sup.push(text.Inf.pop());
    }
}
void simText::principioLinea(simText& text){
    while(!text.Sup.vacia()){
        text.Inf.push(text.Sup.pop());
    }
}

void simText::borrarChar(simText& text){
    text.Inf.pop();
}
void simText::borrarCharAnt(simText& text){
    text.Sup.pop();
}

void simText::insertarChar(simText& text, char cAux){
    text.Inf.push(cAux);
}
void simText::sobreescribirChar(simText& text, char cAux){
    text.Inf.pop();
    text.Inf.push(cAux);
}
#endif // EJERCICIO5_H_INCLUDED
