#include <iostream>
#include "polinom.h"

#define N 3

using namespace std;

int main(){
	unsigned int n;
	polinomio p1(N), p2(N);
	
	//cout << "Introduce el grado del polinomio" << endl;
	//cin >> n;
	p1.coeficiente(0, 2);
	p1.coeficiente(1, 5);
	p1.coeficiente(2, 3);
	p1.coeficiente(3, 1);
	p1.imprimir(p1);
	n = p1.grado();
	cout << n<< endl;
	
	cout << "Introduce el grado del polinomio" << endl;
	cin >> n;
	//p2.polinomio(n);
	
	return 0;
}
