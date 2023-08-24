
/*
    EJERCICIO 1
    Se dice que una pila es isomorfica a una cola cuando los elementos situados en posiciones
    pares de la pila coinciden con los situados en posiciones impares de la cola.
    Usando los TAD Pila y Cola, implemente una funcion que determine y devuelva si una
    pila y una cola dadas son isomorficas o no.
*/

bool isomorfica(PilaD<int> p, ColaD<int> c){
    PilaD<int> pAux;
    ColaD<int> cAux;

    while(!pila.vacia())
        pAux.push(pila.pop());
    
    while(!pAux.vacia())
        cAux.push(pAux.pop());
    
        // Comparamos las posiciones impares de la cola con las impares de la pila (guardados en cAux)
    while(!cAux.vacia() && !cola.vacia()){
        cAux.pop(); // Paso una posicion de la pila, ahora esta en una posicion par (2)
        if(cAux.frente() != cola.frente()) // Comparo pos 1 de cola con pos 2 de cola
            return false;
        cAux.pop();
        cola.pop();
        cola.pop();
    }
    return true;
}

/*
    EJERCICIO 2
    Escriba una funcion que dada una cola y dos elementos a y b, invierta la secuencia delimitada por ambos dentro de ella.
    Dado que la cola puede tener elementos repetidos, se invertira la secuencia delimitada por
    la primera ocurrencia de a y b
*/

Cola<int> invertirScuencia(Cola<int> c, int a, int b){
    Cola<int> cAux;
    Pila<int> pAux;

    // Rellenar la cola
    while(!c.vacia()){
        if(c.frente() == a){
            while(c.frente() != b){
                pAux.push(c.frente());
                c.pop();
            }

            // Volver a rellenar la cola correctamente
            while(!pAux.vacia()){
                cAux.push(pAux.frente());
                pAux.pop();
            }
        }
        cAux.push(c.frente());
        c.pop();
    }

    return cAux;
}

/*
    EJERCICIO 3
    Se define una bicola o cola doble como una cola en la cual se pueden hacer inserciones y
    borrados en ambos extremos.
    Realice la especificacion e implementacion (mediante una estructura enlazada) del TAD
    Bicola.
*/

/*
    EJERCICIO 4
    Implemente el TAD Pila utilizando como representacion interna una bicola. Repita el
    ejercicio para el TAD Cola.
*/

/*
    EJERCICIO 5
    El estacionamiento de las avionetas en un aerodromo es en linea, con capacidad para 12
    avionetas. Las avionetas llegan por el extremo izquierdo y salen por el derecho. Cuando
    llega un piloto a recoger su avioneta, si esta no esta justamente en el extremo de salida
    (derecho), todas las avionetas a su derecha han de ser retiradas, sacar la suya y las retiradas
    colocadas de nuevo en el mismo orden relativo en que estaban. La salida de una avioneta
    supone que las demas se mueven hacia adelante, de tal forma que los espacios libres del
    estacionamiento esten en la parte izquierda (entrada).
    Implemente un subprograma que emule el estacionamiento. Este subprograma, ademas del
    aerodromo, recibira un codigo de accion sobre una avioneta, y la matricula de la misma.
    La accion puede ser entrada (E) o salida (S) de avioneta. En la llegada puede ocurrir que
    el estacionamiento este lleno; si es asi, la avioneta espera hasta que se quede una plaza
    libre o hasta que se le de la orden de retirada (salida).
*/

void aerodromo(Cola<int> aero, int matricula, char codigo){
    Cola<int> aux;
    int avion;
    bool done = true;

    if(codigo == 'E'){
        if(!cola.llena()){
            cola.push(matricula); 
        }
        else{
            avion = matricula;
        }
    }
    else if(codigo == 'S'){
        while(done){
            if(aero.frente() == matricula){
                done = false;
                aero.pop();
            else{
                avion = aero.frente();
                aero.pop();
                aero.push(avion);
            }
        }
    }
    else{
        // Codigo de accion incorrecto
    }
}

/*
    EJERCICIO 6
    Se desea simular el juego de los reyes. Se trata de un solitario que se desarrolla de la
    siguiente forma:
    Se reparten las cartas de la baraja española en diez montones de cuatro cartas cada uno.
    Cada montón se corresponde con una de las diez figuras de la baraja. Se escoge uno de los
    montones al azar y se extrae la carta de dicho montón que esté en la cima. Esta carta se
    coloca al final del montón correspondiente a la figura que represente, extrayéndose ahora
    la primera carta de este montón. Este ciclo se repite hasta llegar a un montón en el que
    las cuatro cartas de la figura correspondiente han sido colocadas.
    El juego se considera acabado con éxito si los cuatro reyes están en su montón.
    Se pide:
        a) Diseñar las estructuras de datos adecuadas para representar los tipos tCarta y
        tMonton.
        b) Suponiendo que las cartas ya están barajadas y que el resultado se encuentra almacenado en un vector de tipo tCarta,
        desarrollar una función que dado el montón de comienzo, simule este juego y devuelva, a su finalización, el resultado 
        del solitario (éxito o fracaso) y el contenido del montón correspondiente a los reyes.
*/



