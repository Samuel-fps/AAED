#include <iostream>
#include "polinomio.h"
#include "polinomiosOp.h."
#define N 1

using namespace std;

int main(){
	unsigned int n, opcion;
	polinomio p1(N), p2(N), sol(N);
	
	p1.coeficiente(0, 2);
	p1.coeficiente(1, 5);
	/*
	p1.coeficiente(2, 3);
	p1.coeficiente(3, 1);
	*/
	p2.coeficiente(0, 3);
	p2.coeficiente(1, 1);
	/*
	p2.coeficiente(2, 2);
	p2.coeficiente(3, 4);
	*/
	while(opcion != 6){
		cout << "Elige la operacion que quieres realizar:" << endl;
		cout << "[1] Inicializar un Polinomio" << endl;
		cout << "[2] Suma de Polinomios" << endl;
		cout << "[3] Resta de Polinomios" << endl;
		cout << "[4] Producto de polinomios" << endl;
		cout << "[5] Salir" << endl;
		cin >> opcion;
		
		switch (opcion){
			case 1: break;
			case 2: sol = p1+p2; break;
			case 3: sol = p1-p2; break;
			case 4: sol = p1*p2; break;
			case 5: break;
		}
		//Mostrar Operación//
		cout << endl << "//////OPERACION///////\n\n";
		printPolinomio(p1);
		switch(opcion){
			case 1: 
			case 2: cout << " + "; break;
			case 3: cout << " - "; break;
			case 4: cout << " * "; break;
		}
		printPolinomio(p2);
		cout << " = ";
		//Mostrar Solución//
		printPolinomio(sol);
		cout << endl << endl;
	}
	return 0;
}
