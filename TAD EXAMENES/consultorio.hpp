#ifndef CONSULTORIO_HPP
#define CONSULTORIO_HPP

#include "../TADs/ColaDinamica.h"
#include "../TADs/ListaDinamica.h"

/*
DEFINICION

ESPECIFICACION
    Consultorio();
        Post: Crea un consultorio vacio
    void altaMedico(Medico m);
        Pre:  Existe un consultorio para agregar el medico
        Post: Se da de alta al medico en el consultorio
    void bajaMedico();
        Pre:  El medico esta dado de alta en el consultorio.
        Post: Se elimina al medico del consultorio
    void agregarPaciente(Medico& m, const Paciente& p);
        Pre:  Existe el medico m en el consultorio.
        Post: Se agrega el paciente a la lista de espera del medico m
    Paciente turno(Medico& m);
        Pre:  Existe el medico (m) en el consultorio
        Post: Devuelve el siguiente paciente de la lista de espera del medico.
    void atenderPaciente(Medico& m);
        Pre:  Existe el medico m en el consultorio.
        Post: Se elimina el primer paciente de la lista de espera.
*/

typedef struct Paciente{};

struct Medico {
    unsigned num;
    Cola<Paciente> pacientes;
};

class Consultorio {
    public:
        Consultorio();
        void altaMedico(Medico& m);
        void bajaMedico();
        void agregarPaciente(Medico& m, const Paciente& p);
        Paciente turno(const Medico& m) const;
        void atenderPaciente(Medico& m);

    private:
        Lista<Medico> medicos;
};

Consultorio::Consultorio(){}

void Consultorio::altaMedico(Medico& m){

}

void bajaMedico(){

}

void agregarPaciente(Medico& m, const Paciente& p){

}

const Paciente turno(const Medico& m) const {

}

void atenderPaciente(Medico& m){

}


#endif