//EJERCICIO 1
#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 6000000

using namespace std;

int numAleatorio(int inferior, int superior);

int main(){
	int num;
	
	for(int i ; i < N ; i++){
		numAleatorio(1,6);
		cout << numAleatorio(1,6) << endl;
	}

	return 0;
}

//int numAleatorio(int inferior, int superior)
//Recibe el limite superior e inferior para generar el numero
//Devuelve un numero aleatorio conprendido entre inferior y superior
int numAleatorio(int inferior, int superior){
	int num;

	//srand(time(NULL));
	num = inferior+rand()%(superior+1-inferior);
	
	return num;
}
