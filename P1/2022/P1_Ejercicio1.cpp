//EJERCICIO 1
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	int num;
	
	srand(time(NULL));
	for(int i = 0 ; i < 5 ; i++){
		num = 50+rand()%(250+1-50); //Entre 50 y 250
		cout << num << endl;
	}
	//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior)

	return 0;
}
