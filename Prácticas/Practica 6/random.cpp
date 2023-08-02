#include <iostream>
#include <algorithm>

using namespace std;

int intervalo_aleatorio (int, int);

int main (){
    int a = 70, b = 120, c;

    c = intervalo_aleatorio(a, b);
    cout << c << endl;

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
