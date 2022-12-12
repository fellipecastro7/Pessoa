#include "Empregador.h"

#include <iostream>

using std::cout;
using std::cin;

Empregador::Empregador()
:numContratados(0)
{

}

Empregador::Empregador(string nome, string sobrenome, string sexo, const Data &dataOut)
:Pessoa(nome, sobrenome, sexo, dataOut), numContratados(0)
{

}

Empregador::Empregador(const Empregador &outroEmpregador)
:Pessoa(outroEmpregador), numContratados(outroEmpregador.numContratados)
{

}

Empregador::~Empregador()
{

}

/*void Empregador::printContratados() const {
    cout << "\nLista de contratados:\n";

    for(int i = 0; i < contratados.size(); i++) {
        cout << "- " << contratados[i]->getNomeCompleto() << "\n";
        cout << "\t> Salário: R$" << contratados[i]->getSalario() << "\n";
        cout << "\t> Salário por hora: R$" << contratados[i]->getSalarioPorHora() << "\n";
        cout << "\t> Horas de trabalho mensais: " << contratados[i]->getHorasDeTrabalhoMensais() << " horas\n";
        cout << "\t> Horas de trabalho semanais: " << contratados[i]->getHorasDeTrabalhoSemanais() << " horas\n";
    }
}*/

/*void Empregador::adicionaRural(const Rural &rural) {
  empregadores.push_back(new Rural(rural));
  numEmpregadores++;
}*/

void Empregador::aposentar() {
    string opcao;

    cout << "Empregador -> Deseja se aposentar? [S/N] ";
    cin >> opcao;

    while(opcao != "S" && opcao != "s" && opcao != "N" && opcao != "n") {
        cout << "Empregador -> Deseja se aposentar? [S/N] ";
        cin >> opcao;
    }

    if(opcao == "n" || opcao == "N") {
        aposentado = false;
    }

    if(opcao == "S" || opcao == "s") {
        if(calculaTempoDeTrabalho() < 35) {
            cout << "Não é possível se aposentar. Tempo de contribuição inferior a 35 anos\n";
            aposentado = false;
        }

        else {
            cout << "Aposentado! tempo de contribuição: " << calculaTempoDeTrabalho() << " anos\n";
            aposentado = true;
        }
    }
}

int Empregador::calculaTempoDeTrabalho() {
    return anosDeContribuicao;
}

/*void Empregador::demiteTrabalhador() {
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
}*/