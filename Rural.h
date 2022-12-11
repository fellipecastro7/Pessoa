#ifndef RURAL_H
#define	RURAL_H

#include "Empregador.h"

class Rural:public Empregador {
    friend ostream &operator<<(ostream &, const Rural &);

    public:
        Rural();
        Rural(string, string, string, string, const Data & = Data(5, 7, 2015));
        Rural(const Rural &);
        ~Rural();
        
        void printContratados() const;
        void contratar(string);
        void demitir(string);

        bool operator==(const Rural &) const;
        bool operator!=(const Rural &) const;

    private:
        string areaDeAtuacao;
        string contato;
        string nacionalidade;
        vector <string *> nomeContratados;
        int numContratados;
        int anosDeContribuicao;
        bool aposentado;
};

#endif