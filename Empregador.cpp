#include "Empregador.h"
#include "Trabalhador.h"

#include <iostream>

using std::cout;
using std::cin;

Empregador::Empregador()
:areaDeAtuacao(""), contato(""), numContratados(0)
{

}

Empregador::Empregador(string nome, string sobrenome, string sexo, const Data &dataOut)
:Pessoa(nome, sobrenome, sexo, dataOut), numContratados(0)
{

}

Empregador::Empregador(const Empregador &outroEmpregador)
:Pessoa(outroEmpregador), areaDeAtuacao(outroEmpregador.areaDeAtuacao), contato(outroEmpregador.contato), numContratados(outroEmpregador.numContratados)
{
    /*contratados.resize(outroEmpregador.contratados.size());
  
	  for(int i = 0; i < contratados.size(); i++) {
	    contratados[i] = new Trabalhador(*outroEmpregador.contratados[i]);
    }*/
}

Empregador::~Empregador()
{
    for(int i = 0; i < contratados.size(); i++) {
		  delete contratados[i];
    }
}

void Empregador::contrataTrabalhador(const Trabalhador &pessoa) {
    //contratados.push_back(new Trabalhador(pessoa));
    numContratados++;
}

void Empregador::printContratados() const {
    cout << "\nLista de contratados:\n";

    for(int i = 0; i < contratados.size(); i++) {
        cout << "- " << contratados[i]->getNomeCompleto() << "\n";
        cout << "\t> Salário: R$" << contratados[i]->getSalario() << "\n";
        cout << "\t> Salário por hora: R$" << contratados[i]->getSalarioPorHora() << "\n";
        cout << "\t> Horas de trabalho mensais: " << contratados[i]->getHorasDeTrabalhoMensais() << " horas\n";
        cout << "\t> Horas de trabalho semanais: " << contratados[i]->getHorasDeTrabalhoSemanais() << " horas\n";
    }
}

void Empregador::demiteTrabalhador() {
  cout << "\nHoras semanais mínima: 44 horas" << "\n";

  for(int i = 0; i < contratados.size(); i++) {
    if(contratados[i]->getVinculoEmpregaticio() == "Sim") {
      if(contratados[i]->getHorasDeTrabalhoSemanais() < 44) {
        cout << "Trabalhador " << contratados[i]->getNomeCompleto() << " demitido! Horas de trabalho semanais realizadas: " << contratados[i]->getHorasDeTrabalhoSemanais() << " horas\n";

          delete contratados[i];
          numContratados--;
      }
    }

    else {
      cout << "Trabalhador " << contratados[i]->getNomeCompleto() << " não pode ser demitido, pois não possui vínculo empregatício\n";
    }
  }
}