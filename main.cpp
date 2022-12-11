#include "Pessoa.h"
#include "Pessoa.cpp"
#include "Data.h"
#include "Data.cpp"
#include "Trabalhador.h"
#include "Trabalhador.cpp"
#include "Empregador.h"
#include "Empregador.cpp"

#include <iostream>
#include <windows.h>

using std::cout;

int main() {
  SetConsoleOutputCP(CP_UTF8);

  Pessoa *pessoaTeste = new Pessoa("Nome", "Sobrenome", "Sexo", Data(7, 7, 2003));
  Pessoa *pessoaTeste2 = new Pessoa("Nome2", "Sobrenome2", "Sexo2", Data(2, 1, 1990));
  Pessoa *pessoaTeste3 = new Pessoa("Nome3", "Sobrenome3", "Sexo3", Data(2, 5, 1999));
  Pessoa *pessoaTeste4 = new Pessoa("Nome4", "Sobrenome4", "Sexo4", Data(6, 9, 2004));

  Trabalhador *trabalhadorTeste = new Trabalhador(*pessoaTeste3);
  Trabalhador *trabalhadorTeste2 = new Trabalhador(*pessoaTeste4);

  trabalhadorTeste->perguntaVinculoEmpregaticio();
  
  if(trabalhadorTeste->getVinculoEmpregaticio() == "Sim") {
    trabalhadorTeste->setProfissao("Engenheiro elétrico");
    trabalhadorTeste->calculaHorasDeTrabalhoMensais(20);
    trabalhadorTeste->calculaSalarioPorHora(5500.00);
  }

  else {
    trabalhadorTeste->setProfissao("Professor particular");
    trabalhadorTeste->setSalario(2200);
  }
  
  cout << *trabalhadorTeste << "\n";

  trabalhadorTeste2->perguntaVinculoEmpregaticio();
  
  if(trabalhadorTeste2->getVinculoEmpregaticio() == "Sim") {
    trabalhadorTeste2->setProfissao("Bancário");
    trabalhadorTeste2->calculaHorasDeTrabalhoMensais(44);
    trabalhadorTeste2->calculaSalarioPorHora(3500.00);
  }

  else {
    trabalhadorTeste2->setProfissao("Organizador de festas");
    trabalhadorTeste2->setSalario(2100);
  }

  Empregador *empregadorTeste = new Empregador("Área de atuação", "Número para contato", *pessoaTeste2);

  empregadorTeste->contrataTrabalhador(*trabalhadorTeste);
  empregadorTeste->contrataTrabalhador(*trabalhadorTeste2);
  //cout << "\n" << *empregadorTeste << "\n";
  empregadorTeste->demiteTrabalhador();

  //Empregador *empregadorTeste2 = new Empregador(*empregadorTeste);
  //cout << (*empregadorTeste == *empregadorTeste2);

  return 0;
}