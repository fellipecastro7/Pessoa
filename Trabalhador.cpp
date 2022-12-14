#include "Trabalhador.h"

#include <iostream>

using std::cout;
using std::cin;

Trabalhador::Trabalhador()
:profissao(""), salario(0), salarioPorHora(0), horasDeTrabalhoMensais(0), horasDeTrabalhoSemanais(0), vinculoEmpregaticio(""), anosDeContribuicao(0), aposentado(false)
{

}

Trabalhador::Trabalhador(string nome, string sobrenome, string sexo, const Data &dataOut)
:Pessoa(nome, sobrenome, sexo, dataOut), profissao(""), salario(0), salarioPorHora(0), horasDeTrabalhoMensais(0), horasDeTrabalhoSemanais(0), vinculoEmpregaticio(""), anosDeContribuicao(0), aposentado(false)
{

}

Trabalhador::Trabalhador(const Trabalhador &outroTrabalhador)
:Pessoa(outroTrabalhador), profissao(outroTrabalhador.profissao), salario(outroTrabalhador.salario), salarioPorHora(outroTrabalhador.salarioPorHora), horasDeTrabalhoMensais(outroTrabalhador.horasDeTrabalhoMensais), horasDeTrabalhoSemanais(outroTrabalhador.horasDeTrabalhoSemanais), vinculoEmpregaticio(outroTrabalhador.vinculoEmpregaticio), anosDeContribuicao(outroTrabalhador.anosDeContribuicao), aposentado(outroTrabalhador.aposentado)
{

}

Trabalhador::~Trabalhador()
{

}

int Trabalhador::calculaHorasDeTrabalhoMensais(int horasDeTrabalhoSemanais1) {
    if(horasDeTrabalhoSemanais1 <= 0) {
        return 0;
    }

    horasDeTrabalhoSemanais = horasDeTrabalhoSemanais1;

    horasDeTrabalhoMensais = horasDeTrabalhoSemanais * 5; //5 = semanas por mês

    return horasDeTrabalhoMensais;
}

float Trabalhador::calculaSalarioPorHora(float salario1) {
    if(salario1 <= 0) {
        return 0;
    }

    salario = salario1;

    salarioPorHora = salario / horasDeTrabalhoMensais;

    return salarioPorHora;
}

void Trabalhador::perguntaVinculoEmpregaticio() {
    string opcao;

    cout << "- Cadastro de trabalhador -\n";
    cout << "O trabalhador possui vinculo empregatício?[S/N] ";
    cin >> opcao;

    while(opcao != "S" && opcao != "s" && opcao != "N" && opcao != "n") {
        cout << "\nO trabalhador possui vinculo empregatício?[S/N] ";
        cin >> opcao;
    }

    if(opcao == "n" || opcao == "N") {
        vinculoEmpregaticio = "Não";
    }

    if(opcao == "S" || opcao == "s") {
        vinculoEmpregaticio = "Sim";
    }

    cout << "\n";
}

void Trabalhador::aposentar() {
    string opcao;

    cout << "Trabalhador -> Deseja se aposentar? [S/N] ";
    cin >> opcao;

    while(opcao != "S" && opcao != "s" && opcao != "N" && opcao != "n") {
        cout << "Trabalhador -> Deseja se aposentar? [S/N] ";
        cin >> opcao;
    }

    if(opcao == "n" || opcao == "N") {
        aposentado = false;
    }

    if(opcao == "S" || opcao == "s") {
        if(calculaAnosDeContribuicao() < 35) {
            cout << "Não é possível se aposentar. Tempo de contribuição inferior a 35 anos\n";
            aposentado = false;
        }

        else {
            cout << "Aposentado! tempo de contribuição: " << calculaAnosDeContribuicao() << " anos\n";
            aposentado = true;
        }
    }
}

int Trabalhador::calculaAnosDeContribuicao() {
    if(calculaIdade() < 18) {
        anosDeContribuicao = 0;

        return 0;
    }

    anosDeContribuicao = calculaIdade() - 18;

    return anosDeContribuicao;
}

void Trabalhador::setAposentado(bool aposentado1) {
    aposentado = aposentado1;
}

void Trabalhador::setSalario(float salario1) {
    if(salario1 <= 0) {
        return;
    }

    salario = salario1;
}

void Trabalhador::setProfissao(string profissao1) {
    if(profissao1.length() <= 0) {
        return;
    }

    profissao = profissao1;
}

string Trabalhador::getProfissao() const {
    return profissao;
}

float Trabalhador::getSalario() const {
    return salario;
}

float Trabalhador::getSalarioPorHora() const {
    return salarioPorHora;
}

int Trabalhador::getHorasDeTrabalhoMensais() const  {
    return horasDeTrabalhoMensais;
}

int Trabalhador::getHorasDeTrabalhoSemanais() const  {
    return horasDeTrabalhoSemanais;
}

string Trabalhador::getVinculoEmpregaticio() const {
    return vinculoEmpregaticio;
}

int Trabalhador::getAnosDeContribuicao() const {
    return anosDeContribuicao;
}

bool Trabalhador::getAposentado() const {
    return aposentado;
}