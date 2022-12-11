#ifndef EMPREGADOR_H
#define	EMPREGADOR_H

#include "Pessoa.h"
#include "Trabalhador.h"

#include <vector>

using std::vector;

class Empregador:public Pessoa {
    friend ostream &operator<<(ostream &, const Empregador &);

    public:
        Empregador();
        Empregador(string, string, const Pessoa &);
        Empregador(const Empregador &);
        ~Empregador();

        void contrataTrabalhador(const Trabalhador &);
        void demiteTrabalhador();
        void printContratados() const;

        bool operator==(const Empregador &) const;
        bool operator!=(const Empregador &) const;

    private:
        string areaDeAtuacao;
        string contato;
        vector <Trabalhador *> contratados;
        int numContratados;
};

#endif