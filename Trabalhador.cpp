#include "Trabalhador.h"

#include <iostream>

using std::cout;
using std::cin;

Trabalhador::Trabalhador()
:profissao(""), salario(0), salarioPorHora(0), horasDeTrabalhoMensais(0), horasDeTrabalhoSemanais(0), vinculoEmpregaticio("")
{

}

Trabalhador::Trabalhador(const Pessoa &pessoaOut)
:Pessoa(pessoaOut), profissao(""), salario(0), salarioPorHora(0), horasDeTrabalhoMensais(0), horasDeTrabalhoSemanais(0), vinculoEmpregaticio("")
{

}

Trabalhador::Trabalhador(const Trabalhador &outroTrabalhador)
:Pessoa(outroTrabalhador), profissao(outroTrabalhador.profissao), salario(outroTrabalhador.salario), salarioPorHora(outroTrabalhador.salarioPorHora), horasDeTrabalhoMensais(outroTrabalhador.horasDeTrabalhoMensais), horasDeTrabalhoSemanais(outroTrabalhador.horasDeTrabalhoSemanais), vinculoEmpregaticio(outroTrabalhador.vinculoEmpregaticio)
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

    cout << "\nO trabalhador possui vinculo empregatício?[S/N] ";
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

void Trabalhador::setProfissao(string profissao1) {
    if(profissao1.length() <= 0) {
        return;
    }

    profissao = profissao1;
}

string Trabalhador::getProfissao() const {
    return profissao;
}

void Trabalhador::setSalario(float salario1) {
    if(salario1 <= 0) {
        return;
    }

    salario = salario1;
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

ostream &operator<<(ostream &out, const Trabalhador &trabalhador) {
    out << "\n- INFORMAÇÕES SOBRE O TRABALHADOR -\n";
    out << static_cast <Pessoa> (trabalhador) << "\n";
    out << "Possui vínculo empregatício? " << trabalhador.vinculoEmpregaticio << "\n";
    out << "Profissão: " << trabalhador.profissao << "\n";
    
    if(trabalhador.vinculoEmpregaticio == "Não") {
        out << "Salário: R$" << trabalhador.salario << "\n";
    }

    else {
        out << "Horas de trabalho mensais: " << trabalhador.horasDeTrabalhoMensais << " horas\n";
        out << "Horas de trabalho semanais: " << trabalhador.horasDeTrabalhoSemanais << " horas\n";
        out << "Salário: R$" << trabalhador.salario << "\n";
        out << "Salário por hora: R$" << trabalhador.salarioPorHora << "\n";
    }
}

bool Trabalhador::operator==(const Trabalhador &outroTrabalhador) const {
  if(this->getProfissao() != outroTrabalhador.getProfissao()) {
    return false;
  }

  if(this->getSalario() != outroTrabalhador.getSalario()) {
    return false;
  }

  if(this->getVinculoEmpregaticio() != outroTrabalhador.getVinculoEmpregaticio()) {
    return false;
  }

  if(this->horasDeTrabalhoMensais != outroTrabalhador.horasDeTrabalhoMensais) {
    return false;
  }

  if(this->horasDeTrabalhoSemanais!= outroTrabalhador.horasDeTrabalhoSemanais) {
    return false;
  }

  if(this->salarioPorHora != outroTrabalhador.salarioPorHora) {
    return false;
  }

  return true;
}

bool Trabalhador::operator!=(const Trabalhador &outroTrabalhador) const {
  return !(*this == outroTrabalhador);
}