#ifndef CURSOR_HPP
#define CURSOR_HPP

#include "pilaenlazada.h"

class Cursor
{
public:
	void avanzar();
	void retrasar();
	void goPpo();
	void goFinal();
	void borrarCaracterCursor();
	void borrarAnterior();
	void insertarCursor(const char& c);
	void sobreescribir(const char& c);
private:
	Pila<char> p1,p2;
};

inline void Cursor::avanzar()
{
	assert(!p2.vacia());
	p1.push(p2.tope());
	p2.pop();
}

inline void Cursor::retrasar()
{
	assert(!p1.vacia());
	p2.push(p1.tope());
	p1.pop();
}

inline void Cursor::goPpo()
{
	assert(!p1.vacia());
	while(!p1.vacia())
	{
		p2.push(p1.tope());
		p1.pop();
	}
}

inline void Cursor::goFinal()
{
	assert(!p2.vacia());
	while(!p2.vacia())
	{
		p1.push(p2.tope());
		p2.pop();
	}
}

inline void Cursor::borrarCaracterCursor()
{
	assert(!p1.vacia())
	p1.pop();
}

inline void Cursor::borrarAnterior()
{
	assert(!p2.vacia())
	p2.pop();
}

inline void insertarCursor(const char& c)
{
	p1.push(c);
}

inline void sobreescribir(const char& c)
{
	assert(!p1.vacia())
	p1.pop()
	p1.push(c);
}

#endif //CURSOR_HPP