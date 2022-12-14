#include "Pessoa.h"

#include <time.h>

using std::cout;

Pessoa::Pessoa()
:nome(""), sobrenome(""), sexo(""), dataNascimento()
{
  
}

Pessoa::Pessoa(string nome, string sobrenome, string sexo, const Data &dataOut)
:nome(nome), sobrenome(sobrenome), sexo(sexo), dataNascimento(dataOut)
{

}

Pessoa::Pessoa(const Pessoa &outraPessoa)
:nome(outraPessoa.nome), sobrenome(outraPessoa.sobrenome), sexo(outraPessoa.sexo), dataNascimento(outraPessoa.dataNascimento)
{
  
}

Pessoa::~Pessoa()
{
  
}

string Pessoa::getNomeCompleto() const {
  string nomeCompleto;
  string nome1; 
  string sobrenome1; 
  string aux;

  nome1 = nome;
  aux = " ";
  sobrenome1 = sobrenome;
  nomeCompleto = nome1 + aux + sobrenome1;
  
  return nomeCompleto;
}

string Pessoa::getSexo() const {
  return sexo;
}

int Pessoa::calculaAnoAtual() const {
    struct tm *local;
    time_t t;
    int anoAtual;

    t = time(NULL);
    local = localtime(&t);

    anoAtual = local->tm_year + 1900;

    return anoAtual;
}

int Pessoa::calculaIdade() const {
    int idade;

    idade = calculaAnoAtual() - dataNascimento.getAno();

    return idade;
}