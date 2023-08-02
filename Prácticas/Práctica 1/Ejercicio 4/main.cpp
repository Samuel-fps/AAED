#include <iostream>
#include "visita.h"

int main(int argc, char* argv[]) {
    using namespace std;

    int Visitas = 0;

    while (*++argv)
        visita(*argv);

    cout << "Visitas: " << Visitas << endl;

    return 0;
    }
