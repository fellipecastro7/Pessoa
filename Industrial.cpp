#include "Industrial.h"

#include <iostream>

using std::cout;
using std::cin;

const string Industrial::AREADEATUACAO = "Indústria";

Industrial::Industrial()
:anosDeContribuicao(0), aposentado(false), contato(""), nacionalidade(""), numContratados(0), vagas(0)
{

}

Industrial::Industrial(string nome, string sobrenome, string sexo, string nacionalidade, string contato, const Data &dataOut)
:Empregador(nome, sobrenome, sexo, dataOut), nacionalidade(nacionalidade), aposentado(false), contato(contato), anosDeContribuicao(0), numContratados(0), vagas(0)
{

}

Industrial::Industrial(const Industrial &outroIndustrial)
:Empregador(outroIndustrial), contato(outroIndustrial.contato), nacionalidade(outroIndustrial.nacionalidade), aposentado(outroIndustrial.aposentado), anosDeContribuicao(outroIndustrial.anosDeContribuicao), numContratados(outroIndustrial.numContratados), vagas(outroIndustrial.vagas)
{

}

Industrial::~Industrial()
{
  for(int i = 0; i < nomeContratados.size(); i++) {
		delete nomeContratados[i];
  }
}

void Industrial::calculaAnosDeContribuicao(int idade1) {
    if(idade1 < 18) {
      anosDeContribuicao = 0;

      return;
    }

    anosDeContribuicao = idade1 - 18;
}

void Industrial::printContratados() const {
  cout << "- Nome dos contratados -\n";

  if(nomeContratados.size() != 0) {
    for(int i = 0; i < nomeContratados.size(); i++) {
      cout << "- " << *nomeContratados[i] << "\n";
    }
  }

  else {
    cout << "Não há nenhum trabalhador contratado por esse empregador\n";
  }
}

void Industrial::aposentar() {
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
        if(calculaTempoDeTrabalho() < 15) {
            cout << "Não é possível se aposentar. Tempo de contribuição inferior a 15 anos\n";
            aposentado = false;
        }

        else {
            cout << "Aposentado! tempo de contribuição: " << calculaTempoDeTrabalho() << " anos\n";
            aposentado = true;
        }
    }
}

int Industrial::calculaTempoDeTrabalho() {
    return anosDeContribuicao;
}

void Industrial::contratar(string nome) {
  nomeContratados.push_back(new string(nome));
  numContratados++;
}

void Industrial::demitir(string nome) {
  if(nomeContratados.size() != 0) {
    for(int i = 0; i < nomeContratados.size(); i++) {
      if(*nomeContratados[i] == nome) {
        cout << "Trabalhador " << *nomeContratados[i] << " demitido com sucesso!\n";

        delete nomeContratados[i];
      }

      else {
        cout << "Demissão não realizada! Trabalhador não encontrado.\n";
      }
    }
  }

  else {
    cout << "Não há nenhum trabalhador contratado por esse empregador\n";
  }
}

ostream &operator<<(ostream &out, const Industrial &industrial) {
    out << "- INFORMAÇÕES SOBRE O EMPREGADOR INDUSTRIAL -\n";
    out << "Nome: " << industrial.getNomeCompleto() << "\n";
    out << "Sexo: " << industrial.getSexo() << "\n";
    out << "Idade: " << industrial.calculaIdade() << " anos\n";
    out << "Nacionalidade: " << industrial.nacionalidade << "\n";
    out << "Anos de contribuição: " << industrial.anosDeContribuicao << " anos\n";
    out << "Aposentado? " << industrial.aposentado << "\n";
}

bool Industrial::operator==(const Industrial &outroIndustrial) const {
  if(this->contato != outroIndustrial.contato) {
    return false;
  }

  if(this->nacionalidade != outroIndustrial.nacionalidade) {
    return false;
  }

  if(this->nomeContratados.size() != outroIndustrial.nomeContratados.size()) {
    for(int i = 0; i < nomeContratados.size(); i++) {
      if(this->nomeContratados[i] != outroIndustrial.nomeContratados[i]) {
        return false;
      }

      else {
        return true;
      }
    }

    return false;
  }

  if(this->numContratados != outroIndustrial.numContratados) {
    return false;
  }

  if(this->anosDeContribuicao != outroIndustrial.anosDeContribuicao) {
    return false;
  }

  if(this->aposentado != outroIndustrial.aposentado) {
    return false;
  }

  return true;
}

bool Industrial::operator!=(const Industrial &outroIndustrial) const {
  return !(*this == outroIndustrial);
}