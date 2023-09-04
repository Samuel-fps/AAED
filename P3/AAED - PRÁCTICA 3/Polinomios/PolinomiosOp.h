#include <iostream>
#include "polinom.h"



void printPolinomio(polinomio p);
int gradoMax(polinomio p1, polinomio p2);

polinomio operator+(const polinomio p1, const polinomio p2);
polinomio operator-(const polinomio p1, const polinomio p2);
polinomio operator*(const polinomio p1, const polinomio p2);
