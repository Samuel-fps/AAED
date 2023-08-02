#include <cassert>
#include <iostream>
#include "polinomAlum.h"

polinomioAlum::polinomioAlum (unsigned gradoMax){
    gMax = gradoMax;
    pElem = gradoMax + 1;
    coef = new double[pElem];

    for(unsigned i = 0; i <= pElem; i++){
        coef[i] = 0;
    }
}

unsigned polinomioAlum::grado () const{

    unsigned gAct;
    for(unsigned i = 0; i <= pElem; i++){
        if(coef[i] != 0) gAct = i;
    }

    return gAct-1;
}

double polinomioAlum::coeficiente (unsigned n) const{
    return n > gMax ? 0 : coef[n];
}

void polinomioAlum::coeficiente (unsigned n, double c){
    assert(n <= gMax);
    coef[n] = c;
}

void polinomioAlum::imprime () const{

    unsigned gAct;
    for(unsigned i = 0; i <= pElem; i++){
        if(coef[i] != 0) gAct = i;
    }

    std::cout << "Polinomio de grado " << gAct << std::endl;
    for(unsigned i = gAct; i >= 0; i--){
        std::cout << coef[i] << "x^" << i << " ";
    }
    std::cout << coef[0] << std::endl;
}

polinomioAlum operator + (const polinomioAlum& p1, const polinomioAlum& p2){

    unsigned gMax, gMin;

    if (p1.grado() > p2.grado()) {gMax = p1.grado(); gMin = p2.grado();}
    else {gMax = p2.grado(); gMin = p1.grado();}

    polinomioAlum pSum(gMax);

    for (unsigned i = 0; i <= gMax; i++){
        if (i <= gMin) pSum.coeficiente(i, p1.coeficiente(i) + p2.coeficiente(i));
        else pSum.coeficiente(i, p1.coeficiente(i));
    }
    return pSum;
}

polinomioAlum operator - (const polinomioAlum& p1, const polinomioAlum& p2){

    unsigned gMax, gMin;

    if (p1.grado() > p2.grado()) gMax = p1.grado(), gMin = p2.grado();
    else gMax = p2.grado(), gMin = p1.grado();

    polinomioAlum pRes(gMax);

    for (unsigned i = 0; i <= gMax; i++){
        if (i <= gMin) pRes.coeficiente(i, p1.coeficiente(i) - p2.coeficiente(i));
        else pRes.coeficiente(i, p1.coeficiente(i));
    }
    return pRes;
}

polinomioAlum operator * (const polinomioAlum& p1, const polinomioAlum& p2){

    polinomioAlum p(p1.grado() + p2.grado());

    for (unsigned i = 0; i <= p1.grado(); i++){
        for (unsigned j = 0; j <= p2.grado(); j++){
            p.coeficiente( (p1.grado() - i + p2.grado() - j),
                          p.coeficiente(p1.grado() - i + p2.grado() - j) + p1.coeficiente(p1.grado() - i) * p2.coeficiente(p2.grado() - j));
        }
    }
    return p;
}

polinomioAlum operator / (const polinomioAlum& p1, const polinomioAlum& p2){
}

polinomioAlum operator += ( polinomioAlum& p1, const polinomioAlum& p2){
    p1 = p1 + p2;
    return p1;
}

polinomioAlum operator -= ( polinomioAlum& p1, const polinomioAlum& p2){
    p1 = p1 - p2;
    return p1;
}

polinomioAlum operator *= (polinomioAlum& p1, const polinomioAlum& p2){
    p1 = p1 * p2;
    return p1;
}

polinomioAlum operator /= ( polinomioAlum& p1, const polinomioAlum& p2){
}

bool operator != (const polinomioAlum& p1, const polinomioAlum& p2){
    int res = 1;
    if(p1.grado() == p2.grado()){
        for(unsigned i = 0; i <= (p1.grado() > p2.grado() ? p1.grado() : p2.grado()); i++){
            if(p1.coeficiente(i) != p2.coeficiente(i)) res = 0;
        }
    }
    return res;
}

bool operator <= (const polinomioAlum& p1, const polinomioAlum& p2){
    int res = 1;
    if(p1.grado() <= p2.grado()){
        for(unsigned i = 0; i <= (p1.grado() > p2.grado() ? p1.grado() : p2.grado()); i++){
            if(p1.coeficiente(i) <= p2.coeficiente(i)) res = 0;
        }
    }
    return res;
}

bool operator > (const polinomioAlum& p1, const polinomioAlum& p2){
    int res = 1;
    if(p1.grado() > p2.grado()){
        for(unsigned i = 0; i <= (p1.grado() > p2.grado() ? p1.grado() : p2.grado()); i++){
            if(p1.coeficiente(i) > p2.coeficiente(i)) res = 0;
        }
    }
    return res;
}

bool operator >= (const polinomioAlum& p1, const polinomioAlum& p2){
    int res = 1;
    if(p1.grado() >= p2.grado()){
        for(unsigned i = 0; i <= (p1.grado() > p2.grado() ? p1.grado() : p2.grado()); i++){
            if(p1.coeficiente(i) >= p2.coeficiente(i)) res = 0;
        }
    }
    return res;
}
