#include "PilaD.h"

#include <iostream>
#include <cstring>
#include <vector>

/*	EJERCICIO 1
	Escriba una función que determine y devuelva si una secuencia de caracteres de entrada
    es de la forma X&Y , donde X es una cadena de caracteres e Y es la cadena inversa,
    separadas por el carácter ‘&’.
*/

bool XandY(char cad[]);
void invertirSecuencia(int a, int b, Pila<int> p);
template <typename T> void mostrarPila(Pila<T> pila);
template <typename T> Pila<T> vector2pila(std::vector<T> v);

int main(){
    char cad[] = "";
    std::vector<int> vector = {4,7,8,9,9,1,8,6,7,9,6,2,4,8,9,3,2,1,0};
    Pila<int> pilaPrueba;
    /*
    if(XandY(cad))
        std::cout << "Ejercicio 1 CORRECTO";
    else
        std::cout << "Ejercicio 1 FAIL";*/
    
    pilaPrueba = vector2pila(vector);
    invertirSecuencia(1, 2, pilaPrueba);
    mostrarPila(pilaPrueba);

    return 0;
}
/*
// Devuelve TRUE --> cadena&anedac
// Devuelve FALSE --> Cualquier otra cadena (cad&cadena, davwve)
bool XandY(char cad[]){
    size_t len = strlen(cad);
    Pila<char> pila((len-1)/2);
    int i=0;

    while(cad[i] != '&' && !pila.llena()) // Meter la primera cadena en la pila
        pila.push(cad[i++]);
    if(cad[i] != '&') // Se ha llenado la pila sin llegar a & --> Las cadena x e Y no son del mismo tamaño
        return false;
    i++; // Para pasar el caracter &

    while(i < len && !pila.vacia()){
        if(cad[i] != pila.tope())
            return false;
        pila.pop();
        i++;
    }
    return true;
}*/

void invertirSecuencia(int a, int b, Pila<int> p){
    Pila<int> aux;
    Pila<int> sol;

    while(!p.vacia()){
        if(p.tope() == a){
            while(!p.vacia() && p.tope() != b){ // Meter la secuencia en una pila para invertirlos
                aux.push(p.tope());
                p.pop();
            }
            while(!aux.vacia()){ // Metemos en la pila solucion los numeros invertidos, ahora la pila está a l reves, es decir esta invertida menos el tramo a-b
                sol.push(aux.tope());
                aux.pop();
            }
        }
        sol.push(p.tope());
        p.pop();
    }

    // Introducir los numeros reordenados en la pila original
    while(!sol.vacia()){
        p.push(sol.tope());
        sol.pop();
    }
}

template <typename T>
void mostrarPila(Pila<T> pila){
    std::cout << "[ ";
    while(!pila.vacia()){
        std::cout << pila.tope() << " ";
        pila.pop();
    }
    std::cout << "]" << std::endl;
}

template <typename T>
Pila<T> vector2pila(std::vector<T> v){
    Pila<T> aux;
    
    for(size_t i = v.size() ; i > 0 ; --i)
        aux.push(v[i-1]);

    return aux;
}


