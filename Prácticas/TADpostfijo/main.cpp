#include <iostream>

#include "PilaD.h"
#include "PilaE.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

//Postfijo: AB+CD+*
//Postfijo: XY/Z*W+
double postfijo(string exp, string var)
{
    char aux = ' ';
    bool isVar = false;
    PilaD<char> pila;
    PilaD<char> pila2;
    double res = 0;

    //Pasar string exp a una pila
    for( unsigned i = 0; i != exp.length(); ++i )
    {
        switch( exp[i] )
        {
            case '+': aux = '+'; break;
            case '-': aux = '-'; break;
            case '*': aux = '*'; break;
            case '/': aux = '/'; break;
            default: isVar = true;
        }
        if( isVar )
        {
            isVar = false;
            for( unsigned j = 0; var[j] != exp[i] && j != exp.length(); ++j );
            pila.push(var[j + 1]);

        } else pila.push(aux);
    }

    //Da la vuelta a los elementos de la pila AB+CD+*(tope) -> *+DC+BA(tope)
    while( !pila.vacia() )
    {
        pila2.push(pila.tope());
        pila.pop();
    }

    //Mete dos variables en la pila y cuando llega al operador calcula el resultado de ambos y lo devuelve a la pila
    //Postfijo: AB+CD+*
    //Postfijo: XY/Z*W+
    while( !pila2.vacia() )
    {
        while( pila2.tope() != '+' && pila2.tope() != '-' && pila2.tope() != '*' && pila2.tope() != '/' )
        {
            pila.push(pila2.tope());
            pila2.pop();
        }

        for ( unsigned t = 0; t != 2; ++t )
        {
            double primerOpndo = pila.tope() - 48;
            pila.pop();

            switch( pila2.tope() )
            {
                case '+': primerOpndo += pila.tope(); break;
                case '-': primerOpndo -= pila.tope(); break;
                case '*': primerOpndo *= pila.tope(); break;
                case '/': primerOpndo /= pila.tope(); break;
            }
            pila.pop();
            pila.push(primerOpndo);
        }
    }

    return pila.tope();
}
