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
  setNomeCompleto(nome, sobrenome);
}

Pessoa::Pessoa(string nome, string sobrenome)
:nome(nome), sobrenome(""), sexo(""), dataNascimento()
{
  setNomeCompleto(nome, sobrenome);
}

Pessoa::Pessoa(const Pessoa &outraPessoa)
:nome(outraPessoa.nome), sobrenome(outraPessoa.sobrenome), sexo(outraPessoa.sexo), dataNascimento(outraPessoa.dataNascimento)
{
  
}

Pessoa::~Pessoa()
{
  
}

void Pessoa::setNomeCompleto(string nome, string sobrenome) {
  nome = nome;
  sobrenome = sobrenome;
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

    idade = calculaAnoAtual() - dataNascimento.ano;

    return idade;
}

ostream &operator<<(ostream &out, const Pessoa &pessoa) {
  out << "Nome: " << pessoa.getNomeCompleto() << "\n";
  out << "Sexo: " << pessoa.sexo << "\n";
  out << "Data de nascimento: ";
  pessoa.dataNascimento.print();
  out << "\n";
  out << "Idade: " << pessoa.calculaIdade() << " anos";

  return out;
}