#include "Pessoa.h"
#include "Pessoa.cpp"
#include "Data.h"
#include "Data.cpp"
#include "Trabalhador.h"
#include "Trabalhador.cpp"
#include "Empregador.h"
#include "Empregador.cpp"
#include "Proprietario.h"
#include "Proprietario.cpp"
#include "Inquilino.h"
#include "Inquilino.cpp"
#include "Rural.h"
#include "Rural.cpp"

#include <iostream>
#include <windows.h>

using std::cout;

int main() {
  SetConsoleOutputCP(CP_UTF8);

  Proprietario *proprietario1 = new Proprietario("João", "Silveira", "Masculino", "Brasileira", 2, Data(2, 4, 1965));
  Casa casa1;
  Casa casa2;

  casa1.numComodos = 4;
  casa1.tipo = "Alvenaria";
  casa1.comprimento = 4;
  casa1.altura = 4;

  casa2.numComodos = 5;
  casa2.tipo = "Madeira";
  casa2.comprimento = 4;
  casa2.altura = 4;

  cout << *proprietario1 << "\n";
  proprietario1->printCasasAlugadas();
  proprietario1->perguntaVinculoEmpregaticio();
  
  if(proprietario1->getVinculoEmpregaticio() == "Sim") {
    proprietario1->setProfissao("Engenheiro elétrico");
    proprietario1->calculaAnosDeContribuicao(57);
    proprietario1->calculaHorasDeTrabalhoMensais(44);
    proprietario1->calculaSalarioPorHora(7500);
  }

  else {
    proprietario1->setProfissao("Professor particular");
    proprietario1->setSalario(2200);
  }

  Inquilino *inquilino1 = new Inquilino("Raimundo", "Nonato", "Masculino", 700, 6, Data(2, 4, 2002));
  Inquilino *inquilino2 = new Inquilino("Tiririca", "Florentina", "Masculino", 650, 4, Data(7, 12, 1990));

  proprietario1->adicionaCasa(casa1);
  proprietario1->adicionaInquilino(*inquilino1);
  proprietario1->adicionaCasa(casa2);
  proprietario1->adicionaInquilino(*inquilino2);
  cout << *proprietario1 << "\n";
  proprietario1->printCasasAlugadas();
  proprietario1->aposentar();
  cout << "\n" << *proprietario1 << "\n";
  proprietario1->printCasasAlugadas();

  //Rural *rural1 = new Rural("Otávio", "Oliveira", "Masculino", "Brasileira", "999999999", Data(19, 12, 1970));

  vector <Trabalhador *> trabalhadores;
  trabalhadores.push_back(new Proprietario(*proprietario1));
  trabalhadores.push_back(new Inquilino(*inquilino1));

  cout << "\n- Situação dos trabalhadores -\n";

  for(Trabalhador *trabalhador:trabalhadores) {
    cout << "Nome: " << trabalhador->getNomeCompleto() << "\n";
    cout << "Está aposentado? " << (trabalhador->getAposentado() ? "Sim" : "Não") << "\n";
  }

  /*cout << *rural1 << "\n";
  rural1->printContratados();
  rural1->calculaAnosDeContribuicao(52);
  rural1->contratar("João");
  rural1->contratar("Maria");
  cout << "\n" << *rural1 << "\n";
  rural1->printContratados();
  rural1->aposentar();
  cout << "\n" << *rural1 << "\n";
  rural1->printContratados();*/

  return 0;
}