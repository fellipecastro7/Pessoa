#ifndef PROPRIETARIO_H
#define PROPRIETARIO_H

#include "Trabalhador.h"
#include "Inquilino.h"

#include <string>
#include <vector>

using std::string;
using std::vector;
using std::ostream;

typedef struct casa {
    int numComodos;
    string tipo;
    double comprimento;
    double altura;
    double area;

    double getArea() const;
} Casa;

class Proprietario:public Trabalhador {
    friend ostream &operator<<(ostream &, const Proprietario &);

    public:
        Proprietario();
        Proprietario(string, string, string, string, int, const Data & = Data(5, 7, 2015));
        Proprietario(const Proprietario &);
        ~Proprietario();

        void adicionaCasa(const Casa &);
        void adicionaInquilino(const Inquilino &);
        void printCasasAlugadas() const;
        void aposentar();
        int calculaAnosDeContribuicao();

        bool operator==(const Proprietario &) const;
        bool operator!=(const Proprietario &) const;
        Proprietario& operator=(const Proprietario &);
        Proprietario& operator!();

    private:
        int numCasasPossuidas;
        string nacionalidade;
        vector <Casa *> casasAlugadas;
        vector <Inquilino *> inquilinos;
        int numCasasAlugadas;
        int anosDeContribuicao;
};

#endif