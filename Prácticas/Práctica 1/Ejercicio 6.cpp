#include <iostream>

using namespace std;

inline void intercambio (int& a, int& b, int& c) {int aux = a; a = b; b = c; c = aux;}

int main (){

    int a = 10, b = 20, c = 30;

    intercambio(a, b, c);

    //cout << a& << "," << b& << "," << c& << endl;

    return 0;
}
