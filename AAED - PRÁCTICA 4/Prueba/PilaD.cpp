#include "PilaD.h"

// Método privado
template <typename T>
void Pila<T>::copiar(const Pila<T>& P){
	if (!P.vacia()) {
		tope_ = new nodo(P.tope()); // Copiar el primer elto
		// Copiar el resto de elementos hasta el fondo de la pila.
		nodo* p = tope_; // Recorre la pila destino
		nodo* q = P.tope_->sig; // 2º nodo, recorre la pila origen
		while (q) {
			p->sig = new nodo(q->elto);
			p = p->sig;
			q = q->sig;
		}
	}
}

template <typename T>
Pila<T>::Pila() : _pTop(nullptr) {}

template <typename T>
Pila<T>::Pila(const Pila& P) : _pTop(nullptr){ copiar(P); }

template <typename T>
Pila<T>& Pila<T>::operator =(const Pila<T>& P){
	if(this != &P){ // Autoasignacion
		this->~Pila(); // ¿Vaciamos? la pila actual
		copiar(P); // Copiamos la asignada
	}
	return *this;
}

template <typename T>
bool Pila<T>::vacia(){ return _pTop == nullptr; }

template <typename T>
T& Pila<T>::tope() const{
	assert(!vacia());
	return _pTop->element;
}



