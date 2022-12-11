#include "Empregador.h"
#include "Trabalhador.h"

#include <iostream>

using std::cout;

Empregador::Empregador()
:areaDeAtuacao(""), contato(""), numContratados(0)
{

}

Empregador::Empregador(string areaDeAtuacao1, string contato1, const Pessoa &pessoaOut)
:Pessoa(pessoaOut), areaDeAtuacao(areaDeAtuacao1), contato(contato1), numContratados(0)
{

}

Empregador::Empregador(const Empregador &outroEmpregador)
:Pessoa(outroEmpregador), areaDeAtuacao(outroEmpregador.areaDeAtuacao), contato(outroEmpregador.contato), numContratados(outroEmpregador.numContratados)
{
    contratados.resize(outroEmpregador.contratados.size());
  
	for(int i = 0; i < contratados.size(); i++) {
	  contratados[i] = new Trabalhador(*outroEmpregador.contratados[i]);
  }
}

Empregador::~Empregador()
{
    for(int i = 0; i < contratados.size(); i++) {
		delete contratados[i];
    }
}

void Empregador::contrataTrabalhador(const Trabalhador &pessoa) {
    contratados.push_back(new Trabalhador(pessoa));
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

ostream &operator<<(ostream &out, const Empregador &empregador) {
    out << "\n- INFORMAÇÕES SOBRE O EMPREGADOR -\n";
    out << static_cast <Pessoa> (empregador) << "\n";
    out << "Área de atuação: " << empregador.areaDeAtuacao << "\n";
    out << "Contato: " << empregador.contato << "\n";
    out << "Número de contratados: " << empregador.numContratados << "\n";
    
    empregador.printContratados();
}