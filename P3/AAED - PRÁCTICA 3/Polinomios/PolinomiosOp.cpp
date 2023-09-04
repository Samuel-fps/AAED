#include <iostream>
#include "polinomio.h"
#include "polinomiosOp.h"

using namespace std;

void printPolinomio(polinomio p){
	int grado=p.grado();
	double coeficiente;
	
	cout << "(";
	for(unsigned i=grado ; i > 0 ; i--){
		coeficiente = p.coeficiente(i);
		if(i == 1){
			if(coeficiente == 1)
				cout << "x" << " + ";
			else
				cout << coeficiente << "x" << " + ";
		}
		else{
			if(coeficiente == 1)
				cout << "x^" << i << " + ";
			else if(coeficiente != 0)
				cout << coeficiente << "x^" << i << " + ";
		}
	}
	coeficiente = p.coeficiente(0);
	if(coeficiente != 0)
		cout << coeficiente;
	cout << ")";
}

//int gradoMax(polinomio p1, polinomio p2)
//Recibe dos polinomios inicializados
//Devuelve el grado maximo entre de los polinomios
int gradoMax(polinomio p1, polinomio p2){
	int g1 = p1.grado(), g2 = p2.grado();
	if(g1 > g2)
		return g1;
	else
		return g2;
}

//SUMA
polinomio operator+(const polinomio p1, const polinomio p2){
	double c, c1, c2;
	int gmax;
	gmax = gradoMax(p1,p2);
	polinomio res(gmax);

	for(unsigned i=0 ; i <= gmax ; i++){
		c1 = p1.coeficiente(i);
		c2 = p2.coeficiente(i);
		
		c = c1 + c2;
		res.coeficiente(i,c);
	}
	return res;
}

polinomio operator-(polinomio p1, polinomio p2){
	double c, c1, c2;
	int gmax;
	gmax = gradoMax(p1,p2);
	polinomio res(gmax);
	
	for(unsigned i=0 ; i <= gmax ; i++){
		c1 = p1.coeficiente(i);
		c2 = p2.coeficiente(i);
		
		c = c1 - c2;
		res.coeficiente(i,c);
	}
	return res;
}

//Solucion 5x^2 + 15x + 2x + 6
polinomio operator*(polinomio p1, polinomio p2){
	double c, c1, c2;
	int gmax, grado1 = p1.grado(), grado2 = p2.grado();
	gmax = grado1 + grado2;
	
	polinomio sol(gmax);
	polinomio aux(gmax);
	
	for(unsigned i=0 ; i <= grado1 ; i++){
		c1 = p1.coeficiente(i);
		
		for(unsigned j=0 ; j <= grado2 ; j++){
			c2 = p2.coeficiente(j);
			
			c = c1 * c2;
			cout << c <<endl;
			aux.coeficiente(i+j,c);
		}
		sol = sol + aux;
		aux.coeficiente(0,0);
	}
	return sol;
}
