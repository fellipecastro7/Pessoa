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
#include "Industrial.h"
#include "Industrial.cpp"

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
  casa2.comprimento = 5;
  casa2.altura = 5;

  cout << *proprietario1 << "\n";
  proprietario1->printCasasAlugadas();
  cout << "\n";
  proprietario1->perguntaVinculoEmpregaticio();
  
  if(proprietario1->getVinculoEmpregaticio() == "Sim") {
    proprietario1->setProfissao("Engenheiro elétrico");
    proprietario1->calculaAnosDeContribuicao();
    proprietario1->calculaHorasDeTrabalhoMensais(41);
    proprietario1->calculaSalarioPorHora(7276);
  }

  else {
    proprietario1->setProfissao("Professor particular");
    proprietario1->setSalario(1069);
  }

  Inquilino *inquilino1 = new Inquilino("Raimundo", "Guimarães", "Masculino", 500, 6, Data(2, 4, 1985));
  Inquilino *inquilino2 = new Inquilino("Maria", "Conceição", "Feminino", 700, 4, Data(7, 12, 1990));

  proprietario1->adicionaCasa(casa1);
  proprietario1->adicionaInquilino(*inquilino1);
  proprietario1->adicionaCasa(casa2);
  proprietario1->adicionaInquilino(*inquilino2);
  cout << "Após as mudanças...\n";
  cout << *proprietario1 << "\n";
  proprietario1->printCasasAlugadas();
  proprietario1->aposentar();
  cout << "Após a escolha de aposentadoria...\n";
  cout << "\n" << *proprietario1 << "\n";
  proprietario1->printCasasAlugadas();

  Rural *rural1 = new Rural("Otávio", "Oliveira", "Masculino", "Brasileira", "999999999", Data(19, 12, 1970));
  Rural *rural2;

  (rural2 = rural1);

  cout << "\n" << *rural1 << "\n";
  rural1->printContratados();
  rural1->calculaAnosDeContribuicao();
  rural1->contratar("João");
  rural1->contratar("Maria");
  cout << "Após as contratações...\n";
  cout << "\n" << *rural1 << "\n";
  rural1->printContratados();
  rural1->aposentar();
  cout << "Após a escolha de aposentadoria...\n";
  cout << "\n" << *rural1 << "\n";
  rural1->printContratados();

  vector <Trabalhador *> trabalhadores;
  trabalhadores.push_back(new Proprietario(*proprietario1));
  trabalhadores.push_back(new Inquilino(*inquilino1));
  trabalhadores.push_back(new Inquilino(*inquilino2));

  cout << "\n- Situação dos trabalhadores -\n";

  for(Trabalhador *trabalhador:trabalhadores) {
    cout << "Nome: " << trabalhador->getNomeCompleto() << "\n";
    cout << "Está aposentado? " << (trabalhador->getAposentado() ? "Sim" : "Não") << "\n";
  }

  Industrial *industrial1 = new Industrial("Sophia", "Nascimento", "Feminino", "Brasileira", "999999999", Data(25, 6, 1974));

  cout << "\n\n" << *industrial1 << "\n";
  industrial1->printContratados();
  industrial1->calculaAnosDeContribuicao();
  industrial1->contratar("Augusto");
  industrial1->contratar("Valentina");
  industrial1->contratar("Jorge");
  industrial1->contratar("Lorena");
  cout << "Após as contratações...\n";
  cout << "\n" << *industrial1 << "\n";
  industrial1->printContratados();
  cout << "\n";
  industrial1->aposentar();
  cout << "Após a escolha de aposentadoria...\n";
  cout << "\n" << *industrial1 << "\n";
  industrial1->printContratados();

  vector <Empregador *> empregadores;
  empregadores.push_back(new Rural(*rural1));
  empregadores.push_back(new Industrial(*industrial1));

  cout << "\n- Situação dos empregadores -\n";

  for(Empregador *empregador:empregadores) {
    cout << "Nome: " << empregador->getNomeCompleto() << "\n";
    cout << "Está aposentado? " << (empregador->getAposentado() ? "Sim" : "Não") << "\n";
  }

  cout << "\n\n- Fazendo a comparação entre trabalhadores -\n";
  cout << "-> Inquilino 1 é igual ao Inquilino 2? " << (*inquilino1 == *inquilino2) << "\n";
  cout << "- Igualando os trabalhadores -\n";
  (inquilino2 = inquilino1);
  cout << "-> Analisando as informações após as mudanças\n";
  cout << *inquilino2 << "\n";
  cout << " - Decrementando um mês de aluguel do trabalhador 1 -\n";
  (!*inquilino1);
  cout << "-> Analisando as informações após as mudanças\n";
  cout << *inquilino1 << "\n";

  /*cout << "- Fazendo a comparação entre empregadores -\n";
  cout << "-> Rural 1 é igual ao Rural 2? " << (*rural1 == *rural2) << "\n";
  cout << "- Igualando os trabalhadores -\n";
  (rural2 = rural1);
  cout << "-> Analisando as informações após as mudanças\n";
  cout << *rural2 << "\n";
  cout << " - Decrementando em 1 o número de contratado dos empregadores -\n";
  (!*rural1);
  (!*rural2);
  cout << "-> Analisando as informações após as mudanças\n\n";
  cout << *rural1 << "\n";
  cout << *rural2 << "\n";*/

  for(int i = 0 ; i < trabalhadores.size() ; i++) {
        if(typeid(*trabalhadores[i]).name() == typeid(Proprietario).name()) {
            Proprietario *proprietarioPtr = dynamic_cast <Proprietario *> (trabalhadores[i]);
            cout << "Proprietario: " << proprietarioPtr->getNomeCompleto() << "\n";
            proprietarioPtr->printCasasAlugadas();
        }
  }

  vector <Trabalhador *>::iterator trabalhadoresItr = trabalhadores.begin();
    for(int i = 0 ; i < trabalhadores.size() ; i++) {
        trabalhadoresItr++;
        delete trabalhadores[i];
        trabalhadores.erase(trabalhadoresItr);
    }

  vector <Empregador *>::iterator empregadoresItr = empregadores.begin();
    for(int i = 0 ; i < empregadores.size() ; i++) {
        empregadoresItr++;
        delete empregadores[i];
        empregadores.erase(empregadoresItr);
    }

  delete proprietario1;
  delete inquilino1;
  delete inquilino2;
  delete rural1;
  delete rural2;
  delete industrial1;

  return 0;
}