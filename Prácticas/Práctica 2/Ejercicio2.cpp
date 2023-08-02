#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#define CARAS 6

using namespace std;

int intervalo_aleatorio (int, int);

int main (){

    int a = 0, b = 5, i, aux;
    long int prob[CARAS], j = 0;
    float res;

    for(i = 0; i < CARAS; i++){
        prob[i] = 0;
    }

    srand(time(0));
    while(j < 10000000){
        prob[intervalo_aleatorio(a,b)]++;
        j++;
    }

    for(i = 0; i < CARAS; i++){
        cout << "Probabilidad de " << i << " = " << prob[i]/100000.0 << "%" << endl;
    }

    return 0;
}



int intervalo_aleatorio (int a, int b){

    int aux = rand();

    if (a>b){
        int aux2 = a;
        a = b;
        b = aux2;
    }

    while(!(aux <= b && aux >= a)){
        aux = a + aux % (b-a+1);
    }
    return aux;
}
