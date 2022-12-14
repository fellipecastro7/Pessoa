#include "Rural.h"

#include <iostream>

using std::cout;
using std::cin;

const string Rural::AREADEATUACAO = "Agroeconomia";

Rural::Rural()
:anosDeContribuicao(0)/*, aposentado(false)*/, contato(""), nacionalidade(""), numContratados(0), vagas(0)
{

}

Rural::Rural(string nome, string sobrenome, string sexo, string nacionalidade, string contato, const Data &dataOut)
:Empregador(nome, sobrenome, sexo, dataOut), nacionalidade(nacionalidade)/*, aposentado(false)*/, contato(contato), anosDeContribuicao(0), numContratados(0), vagas(0)
{

}

Rural::Rural(const Rural &outroRural)
:Empregador(outroRural), contato(outroRural.contato), nacionalidade(outroRural.nacionalidade)/*, aposentado(outroRural.aposentado)*/, anosDeContribuicao(outroRural.anosDeContribuicao), numContratados(outroRural.numContratados), vagas(outroRural.vagas)
{

}

Rural::~Rural()
{
  for(int i = 0; i < contratados.size(); i++) {
		delete contratados[i];
  }
}

int Rural::calculaAnosDeContribuicao() {
    if(calculaIdade() < 18) {
        anosDeContribuicao = 0;

        return 0;
    }

    anosDeContribuicao = calculaIdade() - 18;

    return anosDeContribuicao;
}

void Rural::printContratados() const {
  cout << "- Nome dos contratados -\n";

  if(contratados.size() != 0) {
    for(int i = 0; i < contratados.size(); i++) {
      cout << "- " << *contratados[i] << "\n";
    }
  }

  else {
    cout << "Não há nenhum trabalhador contratado por esse empregador\n";
  }
}

void Rural::aposentar() {
    string opcao;

    cout << "Empregador -> Deseja se aposentar? [S/N] ";
    cin >> opcao;

    while(opcao != "S" && opcao != "s" && opcao != "N" && opcao != "n") {
        cout << "Empregador -> Deseja se aposentar? [S/N] ";
        cin >> opcao;
    }

    if(opcao == "n" || opcao == "N") {
        setAposentado(false);
    }

    if(opcao == "S" || opcao == "s") {
        if(calculaAnosDeContribuicao() < 15) {
            cout << "Não é possível se aposentar. Tempo de contribuição inferior a 15 anos\n";
            setAposentado(false);
        }

        else {
            cout << "Aposentado! tempo de contribuição: " << calculaAnosDeContribuicao() << " anos\n";
            setAposentado(true);
        }
    }
}

void Rural::contratar(string nome) {
  contratados.push_back(new string(nome));
  numContratados++;
}

void Rural::demitir(string nome) {
  if(contratados.size() != 0) {
    for(int i = 0; i < contratados.size(); i++) {
      if(*contratados[i] == nome) {
        cout << "Trabalhador " << *contratados[i] << " demitido com sucesso!\n";

        delete contratados[i];
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

ostream &operator<<(ostream &out, const Rural &rural) {
    out << "- INFORMAÇÕES SOBRE O EMPREGADOR RURAL -\n";
    out << "Nome: " << rural.getNomeCompleto() << "\n";
    out << "Sexo: " << rural.getSexo() << "\n";
    out << "Idade: " << rural.calculaIdade() << " anos\n";
    out << "Nacionalidade: " << rural.nacionalidade << "\n";
    out << "Anos de contribuição: " << rural.anosDeContribuicao << " anos\n";
    out << "Aposentado? " << (rural.getAposentado() ? "Sim" : "Não") << "\n";
}

bool Rural::operator==(const Rural &outroRural) const {
  if(this->contato != outroRural.contato) {
    return false;
  }

  if(this->nacionalidade != outroRural.nacionalidade) {
    return false;
  }

  if(this->numContratados != outroRural.numContratados) {
    return false;
  }

  if(this->anosDeContribuicao != outroRural.anosDeContribuicao) {
    return false;
  }

  if(this->vagas != outroRural.vagas) {
    return false;
  }

  return true;
}

bool Rural::operator!=(const Rural &outroRural) const {
  return !(*this == outroRural);
}