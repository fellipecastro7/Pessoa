#ifndef INQUILINO_H
#define INQUILINO_H

#include "Trabalhador.h"

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
        int getTempoDeAluguel() const;
        float calculaAluguelFinal() const;
        void aposentar();
        int calculaAnosDeContribuicao();

        bool operator==(const Inquilino &) const;
        bool operator!=(const Inquilino &) const;
        Inquilino& operator=(const Inquilino &);
        Inquilino& operator!();

    private:
        float aluguel;
        int tempoDeAluguel;
        int anosDeContribuicao;
};

#endif