#include "listaEnla.h"

class Binario {
    public:
        // Constructor
        Binario(const char* binStr);

        // Operaciones lógicas de bits
        Binario operacionNOT() const;
        Binario operacionAND(const Binario& otro) const;
        Binario operacionOR(const Binario& otro) const;
        Binario operacionXOR(const Binario& otro) const;

        Binario desplazarIzquierda(int n) const;
        Binario desplazarDerecha(int n) const;

        int obtenerValorNumerico() const;
        void imprimirBinario() const;
    private:
        Lista<bool> bin;
};
