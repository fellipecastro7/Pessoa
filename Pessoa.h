#ifndef PESSOA_H
#define PESSOA_H

#include "Data.h"

#include <iostream>

using std::string;

class Pessoa {
  public:
    Pessoa();
    Pessoa(string, string, string, const Data & = Data(5, 7, 2015));
    Pessoa(const Pessoa &);
    ~Pessoa();

    string getNomeCompleto() const;
    string getSexo() const;
    int calculaAnoAtual() const;
    int calculaIdade() const;
    virtual void aposentar() = 0;
    virtual int calculaAnosDeContribuicao() = 0;

  private:
    string nome;
    string sobrenome;
    string sexo;
    Data dataNascimento;
    int idade;
};

#endif