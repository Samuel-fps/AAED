#ifndef TADTREN_H
#define TADTREN_H
#include <cassert>

#include "PilaD.h"

typedef int Vagon;

class Tren{
public:
    //Constructor por defecto

    void despIzq();
    void despDer();

    void elimActivo();
    void inseActivo(Vagon v);
    Vagon mostrarActivo();

    bool vacio();

private:
    static const Vagon ActivoVacio = -1;

    Vagon activo;
    PilaD<Vagon> izq;
    PilaD<Vagon> der;
};

#endif // TADTREN_H
