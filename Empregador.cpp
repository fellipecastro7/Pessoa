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
        if(calculaIdade() < 35) {
            cout << "Não é possível se aposentar. Tempo de contribuição inferior a 35 anos\n";
            aposentado = false;
        }

        else {
            cout << "Aposentado! tempo de contribuição: " << calculaIdade() << " anos\n";
            aposentado = true;
        }
    }
}

void Empregador::setAposentado(bool aposentado1) {
    aposentado = aposentado1;
}

bool Empregador::getAposentado() const {
    return aposentado;
}

int Empregador::calculaAnosDeContribuicao() {
    if(calculaIdade() < 18) {
        anosDeContribuicao = 0;

        return 0;
    }

    anosDeContribuicao = calculaIdade() - 18;

    return anosDeContribuicao;
}