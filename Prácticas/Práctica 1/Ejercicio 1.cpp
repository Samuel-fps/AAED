#include <iostream>

void muestra_temperatura(int );

using namespace std;

int main()
{
    muestra_temperatura(10);
    muestra_temperatura(27);
    muestra_temperatura(40);
    return 0;
}



void muestra_temperatura(int temperatura) {
    cout << "Temperatura: " << temperatura << " grados ";
    if (temperatura > 20) {
        if (temperatura < 30);
            cout << "(normal)";}
    else cout << "(baja)";
    cout << endl;
    }
