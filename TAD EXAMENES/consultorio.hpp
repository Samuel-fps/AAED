#ifndef CONSULTORIO_HPP
#define CONSULTORIO_HPP

#include "../TADs/ColaDinamica.h"
#include "../TADs/ListaEnla.h"

/*
DEFINICION
    Consultorio: 
        Un Consultourio es una secuencia de Medicos
    Medico:
        Un Medico tiene un numero identifico y atienden listas de esperas de Pacientes.
    Paciente:
        Un Paciente tiene un numero identifico y son atendidos por los medicos en orden 
        de primero a ultimo.


ESPECIFICACION
    Consultorio();
        Post: Crea un consultorio vacio
    void altaMedico(const Medico& m);
        Pre:  Existe un consultorio para agregar el medico
        Post: Se da de alta al medico en el consultorio
    void bajaMedico(const Medico& m);
        Pre:  El medico esta dado de alta en el consultorio.
        Post: Se elimina al medico del consultorio
    void agregarPaciente(Medico& m, const Paciente& p);
        Pre:  Existe el medico m en el consultorio.
        Post: Se agrega el paciente a la lista de espera del medico m
    Paciente turno(const Medico& m);
        Pre:  Existe el medico (m) en el consultorio
        Post: Devuelve el siguiente paciente de la lista de espera del medico.
    void atenderPaciente(Medico& m);
        Pre:  Existe el medico m en el consultorio.
        Post: Se elimina el primer paciente de la lista de espera.
    bool pacientesVacio(const Medico& m);
        Pre:  Existe el medico m en el consultorio.
        Post: Se elimina el primer paciente de la lista de espera.
*/

class Consultorio {
    public:
        struct Paciente {
            unsigned num;
        };

        struct Medico {
            Cola<Paciente> pacientes;
        };

        Consultorio();
        void altaMedico(const Medico& m);
        void bajaMedico(const Medico& m);
        void agregarPaciente(Medico& m, const Paciente& p);
        Paciente turno(const Medico& m) const;
        void atenderPaciente(Medico& m);
        bool pacientesVacio(const Medico& m) const;

    private:
        Lista<Medico> medicos;
};

Consultorio::Consultorio(){}

void Consultorio::altaMedico(const Medico& m){
    medicos.insertar(m, medicos.primera());
}

void Consultorio::bajaMedico(const Medico& m){
    Lista<Medico>::posicion posMedico = medicos.buscar(m);
    if(posMedico != medicos.fin())
        medicos.eliminar(posMedico);
}

void Consultorio::agregarPaciente(Medico& m, const Paciente& p){
    m.pacientes.push(p);
}

Consultorio::Paciente Consultorio::turno(const Medico& m) const {
    return m.pacientes.frente();
}

void Consultorio::atenderPaciente(Medico& m){
    m.pacientes.pop();
}

bool Consultorio::pacientesVacio(const Medico& m) const {
    return m.pacientes.vacia();
}

#endif