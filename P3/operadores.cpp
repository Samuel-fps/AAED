#include "operadores.h"

#include <algorithm>
#include <iostream>

polinomio operator +(const polinomio& p1, const polinomio& p2){
    unsigned gradoMax = std::max(p1.grado(), p2.grado());
    polinomio res(gradoMax);
    for(unsigned i=0 ; i <= gradoMax ; i++)
        res.coeficiente(i, p1.coeficiente(i) + p2.coeficiente(i));
    return res;
}

polinomio operator -(const polinomio& p1, const polinomio& p2){
    unsigned gradoMax = std::max(p1.grado(), p2.grado());
    polinomio res(gradoMax);
    for(unsigned i = 0 ; i < gradoMax ; i++)
        res.coeficiente(i, p1.coeficiente(i) - p2.coeficiente(i));
    return res;
}

polinomio operator *(const polinomio& p1, const polinomio& p2){
    unsigned gradoMax = p1.grado() * p2.grado();
    polinomio res(gradoMax);

    for(unsigned i = 0 ; i < gradoMax ; i++)
        for(unsigned j = 0 ; j < gradoMax ; j++)
            res.coeficiente(i+j, res.coeficiente(i+j) + p1.coeficiente(i) * p2.coeficiente(i));
    return res;
}

polinomio operator /(const polinomio& p1, const polinomio& p2){
    polinomio res(p1.grado());

    for(unsigned i = 0 ; i < res.grado() ; i++)
        for(unsigned j = 0 ; j < res.grado() ; j++)
            res.coeficiente(i-j, res.coeficiente(i-j) + p1.coeficiente(i) / p2.coeficiente(i));
    return res;
}

polinomio derivar(const polinomio& p){
    polinomio res(p.grado());
    for(unsigned i = 1 ; i < p.grado() ; i++)
        res.coeficiente(i-1, p.coeficiente(i) * i);
    return res;
}

void printPolinom(const polinomio& p){
    std::cout << p.grado() << std::endl;
    for(int i=p.grado() ; i >= 0 ; i--){
        if(p.coeficiente(i) != 0){
            if(p.grado() != i){
                if(p.coeficiente(i) < 0)
                    std::cout << " - ";
                else
                    std::cout << " + ";
            }
            std::cout << p.coeficiente(i);
            if(i > 1)
                std::cout << "x^" << i;
            else if(i == 1)
                std::cout << "x";
        }
    }
    std::cout << std::endl;
}