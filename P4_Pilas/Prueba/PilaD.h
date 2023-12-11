// PilaDy dinamica

#include <cassert>

template <typename T> class Pila {
	public:
		Pila(); // Constructor
		Pila(const Pila<T>& P); // Constructor copia
		
		Pila<T>& operator =(const Pila<T>& P);
		bool vacia() const;
		const T& tope() const;
		void pop();
		void push(const T& x);
		
		~Pila(); // Destuctor
	private:
		struct node{
			T element;
			node* next;
			node(const T& e, node* p = nullptr): element(e), next(p) {}
		};
		node* _pTop;
		void copy(const Pila<T>& P);
};
