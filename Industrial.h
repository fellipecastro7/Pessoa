#ifndef INDUSTRIAL_H
#define	INDUSTRIAL_H

#include "Empregador.h"

#include <iostream>
#include <vector>

using std::vector;
using std::ostream;

class Industrial:public Empregador {
    friend ostream &operator<<(ostream &, const Industrial &);

    public:
        Industrial();
        Industrial(string, string, string, string, string, const Data & = Data(5, 7, 2015));
        Industrial(const Industrial &);
        ~Industrial();
        
        void printContratados() const;
        void aposentar();
        int calculaAnosDeContribuicao();
        void contratar(string);
        void demitir(string);

        bool operator==(const Industrial &) const;
        bool operator!=(const Industrial &) const;
        Industrial& operator=(const Industrial &);
        Industrial& operator!();

    private:
        static const string AREADEATUACAO;
        string contato;
        string nacionalidade;
        vector <string *> nomeContratados;
        int numContratados;
        int anosDeContribuicao;
        int vagas;
};

#endif