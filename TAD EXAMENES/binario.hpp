#include "../TADs/ColaDinamica.h"
#include "../TADs/ListaEnla.h"
typedef int Paciente;

typedef struct {
    Cola<Paciente> espera;
} Medico;

class Hospital {
    public:
        Hospital();
        void altaMedico(const Medico& m);
        void bajaMedico(const Medico& m);
        void addPaciente(const Medico& m, const Paciente& p);
        const Paciente& siguiente(const Medico& m);
        bool tienePacientes(const Medico& m);
    private:
        Lista<Medico> medicos;
};

void Hospital::altaMedico(const Medico& m){
    medicos.insertar(m, medicos.fin());
}

void Hospital::bajaMedico(const Medico& m){

}

void Hospital::addPaciente(const Medico& m, const Paciente& p){

}

const Paciente& Hospital::siguiente(const Medico& m){

}

bool Hospital::tienePacientes(const Medico& m){

}