#include "consultorio.h"

void Consultorio::insertarMedico(ListaD<ColaD<std::string> >::posicion& pos)
{
    medicos.insertar(ColaD<std::string>(), pos);
}

void Consultorio::eliminarMedico(ListaD<ColaD<std::string> >::posicion& pos)
{
    medicos.eliminar(pos);
}

void Consultorio::nuevoPaciente(std::string pac, ListaD<ColaD<std::string> >::posicion& pos)
{
    medicos.elemento(pos).push(pac);
}

std::string Consultorio::siguientePaciente(ListaD<ColaD<std::string> >::posicion& pos)
{
    std::string pac = medicos.elemento(pos).frente();
    medicos.elemento(pos).pop();
    return pac;
}

bool Consultorio::esperaVacia(ListaD<ColaD<std::string> >::posicion& pos)
{
    return medicos.elemento(pos).vacia();
}
