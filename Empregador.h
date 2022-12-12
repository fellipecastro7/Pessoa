#ifndef EMPREGADOR_H
#define	EMPREGADOR_H

#include "Pessoa.h"

#include <vector>

using std::vector;

class Empregador:public Pessoa {
    public:
        Empregador();
        Empregador(string, string, string, const Data & = Data(5, 7, 2015));
        Empregador(const Empregador &);
        ~Empregador();

        void aposentar();
        int calculaTempoDeTrabalho();
        virtual void contratar(string) = 0;
        virtual void demitir(string) = 0;

    private:
        int numEmpregadores;
        int numContratados;
        int anosDeContribuicao;
        bool aposentado;
};

#endif