#include<iostream>

using namespace std;

template <class TIPOD>
void mostrarAbs(TIPOD numero);

int main (){
	int num1 = -7;
	float num2 = 3.14;
	double num3 = -572.5323;
	
	mostrarAbs(num1);
	mostrarAbs(num2);
	mostrarAbs(num3);
}

template <class TIPOD>
void mostrarAbs(TIPOD numero){
	if(numero < 0){
		numero *= -1;
	}
	
	cout << "Numero absoluto" << numero << endl;
	}

