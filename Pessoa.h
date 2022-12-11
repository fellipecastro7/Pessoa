#ifndef PESSOA_H
#define PESSOA_H

#include "Data.h"

#include <iostream>

using std::string;
using std::ostream;

class Pessoa {
  public:
    Pessoa();
    Pessoa(string, string, string, const Data & = Data(5, 7, 2015));
    Pessoa(string, string);
    Pessoa(const Pessoa &);
    ~Pessoa();

    void setNomeCompleto(string, string);
    string getNomeCompleto() const;
    string getSexo() const;
    Data getDataNascimento() const;
    int calculaAnoAtual() const;
    int calculaIdade() const;
    virtual void aposentar() = 0;
    virtual int calculaTempoDeTrabalho() = 0;

  private:
    string nome;
    string sobrenome;
    string sexo;
    Data dataNascimento;
    int idade;
};

#endif