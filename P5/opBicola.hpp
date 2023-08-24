//
//  opBicola.hpp
//  Bicola
//
//  Created by Guillermo Girón García on 4/1/18.
//  Copyright © 2018 Guillermo Girón García. All rights reserved.
//

#ifndef opBicola_hpp
#define opBicola_hpp

#include "pila.hpp"
#include "colaEnla.hpp"
#include <iostream>
#include <string>

using namespace std;

//Imprime los elementos de la bicola por pantalla tal como si de una pila se tratase

void imprPila(Pila<unsigned> const &P);

//Imprime los elementos de la bicola por pantalla tal como si de una cola se tratase

void imprCola(Cola<unsigned> const &C);

//Introduce elementos en la bicola tal como si de una pila se tratase

void elemAPila(Pila<unsigned> &P);

//Introduce elementos en la bicola tal como si de una cola se tratase

void elemACola(Cola<unsigned> &C);

#endif /* opBicola_hpp */
