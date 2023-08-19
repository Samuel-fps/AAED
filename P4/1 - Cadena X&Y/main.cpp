#include <iostream>
#include "PilaD.h"

using namespace std;

bool inversa(char cad[]);

int main (){
	char cad[12] = "casas&sasac";
	
	if(inversa(cad)){
		cout << "La cadena tiene su inversa al lado." << endl;
	}
	
	return 0;
}

bool inversa(char cad[]){
	int i=0;
	char c;
	bool iguales=true;
	PilaD<char> pila;
	
	while(cad[i] != '&'){
		pila.push(cad[i]);
		i++;
	}
	i++;
	while(!pila.vacia() && cad[i] != '\0'){
		c = pila.pop();
		cout << c << " ";
		if(cad[i] != c)
			iguales=false;
	}
	return iguales;
}
