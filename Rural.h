#ifndef RURAL_H
#define	RURAL_H

#include "Empregador.h"

class Rural:public Empregador {
    friend ostream &operator<<(ostream &, const Rural &);

    public:
        Rural();
        Rural(string, string, string, string, string, const Data & = Data(5, 7, 2015));
        Rural(const Rural &);
        ~Rural();
        
        void printContratados() const;
        void aposentar();
        int calculaAnosDeContribuicao();
        void contratar(string);
        void demitir(string);

        bool operator==(const Rural &) const;
        bool operator!=(const Rural &) const;
        Rural& operator=(const Rural &);
        Rural& operator!();

    private:
        static const string AREADEATUACAO;
        string contato;
        string nacionalidade;
        vector <string *> contratados;
        int numContratados;
        int anosDeContribuicao;
        int vagas;
};

#endif