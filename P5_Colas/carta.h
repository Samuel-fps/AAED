#ifndef TCARTA_H
#define TCARTA_H

#include <iostream>

enum tpalo {OROS, COPAS, ESPADAS, BASTOS};
enum tfig {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};

class tCarta {
    public:
        tCarta(tpalo p = OROS, tfig f = AS) : palo_(p), fig_(f) {};
        tpalo palo() const { return palo_; };
        tfig fig() const { return fig_; };  
        friend std::ostream& operator <<(std::ostream& os, const tCarta& c);
    private:
        tpalo palo_;
        tfig fig_;
        static const char* nom_palo[], * nom_fig[];
};

#endif // TCARTA_H