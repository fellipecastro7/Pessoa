#ifndef PROPRIETARIO_H
#define PROPRIETARIO_H

#include "Trabalhador.h"

#include <iostream>
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
} Casa;

class Proprietario:public Trabalhador {
    friend ostream &operator<<(ostream &, const Proprietario &);

    public:
        Proprietario();
        Proprietario(string, const Trabalhador &);
        Proprietario(const Proprietario &);
        ~Proprietario();

        double calculaArea();
        void adicionaCasa(const Casa &);
        void printCasasAlugadas() const;

        bool operator==(const Proprietario &) const;
        bool operator!=(const Proprietario &) const;

    private:
        string nacionalidade;
        Data ultimaCasaAlugada;
        vector <Casa *> casasAlugadas;
        vector <string *> inquilinosCasas;
        int numCasasAlugadas;
};

#endif