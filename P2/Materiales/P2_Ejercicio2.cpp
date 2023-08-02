//P2 Ejercicio 2

#include <iostream>
#include <vector>
#define N 5

#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

//menus
void menuGenerar(int v[]);
void menuOrdenar(int v[], int n);
//funciones
void mostrarVector(int v[], int n);
void generarVector(int n, int v[], int infe, int supe); //En un futuro sobrecargarla con infe y supe
void inicializarVector(int n, int v[], int infe, int supe);
int numAleatorio(int inferior, int superior);
//Algoritmos de ordenacion
void ordenarIntercambio(int v[], int n);
void ordenarSeleccion(int v[], int n);
void ordenarInsercion(int v[], int n);


int main(){
	int n = N, permutaciones;
	
	for(int i=1 ; i <= 9; i++){
		permutaciones = pow(10,i);
		for(int j=0 ; j <= permutaciones ; j++){
			int* vector= new int[j];
			inicializarVector(i,vector,j,j+1);
		}
	}
	
	//menuGenerar(vector);
	//mostrarVector(vector, n);
	//menuOrdenar(v, n);
	
	return 0;
}

void inicializarVector(int n, int v[], int infe, int supe){
	
	for(int i=0 ; i<n ; i++){
		v[i] = numAleatorio(infe, supe);
	}
	cout << "Vector generado:" << endl;
	mostrarVector(v, n);
}

//generarVector(int n, int v[])
//Recibe la longitud que se desea que tenga el vector
//Devuelve un vector inicializado con numeros del infe al supe de n elementos ()
void generarVector(int n, int v[], int infe, int supe){
	
	int* nuevo = new int[n];
	
	for(int i=0 ; i<n ; i++){
		nuevo[i] = numAleatorio(infe, supe);
		cout << nuevo[i] << endl;
	}

	cout << "Vector generado:" << endl;
	mostrarVector(nuevo, n);
	v = nuevo;
}

//int numAleatorio(int inferior, int superior)
//Recibe el limite superior e inferior para generar el numero , Recibe 0 en los 2 parametros para generar un número sin limites
//Devuelve un numero aleatorio conprendido entre inferior y superior
int numAleatorio(int inferior, int superior){
	int num;
	if(inferior == 0 && superior == 0){
		num = rand();
	}
	else{
		num = inferior+rand()%(superior+1-inferior);
	}
	return num;
}

//void menuGenerar (int v[])
//Munu con opciones para generar un vector
void menuGenerar (int v[]){
	int longitud, inferior, superior, opcion=0;
	
	while(opcion != 4){
		cout << "Introduce el vector que quieres." << "\n";
		cout << "[1] Vector con elementos del 1 al 9." << endl;
		cout << "[2] Vector indicando el rango." << endl;
		//cout << "[3] ." << endl;
		cout << "[4] Salir." << endl;
		cin >> opcion;

		switch(opcion){
			case 1: cout << "Introduce la logitud del vector que deseas:\n";
					cin >> longitud;
					inferior = 1;
					superior = 9;
					break;
			case 2: cout << "Introduce la logitud del vector que deseas:\n";
					cin >> longitud;
					cout << "Rango para generar los elementos:\n";
					cout << "Limite inferior: ";
					cin >> inferior;
					cout << "Limite superor: ";
					cin >> superior;
					break;
			case 3: break;
			case 4: break;
			default: cout << "El numero introducido no corresponde a una opcion." << endl;
		}
		if(opcion != 4){
			generarVector(longitud, v, inferior, superior);
			cout << "Vector fuera:" << endl;
			mostrarVector(v, longitud);
		}
	}
}

//void menuOrdenar(int v[], int n)
//Muestra el menu para ordenar un vector de 3 formas diferentes
void menuOrdenar(int v[], int n){
	int opcion = 0;
	
	while(opcion != 4){
		cout << "Introduce el orden que quieres ejecutar al vector." << "\n";
		cout << "[1] Ordenar por Intercambio." << endl;
		cout << "[2] Ordenar por Seleccion." << endl;
		cout << "[3] Ordenar por Insercion." << endl;
		cout << "[4] Salir." << endl;
		cin >> opcion;

		switch(opcion){
			case 1: ordenarIntercambio(v, n); break;
			case 2: ordenarSeleccion(v, n); break;
			case 3: ordenarInsercion(v, n);break;
			case 4: break;
			default: cout << "El numero introducido no corresponde a una opcion." << endl;
		}
		if(opcion != 4){
			cout << endl << "VECTOR ORDENADO" << endl;
			mostrarVector(v, n);
			cout << endl;
		}
	}
}


//ordenarIntercambio(int v[], int n)
//Recibe un vector y su numero de elementos
//Devuelve el vector ordenado
void ordenarIntercambio(int v[], int n){
	int aux;
	
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			if(v[i] < v[j]){
				aux = v[j];
				v[j] = v[i];
				v[i] = aux;
			}
		}
	}
}

//ordenarSeleccion(int v[], int n)
//Recibe un vector y su numero de elementos
//Devuelve el vector ordenado
void ordenarSeleccion(int v[], int n){
	int max, aux;
	
	for(int i=n-1 ; i>0 ; i--){
		max = 0;
		for(int j=0 ; j<=i ; j++){ //Busca el maximo del vector
		cout << "Leyendo interior vector " << v[j] << endl;
			if(v[j] > v[max]){
				max = j;
			}
			cout << "Maximo Interior  " << v[max] << endl;
		}
		cout << "Maximo " << v[max] << endl;
		if(max != i){ //El elemento no esta en su posicion
			aux = v[i];
			v[i] = v[max];
			v[max] = aux;			
		}
	}
}

//ordenarInsercion(int v[], int n);
//Recibe un vector y su numero de elementos
//Devuelve el vector ordenado
void ordenarInsercion(int v[], int n){
	int aux, elemento, pos;
	
	for(int i=1 ; i<n ; i++){ //posicion del elemento
		elemento = v[i];
		pos = i;
		
		while(pos > 0 && elemento < v[pos-1]){ //Recorre los elementos a ala izquierda
			v[pos] = v[pos-1]; //Movemos una posicion a la derecha el numero mayor
			pos--;
		}
		v[pos] = elemento; //Introducimos el elmento en su posicion
	}
}

//void mostrarVector(int v[], int n)
//Recibe un vector y su numero de elementos
//Imprime el vector por pantalla
void mostrarVector(int v[], int n){
	cout << "[ ";
	for(int i = 0 ; i < n ; i++){
		cout << v[i] << " ";
	}
	cout << "]" << endl;
}

//double cronometro (double e_abs. double e_rel);
//Recibe el errar absoluto y el error relativo
//Devuelve el tiempo en segundos
double cronometro (double e_abs. double e_rel){
	crometro c;
	long r = 0;
	c.activar();
	do{
		//Codigo a cronometrar
	}while(c.tiempo() < e_abs/e_rel+e_abs);
	c.parar();
	return (c.tiempo()/r);
}

