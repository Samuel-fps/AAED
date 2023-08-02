#ifndef ESCALONADA_HPP
#define ESCALONADA_HPP

#include <iostream>
#include <cassert>
#include "listadinamica.h"

struct funcion
	{
		funcion(double i, double a): ini(i), alt(a);
		double ini, alt;
	};	

typedef Lista<funcion>::posicion pos;

class escalonada{
public:
	escalonada(funcion&){}
	void aniadirsalto(double, double);
	void eliminarescalon(double);
	double valorenunpunto(double);
	double valormin();
	double valormax();
	~escalonada();
private:
	Lista<funcion> list;
};

escalonada::escalonada(funcion& f):{
	pos primera = l.primera();
	list.insertar(f, primera);
}

void escalonada::aniadirsalto(double x, double y)
{
	bool insertada = false;
	posicion pos = list.primera();

	while(pos != list.fin() && !insertada)
	{
		if(list.elemento(pos).ini == x)
		{
			list.elemento(pos).alt = y;
			insertada = true;
		}
		else if(list.elemento(pos).ini <= x && list.elemento(siguiente(pos)) == list.fin())
		{
			list.insertar(funcion(x,y), pos);
			insertada = true;
		}
		else if(list.elemento(pos).ini > x)
		{
			list.insertar(funcion(x,y), pos);
			insertada = true;
		}
		else if(list.elemento(pos).ini <= x && list.elemento(siguiente(pos)).ini > x)
		{
			list.insertar(funcion(x,y), pos);
			insertada = true;
		}
		else
			pos = list.siguiente(pos);			
	}
}

void escalonada::eliminarescalon(double x)
{
	assert(x >= valormin());

	bool eliminado = false;
	posicion pos = list.primera();

	while(pos != list.fin() && !eliminado)
	{
		if(list.siguiente(pos) == fin && x > list.elemento(pos).ini)
		{
			list.eliminar(pos);
			eliminado = true:
		}
		else if(list.elemento(pos).ini <= x && list.elemento(siguiente(posicion)).ini > x)
		{
			list.eliminar(pos);
			eliminado = true;
		}
		else
			pos = list.siguiente(pos);
	}
	
}

double escalonada::valorenunpunto(double x)
{
	assert(x >= valormin());

	posicion pos = list.primera();

	while(posicion != list.fin())
	{
		if(list.siguiente(pos) == fin && x > list.elemento(pos).ini)
			return list.elemento(posicion).alt;
		else if(list.elemento(posicion).ini <= x && list.elemento(siguiente(posicion)).ini > x)
			return list.elemento(posicion).alt;
		else
			pos = list.siguiente(posicion);
	}
}

double escalonada::valormin(){
	posicion pos = list.primera();
	assert(pos != list.fin());

	double minimo = list.elemento(list.primera()).alt;
	pos = list.siguiente(list.primera());

	while(pos != list.fin())
	{
		if(list.elemento(pos).alt < minimo)
			minimo = list.elemento(pos).alt;
		else
			pos = list.siguiente(pos);
	}
	return minimo;
}

double escalonada::valormax(){
	posicion pos = list.primera();
	assert(pos != list.fin());

	double maximo = list.elemento(list.primera()).alt;
	pos = list.siguiente(list.primera());

	while(posicion != list.fin())
	{
		if(list.elemento(pos).alt > maximo)
			maximo = list.elemento(pos).alt;
		else
			pos = list.siguiente(pos);
	}
	return maximo;
}

escalonada::~escalonada(){
	~list.~Lista();
}

#endif