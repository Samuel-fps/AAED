#include "hospital.h"

void Hospital::ingreso(Paciente pac)
{
    if( pac.gravedad > 0 && pac.gravedad < 6 )
    {
       if( actualUCI_ <= totalUCI_) uci_.insertar(pac, uci_.primera());
       else
       {
            ListaE<Paciente>::posicion pos = uci_.siguiente(uci_.primera());
            int mayor = uci_.elemento(uci_.primera()).gravedad;
            ListaE<Paciente>::posicion posMayor = uci_.primera();
            while( pos != uci_.fin() )
            {
                if( mayor < uci_.elemento(pos).gravedad )
                {
                    mayor = uci_.elemento(pos).gravedad;
                    posMayor = pos;
                }
                pos = uci_.siguiente(pos);
            }
            ingreso(uci_.elemento(posMayor));
            uci_.insertar(pac, uci_.primera());
            ++actualUCI_;
       }
    }
    else if( pac.gravedad > 5 && pac.gravedad < 10 )
    {
        if( actualPlanta_ <= totalPlanta_ ) planta_.insertar(pac, planta_.primera());
        else
        {
            ListaE<Paciente>::posicion pos = planta_.siguiente(planta_.primera());
            int mayor = planta_.elemento(planta_.primera()).gravedad;
            ListaE<Paciente>::posicion posMayor = planta_.primera();
            while( pos != planta_.fin() )
            {
                if( mayor < planta_.elemento(pos).gravedad )
                {
                    mayor = planta_.elemento(pos).gravedad;
                    posMayor = pos;
                }
                pos = planta_.siguiente(pos);
            }
            alta(planta_.elemento(posMayor));
            planta_.insertar(pac, planta_.primera());
            ++actualPlanta_;
       }
    }
}

void Hospital::alta(Paciente pac)
{
    if( pac.gravedad > 0 && pac.gravedad < 6 ) uci_.eliminar(uci_.buscar(pac));
    else if( pac.gravedad > 5 && pac.gravedad < 10 ) planta_.eliminar(planta_.buscar(pac));
}

void Hospital::muerte(Paciente pac)
{
    alta(pac);
}

ListaE<Hospital::Paciente> Hospital::UCI()
{
    return uci_;
}

ListaE<Hospital::Paciente> Hospital::Planta()
{
    return planta_;
}

ListaE<Hospital::Paciente> Hospital::gravedad(int grav)
{
    ListaE<Hospital::Paciente> aux(actualPlanta_ + actualUCI_);

    for( ListaE<Paciente>::posicion pos = uci_.primera(); pos != uci_.fin(); pos = uci_.siguiente(pos) )
    {
        if( uci_.elemento(pos).gravedad == grav ) aux.insertar(uci_.elemento(pos), aux.primera());
    }

    for( ListaE<Paciente>::posicion pos = planta_.primera(); pos != planta_.fin(); pos = planta_.siguiente(pos) )
    {
        if( planta_.elemento(pos).gravedad == grav ) aux.insertar(planta_.elemento(pos), aux.primera());
    }
    return aux;
}
