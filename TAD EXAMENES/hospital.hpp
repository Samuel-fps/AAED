/*#ifdef HOSPITAL_HPP
#define HOSPITAL_HPP
*/
#include "../TADs/ListaPseudo.h"

#include <vector>

struct Paciente {
    int codigo, gravedad;
};

class Hospital {
    public:
        Hospital(size_t planta, size_t uci);
        void ingreso(const Paciente&);
        void alta(const Paciente&);
        void muerte(const Paciente&);
        ~Hospital() = default;

    private:
        size_t pMax, uMax;
        Lista<Paciente> planta;
        Lista<Paciente> uci;
        std::vector<Paciente> morgue;
};

Hospital::Hospital(size_t pl, size_t u) : planta(pl), uci(u), pMax(pl), uMax(u){}

void Hospital::ingreso(const Paciente& p){
    assert(p.gravedad >= 0 || p.gravedad <= 9);
    Lista<Paciente>::posicion pos, posMax;
    int gMin = -1;

    if(p.gravedad >= 1 && p.gravedad <= 5){
        if(uci.fin() <= uMax){ // UCI llena
            pos = uci.primera();
            posMax = pos;
            while(pos < uci.fin()){ // Buscamos el paciente menos grave
                if(uci.elemento(pos).gravedad < gMin){
                    gMin = uci.elemento(pos).gravedad;
                    posMax = pos;
                }
                pos = uci.siguiente(pos);
            }
            uci.elemento(posMax).gravedad = 6; // Cambiamos a gravedad de planta
            ingreso(uci.elemento(posMax));     // Ingresarlo en la planta
            uci.eliminar(posMax);              // Eliminarlo de la uci
        }
        planta.insertar(p, uci.fin());         // Ingresamos al nuevo paciente en la uci 
    }
    else if(p.gravedad >= 6 && p.gravedad <= 9){
        if(planta.fin() <= pMax){ // Planta llena
            pos = planta.primera();
            posMax = pos;
            while(pos < planta.fin()){ // Buscamos el paciente menos grave
                if(planta.elemento(pos).gravedad < gMin){
                    gMin = planta.elemento(pos).gravedad;
                    posMax = pos;
                }
                pos = planta.siguiente(pos);
            }
            planta.elemento(posMax).gravedad = 10; // Gravedad de Alta
            alta(uci.elemento(posMax));           // Damos de alta al paciente
            planta.eliminar(posMax);              // Eliminarlo de la plata
        }
        planta.insertar(p, uci.fin());         // Ingresamos al nuevo paciente en la planta
    }   
    else if(p.gravedad == 0) 
        morgue.push_back(p);
}

void Hospital::alta(const Paciente& p){
    
}

void Hospital::muerte(const Paciente&){

}

//#endif