#ifndef EMPREGADOR_H
#define	EMPREGADOR_H

#include "Pessoa.h"
#include "Trabalhador.h"

#include <vector>

using std::vector;

class Empregador:public Pessoa {
    public:
        Empregador();
        Empregador(string, string, string, const Data & = Data(5, 7, 2015));
        Empregador(const Empregador &);
        ~Empregador();

        void contrataTrabalhador(const Trabalhador &);
        void demiteTrabalhador();
        void printContratados() const;
        virtual void contratar() = 0;
        virtual void demitir() = 0;

    private:
        string areaDeAtuacao;
        string contato;
        vector <Trabalhador *> contratados;
        int numContratados;
        int anosDeContribuicao;
        bool aposentado;
};

#endif