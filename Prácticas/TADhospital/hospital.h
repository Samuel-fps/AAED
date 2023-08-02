#ifndef TADHOSPITAL_H_INCLUDED
#define TADHOSPITAL_H_INCLUDED
#include <cassert>

#include "ListaE.h"

class Hospital{
    struct Paciente;
public:
    Hospital(int tamUCI, int tamPlanta) : uci_{tamUCI}, planta_{tamPlanta}, totalUCI_{tamUCI}, totalPlanta_{tamPlanta}, actualUCI_{0}, actualPlanta_{0} {}
    void ingreso(Paciente pac);
    void alta(Paciente pac);
    void muerte(Paciente pac);

    ListaE<Paciente> UCI();
    ListaE<Paciente> Planta();

    ListaE<Paciente> gravedad(int grav);

private:
    struct Paciente{
        int id;
        int gravedad;

        bool operator ==(Paciente pac) {return id == pac.id;}
    };
    ListaE<Paciente> uci_;
    ListaE<Paciente> planta_;
    const int totalUCI_;
    const int totalPlanta_;
    int actualUCI_;
    int actualPlanta_;
};

#endif // TADHOSPITAL_H_INCLUDED
