#include <iostream>
#include <ctime>

using namespace std;

inline void cuadrado (double x) {x*x;}

int main ()
{
    double x;

    cout << "Introduce un numero" << endl;
    cin >> x;

    //cout << "El cuadrado de " << x << " es " << cuadrado(x) << endl;

    return 0;
}
