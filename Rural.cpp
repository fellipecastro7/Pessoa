#include "Rural.h"

#include <iostream>

using std::cout;

Rural::Rural()
:anosDeContribuicao(0), aposentado(false), areaDeAtuacao(""), contato("")
{

}

Rural::Rural(string nome, string sobrenome, string sexo, string nacionalidade, const Data &dataOut)
:Empregador(nome, sobrenome, sexo, dataOut), nacionalidade(nacionalidade), aposentado(false), areaDeAtuacao(""), contato("")
{

}

Rural::Rural(const Rural &outroRural)
:Empregador(outroRural), areaDeAtuacao(outroRural.areaDeAtuacao), contato(outroRural.contato), nacionalidade(outroRural.nacionalidade)
{

}

Rural::~Rural()
{
    for(int i = 0; i < nomeContratados.size(); i++) {
		  delete nomeContratados[i];
    }
}

void Rural::printContratados() const {
    cout << "- Nome dos contratados -\n";
}

void Rural::contratar(string nome) {
    nomeContratados.push_back(new string(nome));
    numContratados++;
}

void Rural::demitir(string nome) {
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

ostream &operator<<(ostream &out, const Rural &rural) {
    out << "\n- INFORMAÇÕES SOBRE O EMPREGADOR RURAL -\n";
    out << "Nome: " << rural.getNomeCompleto() << "\n";
    out << "Sexo: " << rural.getSexo() << "\n";
    //out << "Data de nascimento: ";
    //rural.getDataNascimento();
    out << "\nIdade: " << rural.calculaIdade() << "\n";
    out << "Nacionalidade: " << rural.nacionalidade << "\n";
    out << "Anos de contribuição: " << rural.anosDeContribuicao << "\n";
    out << "Aposentado? " << rural.aposentado << "\n";
    out << "Quantidade de contratados: " << rural.numContratados << "\n";

    rural.printCasasAlugadas();
    //proprietario.printInquilinos();
}

bool Rural::operator==(const Rural &outroRural) const {
  if(this->areaDeAtuacao != outroRural.areaDeAtuacao) {
    return false;
  }

  if(this->contato != outroRural.contato) {
    return false;
  }

  if(this->nacionalidade != outroRural.nacionalidade) {
    return false;
  }

  if(this->nomeContratados.size() != outroRural.nomeContratados.size()) {
    return false;
  }

  if(this->numContratados != outroRural.numContratados) {
    return false;
  }

  return true;
}

bool Rural::operator!=(const Rural &outroProprietario) const {
  return !(*this == outroProprietario);
}