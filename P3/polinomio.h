#ifndef POLINOMIO_H
#define POLINOMIO_H

template <typename T>
class polinomio {
    public:
        polinomio(unsigned gradoMax);
        grado() const;
        double coeficiente(unsigned n) const;
        void coeficiente(unsigned n, double c);
    private:
        double* coeficientes;
        unsigned gradoMax;

};

polinomio::polinomio(unsigned n) : gradoMax(n), coeficientes(new double[n]){}

polinomio::grado() const { 
    unsigned grado=0;
    for(unsigned i=0 ; i < gradoMax ; i++)
        if(coeficientes[i] != 0)
            grado = i;
    return grado;
}


double polinomio::coeficiente(unsigned n) const { return coeficientes[n]; }

void polinomio::coeficiente(unsigned n, double c){
    coeficientes[n] = c;
}

#endif