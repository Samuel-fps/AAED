#include "PilaPs.h"

// Constructor PilaPs
PilaPs::PilaPs(unsigned uSizeMax) :
	_aElements(new tElement[uSizeMax]), 
	_uLMax(uSizeMax),
	_uElements(0)
{}

// Constructor de copia PilaPs
PilaPs::PilaPs(const PilaPs& P) :
	_aElements(new tElement[P._uLMax]), 
	_uLMax(P._uLMax),
	_uElements(P._uElements)
{
	for(int i=0 ; i<P._uElements ; i++) // Copiar elementos 1 a 1
		_aElements[i] = P._aElements[i];
}

// Operaciones
PilaPs& PilaPs::operator =(const PilaPs& P) {
	if(this != &P){ // Autoasignacion
		if(_uLMax != P._uLMax){ // No miden los mismo
			delete [] _aElements;
			_uLMax = P._uLMax;
			_aElements = new tElement[_uLMax];
		} // Si miden los mismo no redimensionamos el vector
		_uElements = P._uElements;
		for(int i=0 ; i<P._uElements ; i++) // Copiar elementos 1 a 1
			_aElements[i] = P._aElements[i];
	};
	return *this;
}

bool PilaPs::vacia() const { return _uElements == 0; }

bool PilaPs::PilaPs::llena() const { return _uElements == _uLMax; }

const PilaPs::tElement& PilaPs::tope() const {
	assert(!vacia());
	return _aElements[_uElements-1];
}

void PilaPs::pop(){
	assert(!vacia());
	_uElements--;
}

void PilaPs::push(const tElement& x){
	assert(!llena());
	_aElements[_uElements] = x;
	_uElements++;
}

PilaPs::~PilaPs(){
	delete [] _aElements; // ¿Habría que igualar a 0 el numero de elementos?
}


