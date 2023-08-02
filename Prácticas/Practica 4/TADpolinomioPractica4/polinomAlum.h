#ifndef POLINOMALUM_H_INCLUDED
#define POLINOMALUM_H_INCLUDED

class polinomioAlum{
public:

    //Postcondiciones: Crea el polinomio nulo. El objetivo de este método es crear un objeto polinomio,
    //reservando el espacio necesario e inicializando con el valor nulo.
    explicit polinomioAlum (unsigned gradoMax);

    //Postcondiciones: Devuelve el grado de un polinomio.
    unsigned grado () const;

    //Postcondiciones: Devuelve el coeﬁciente correspondiente al monomio de grado n de un polinomio. Si n > gradoMax, devuelve 0.
    double coeficiente (unsigned n) const;

    //Precondiciones: n <= gradoMax
    //Postcondiciones: Asigna al monomio de grado n el coeﬁciente c.
    void coeficiente (unsigned n, double c);

    //Postcondiciones: Imprime por pantalla el polinomio p
    void imprime () const;

    /*SOBRECARGA DE OPERADORES*/
    friend polinomioAlum operator + (const polinomioAlum& p1, const polinomioAlum& p2);
    friend polinomioAlum operator - (const polinomioAlum& p1, const polinomioAlum& p2);
    friend polinomioAlum operator * (const polinomioAlum& p1, const polinomioAlum& p2);
    friend polinomioAlum operator / (const polinomioAlum& p1, const polinomioAlum& p2);

    friend polinomioAlum operator += (polinomioAlum& p1, const polinomioAlum& p2);
    friend polinomioAlum operator -= (polinomioAlum& p1, const polinomioAlum& p2);
    friend polinomioAlum operator *= (polinomioAlum& p1, const polinomioAlum& p2);
    friend polinomioAlum operator /= (polinomioAlum& p1, const polinomioAlum& p2);

    friend bool operator != (const polinomioAlum& p1, const polinomioAlum& p2);
    friend bool operator <= (const polinomioAlum& p1, const polinomioAlum& p2);
    friend bool operator > (const polinomioAlum& p1, const polinomioAlum& p2);
    friend bool operator >= (const polinomioAlum& p1, const polinomioAlum& p2);

private:
    unsigned gMax; //Guarda el grado máximo que puede alcanzar el polinomio
    unsigned pElem; //Guarda el numero de monomios que forma el polinomio más uno del término independiente
    double *coef; //Puntero a los coeficientes de cada monomio
};

#endif // POLINOMALUM_H_INCLUDED

