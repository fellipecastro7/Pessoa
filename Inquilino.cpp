#include "Inquilino.h"

#include <iostream>

using std::cout;
using std::cin;

Inquilino::Inquilino() 
:aluguel(0), tempo(0), anosDeContribuicao(anosDeContribuicao), aposentado(false)
{

}

Inquilino::Inquilino(string nome, string sobrenome, string sexo, float aluguel1, int tempo1, const Data &dataOut)
:Trabalhador(nome, sobrenome, sexo), aluguel(aluguel1), tempo(tempo1), anosDeContribuicao(0), aposentado(false)
{

}

Inquilino::Inquilino(const Inquilino &outroInquilino)
:Trabalhador(outroInquilino), aluguel(outroInquilino.aluguel), tempo(outroInquilino.tempo), anosDeContribuicao(outroInquilino.anosDeContribuicao), aposentado(outroInquilino.aposentado)
{

}

Inquilino::~Inquilino()
{

}

float Inquilino::getAluguel() const {
  return aluguel;
}

int Inquilino::getTempo() const {
  return tempo;
}

int Inquilino::calculaAluguelFinal() const {
    return (aluguel * tempo);
}

void Inquilino::aposentar() {
    string opcao;

    cout << "Deseja se aposentar? [S/N] ";
    cin >> opcao;

    while(opcao != "S" && opcao != "s" && opcao != "N" && opcao != "n") {
        cout << "Deseja se aposentar? [S/N] ";
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

int Inquilino::calculaTempoDeTrabalho() {
    return anosDeContribuicao;
}

ostream &operator<<(ostream &out, const Inquilino &inquilino) {
    out << "\n- INFORMAÇÕES SOBRE O INQUILINO -\n";
    out << "Nome: " << inquilino.getNomeCompleto() << "\n";
    out << "Sexo: " << inquilino.getSexo() << "\n";
    out << "Data de nascimento: ";
    inquilino.getDataNascimento();
    out << "Idade: " << inquilino.calculaIdade() << "\n";
    out << "Possui vínculo empregatício? " << inquilino.getVinculoEmpregaticio() << "\n";
    out << "Profissão: " << inquilino.getProfissao() << "\n";
    
    if(inquilino.getVinculoEmpregaticio() == "Não") {
        out << "Salário: R$" << inquilino.getSalario() << "\n";
    }

    else {
        out << "Horas de trabalho mensais: " << inquilino.getHorasDeTrabalhoMensais() << " horas\n";
        out << "Horas de trabalho semanais: " << inquilino.getHorasDeTrabalhoSemanais() << " horas\n";
        out << "Salário: R$" << inquilino.getSalario() << "\n";
        out << "Salário por hora: R$" << inquilino.getSalarioPorHora() << "\n";
    }

    out << "Aluguel: R$" << inquilino.aluguel << "\n";
    out << "Tempo de aluguel: " << inquilino.tempo << " meses\n";
    out << "Aluguel final: " <<inquilino.calculaAluguelFinal() << "\n";

    return out;
}

bool Inquilino::operator==(const Inquilino &outroInquilino) const {
  if(this->aluguel != outroInquilino.aluguel) {
    return false;
  }

  if(this->tempo != outroInquilino.tempo) {
    return false;
  }

  if(this->calculaAluguelFinal() != outroInquilino.calculaAluguelFinal()) {
    return false;
  }

  if(this->anosDeContribuicao != outroInquilino.anosDeContribuicao) {
    return false;
  }

  if(this->aposentado != outroInquilino.aposentado) {
    return false;
  }

  return true;
}

bool Inquilino::operator!=(const Inquilino &outroInquilino) const {
  return !(*this == outroInquilino);
}