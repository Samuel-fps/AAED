//
//  opBicola.cpp
//  Bicola
//
//  Created by Guillermo Girón García on 4/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#include "opBicola.hpp"

void imprPila(Pila<unsigned> const &P)
{
    Pila<unsigned> impr;
    
    impr.operator = (P);
    
    while (!impr.vacia())
    {
        cout << impr.tope();
        impr.pop();
    }
    
    cout << endl;
   
    impr.~Pila();
}

void elemAPila(Pila<unsigned> &P)
{
    unsigned i;
    
    for(i = 0; i < 5; ++i)
    {
        cout << i;
        P.push(i);
    }
    
    cout << endl;
}

void elemACola(Cola<unsigned> &C)
{
    unsigned i;
    
    for(i = 0; i < 5; ++i)
    {
        cout << i;
        C.push(i);
    }
    
    cout << endl;
}

void imprCola(Cola<unsigned> const &C)
{
    Cola<unsigned> impr;
    
    impr.operator = (C);
    
    while (!impr.vacia())
    {
        cout << impr.frente();
        impr.pop();
        
    }
    
    cout << endl;
    
    impr.~Cola();
}
