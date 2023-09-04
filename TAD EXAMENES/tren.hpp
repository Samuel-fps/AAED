#ifndef TREN_HPP
#define TREN_HPP

/*

DEFINICION:
    Secuencia de elemento de tipo Vagon con uno d ellos como Vagon activo.

ESPECIFICACION:
    Tren();
        Pre:
        Post:   Crea un tren vacio.
    void desplazarIzq();
        Pre:    El tren tiene al menos un vagon.
        Post:   El vagon activo pasa a ser el de la derecha.

    void desplazarDrch();
        Pre:    El tren tiene al menos un vagon.
        Post:   El vagon activo pasa a ser el de la izquierda

    void eliminarVagon();
        Pre:    El tren tiene al menos un vagon.
        Post:   Elimina el vagon activo y el vagon activo pasa a el de la derecha si existe
                si no existe vagon a la derecha, vagonActivo=VagonIzq
    const Vagon VagonActivo();
        Pre:    El tren tiene al menos un vagon.
        Post:   Devuelve el vagon activo en este mmento.
    Vacio();
        Pre:
        Post:   Devuelve true si es Tren esta vacio o false si no lo esta.
*/

class Tren {
    public:
        typedef int Vagon;

        Tren();
        ~Tren();
        void desplazarIzq();
        void desplazarDrch();
        void eliminarVagon();
        const Vagon& vagonActivo();
        bool vacio();

    private:
        Pila<Vagon> izquierda;
        Pila<Vagon> derecha; // vagonActivo = Tope Pila derecha
};

#endif

/*
TAD CONOCIDOS
*/