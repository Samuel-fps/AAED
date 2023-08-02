// Pila Pseudoestatica

#include <cassert>

class PilaPs {
	public:
		typedef int tElement;
		PilaPs(unsigned uTMax);				// Constructor
		PilaPs(const PilaPs& P);					// Constructor copia
		
		PilaPs& operator =(const PilaPs& P);	// Asignacion
		bool vacia() const;
		bool llena() const;
		const tElement& tope() const;
		void pop();
		void push(const tElement& x);
		
		~PilaPs();			// Destructor
	private:
		tElement *_aElements;
		unsigned _uLMax;
		unsigned _uElements;
};
