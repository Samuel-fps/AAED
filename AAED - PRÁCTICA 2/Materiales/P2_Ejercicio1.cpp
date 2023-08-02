//Ejercicio 1

#include <iostream>
#define N 5

using namespace std;

void menuOrdenar(int v[], int n);
void mostrarVector(int v[], int n);
void ordenarIntercambio(int v[], int n);
void ordenarSeleccion(int v[], int n);
void ordenarInsercion(int v[], int n);


int main(){
	int v[N] = {3, 5, 7, 2, 1};
	int n = N;
	
	menuOrdenar(v, n);
	
	return 0;
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

//mostrarVector(int v[], int n)
//Recibe un vector y su numero de elementos
//Imprime el vector por pantalla
void mostrarVector(int v[], int n){
	for(int i = 0 ; i < n ; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

