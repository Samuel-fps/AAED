
/*
    EJERCICIO 1
    
*/

/*
    EJERCICIO 2
    Una lista ordenada es una lista en la cual los elementos están ordenados de forma 
    ascendente según la relacion de orden definida entre ellos. Especifique e implemente
    el TAD Lista ordenada.
*/

/*
    EJERCICIO 3
    
*/

/*
    EJERCICIO 3
    Implemente una funcion que tenga como entrada una lista de enteros y un entero x, de
    forma que devuelva la lista modificada mediante la eliminacion de todas las ocurrencias
    de x en la lista.
*/

    Lista<int> eliminarEntero(Lista<int> l, int num){
        Lista<int>::posicion pos;

        for(pos = l.primera() ; pos < l.fin() ; pos++){
            if(l.elemento(pos) == num)
                l.eliminar(pos);
        }

        return l;
    }

/*
    EJERCICIO 4
    Dadas dos listas de enteros ordenadas, implemente una funcion que devuelva una tercera
    lista ordenada con la mezcla de las dos listas de entrada.
*/

Lista<int> combinarListas(const Lista<int>& l1, const Lista<int>& l2){
    Lista<int>::posicion pos1;
    Lista<int>::posicion pos2;

    for(pos1 = l1.primera() ; pos1 < l1.fin() ; pos1++){
        pos2 = pos1;
        while(l1.elemento(pos1) > l2.elemento(pos2)){
            pos2 = l1.siguiente();
        }

    }
}