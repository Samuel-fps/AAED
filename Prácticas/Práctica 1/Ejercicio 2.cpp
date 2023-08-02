#include <iostream>

using namespace std;

void muestra_temperatura(int );

int main() {

    muestra_temperatura(10);
    muestra_temperatura(27);
    muestra_temperatura(40);

    return 0;
}


void muestra_temperatura(int temperatura) {
    cout << "Temperatura: " << temperatura << " grados ";
    if (20 < temperatura && temperatura < 30)
            cout << "(normal)";
    else cout << "(baja)";
    cout << endl;
    }
