#ifndef INQUILINO_H
#define INQUILINO_H

#include "Trabalhador.h"
#include <iostream>

using std::string;
using std::ostream;

class Inquilino:public Trabalhador {
    friend ostream &operator<<(ostream &, const Inquilino &);

    public:
        Inquilino();
        Inquilino(string, string, string, float, int, const Data & = Data(5, 7, 2015));
        Inquilino(const Inquilino &);
        ~Inquilino();

        float getAluguel() const;
        int getTempo() const;
        int calculaAluguelFinal() const;
        void aposentar();
        int calculaTempoDeTrabalho();

        bool operator==(const Inquilino &) const;
        bool operator!=(const Inquilino &) const;

    private:
        float aluguel;
        int tempo;
        int anosDeContribuicao;
        bool aposentado;
};

#endif