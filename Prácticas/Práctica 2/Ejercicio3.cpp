#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

double intervalo_aleatorio_float (double, double);

int main (){

    double num, a = 20.0, b = 25.0;
    srand(time(0));

    num = intervalo_aleatorio_float(a, b);

    cout << "El numero en coma flotante y precision doble en el intervalo (" << a << ", " << b << ") es: " << num << endl;

    return 0;
}


double intervalo_aleatorio_float (double a, double b){

    double aux = rand();

    if (a>b){
        double aux2 = a;
        a = b;
        b = aux2;
    }

    while(!(aux <= b && aux >= a)){
        aux -= b-a+1;
    }
    return aux;
}
