#ifndef EJERCICIO4_H_INCLUDED
#define EJERCICIO4_H_INCLUDED

//Precondicion: P y Q son dos pilas cuyos elementos representan un dígito de un número entero
//Postcondicion: Devuelve una pila con cuyos elementos representan las sumas de los numeros enteros representados por P y Q
PilaD<int> sumaEnteros(PilaD<int> P, PilaD<int> Q);

PilaD<int> sumaEnteros(PilaD<int> P, PilaD<int> Q){
    PilaD<int> R;
    int acarreo = 0;

    while(!P.vacia() || !Q.vacia()){
        if(!P.vacia() && !Q.vacia()){
            if(P.tope() + Q.tope() + acarreo > 9) {
                R.push(P.pop() + Q.pop() + acarreo - 10);
                acarreo = 1;
            }
            else {
                R.push(P.pop() + Q.pop() + acarreo);
                acarreo = 0;
            }
        }
        else {
            if (!P.vacia() && Q.vacia()){
                if(P.tope() + acarreo > 9) {
                    R.push(P.pop() + acarreo - 10);
                    acarreo = 1;
                }
                else {
                    R.push(P.pop() + acarreo);
                    acarreo = 0;
                }
            }
            else {
                if (!Q.vacia() && P.vacia()){
                    if(Q.tope() + acarreo > 9) {
                        R.push(Q.pop() + acarreo - 10);
                        acarreo = 1;
                    }
                    else {
                        R.push(Q.pop() + acarreo);
                        acarreo = 0;
                    }
                }
            }
        }
    }
    return R;
}

#endif // EJERCICIO4_H_INCLUDED
