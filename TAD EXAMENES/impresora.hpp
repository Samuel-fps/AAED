#ifndef IMPRESORA_H
#define IMPRESORA_H

#include "../TADs/ColaDinamica.h"

#include <string>
#include <vector>

/*
DEFINICION
    Impresora: La impresora atiende a los usuarios por turnos, cada vez que llega el turno de un Usuario se procesa un trabajo
    y se pasa el turno al siguiente usuario.

    Usuario: El usuario tiene dos conjuntos de Trabajos (urgente, no urgente) que encargan para la impresion y seran atendidos
             cuando llegue su turno de impresión, tendrán prioridad el conjunto de trabajo de urgente respecto al no urgente.

    Trabajo: Tareas que se añaden a la impresora para ser impresos, se identifican con un código único y pueden ser urgentes o no.

ESPECIFICACION
    Impresora(site_t n)
        Pre:  n > 0
        Post: Crea una impresora  para n usuarios
    void agregarUsuario(Usuario u, const Trabajo& t)
        Pre:  La impresora tiene espacio para un usuario mas.
        Post: Si el usuario ya estaba esperando impresion se la agrega un trabajomas, si no se añade el usuario como ultimo
              en la lista de espera
    void eliminarTrabajo(const Usuario& u, const Trabajo& t)
        Pre:  El trabajo pertenece a al usuario u.
        Post: Se elimina el trabajo t.
    void cancelarUsuario(const Usuario& u)
        Pre:  El usuario tiene un trabajo para imprimir incluido en el conjunto de impresón.
        Post: Se elimina los trabajos de impresion del usuario u.
    
TAD CONOCIDOS (Cola Enlazada)
    template <typename T> Cola<T>();
    template <typename T> const T& frente();
    template <typename T> void pop();
    template <typename T> void push(cosnt T& x);
    template <typename T> bool vacia();
    template <typename T> ~vacia(); // Llamada implicita
*/

struct Trabajo {
    std::string codigo;
    bool urgente;

    Trabajo(std::string c, bool u) : codigo(c), urgente(u) {}
};

struct Usuario {
    unsigned _id;
    Cola<Trabajo> basicos;
    Cola<Trabajo> urgentes;

    Usuario(unsigned id) : _id(id) {}
};

class Impresora {
    public:
        Impresora(size_t n);
        void agregarUsuario(Usuario u, const Trabajo& t);
        void eliminarTrabajo(const Trabajo& t);
        void cancelarUsuario(const Usuario& u);

    private:
        std::vector<Usuario> usuarios; // Guarda la informacion de los trabajos ha imprimir por los usuarios
        Cola<int> turnos;    // Cola que controla los turnos de la inpresora
        size_t nUsuarios;    // Numero de usuarios introducidos
        size_t _maxUsuarios; // Maximo de usuarios que se pueden añadir
};

Impresora::Impresora(size_t max) : nUsuarios(0), _maxUsuarios(max){ 
    assert(max > 0);
}

void Impresora::agregarUsuario(Usuario u, const Trabajo& t){
    assert(nUsuarios+1 < _maxUsuarios);
    size_t pos = nUsuarios+1;
    
    // Buscar u usuario en vector
    for(size_t i=0 ; i<nUsuarios ; i++)
        if(u._id == usuarios[i]._id)
            pos = i;

    // el usuario no existe en la cola -> Se introduce
    if(pos == nUsuarios+1){
        usuarios[nUsuarios] = u;
        nUsuarios++;
    }

    // introducimos el trabajo en la cola correspondiente
    if(t.urgente)
        usuarios[pos].urgentes.push(t);
    else
        usuarios[pos].basicos.push(t);

}

void Impresora::eliminarTrabajo(const Trabajo& t){
    size_t sig = turnos.frente();
    if(usuarios[sig].urgentes.vacia())
        usuarios[sig].basicos.pop();
    else
        usuarios[sig].urgentes.pop();
}

void Impresora::cancelarUsuario(const Usuario& u){
     // Buscar u usuario en vector
    for(size_t i=0 ; i < nUsuarios ; i++)
        if(u._id == usuarios[i]._id)
            usuarios[i] = usuarios[nUsuarios]; // se sobrescribe con el ultimo elemento
    nUsuarios--; // Reducimos la longitud de lso usuarios
}

#endif