#include "Inquilino.h"

#include <iostream>

using std::cout;
using std::cin;

Inquilino::Inquilino() 
:aluguel(0), tempoDeAluguel(0), anosDeContribuicao(anosDeContribuicao)
{

}

Inquilino::Inquilino(string nome, string sobrenome, string sexo, float aluguel1, int tempoDeAluguel1, const Data &dataOut)
:Trabalhador(nome, sobrenome, sexo), aluguel(aluguel1), tempoDeAluguel(tempoDeAluguel1), anosDeContribuicao(0)
{

}

Inquilino::Inquilino(const Inquilino &outroInquilino)
:Trabalhador(outroInquilino), aluguel(outroInquilino.aluguel), tempoDeAluguel(outroInquilino.tempoDeAluguel), anosDeContribuicao(outroInquilino.anosDeContribuicao)
{

}

Inquilino::~Inquilino()
{

}

float Inquilino::getAluguel() const {
  return aluguel;
}

int Inquilino::getTempoDeAluguel() const {
  return tempoDeAluguel;
}

float Inquilino::calculaAluguelFinal() const {
    return (aluguel * tempoDeAluguel);
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
    setAposentado(false);
  }

  if(opcao == "S" || opcao == "s") {
    if(calculaAnosDeContribuicao() < 35) {
      cout << "Não é possível se aposentar. Tempo de contribuição inferior a 35 anos\n";
      setAposentado(false);
    }

    else {
      cout << "Aposentado! tempo de contribuição: " << calculaAnosDeContribuicao() << " anos\n";
      setAposentado(true);
    }
  }
}

int Inquilino::calculaAnosDeContribuicao() {
  if(calculaIdade() < 18) {
    anosDeContribuicao = 0;

    return 0;
  }

  anosDeContribuicao = calculaIdade() - 18;

  return anosDeContribuicao;
}

ostream &operator<<(ostream &out, const Inquilino &inquilino) {
  out << "\n- INFORMAÇÕES SOBRE O INQUILINO -\n";
  out << "Nome: " << inquilino.getNomeCompleto() << "\n";
  out << "Sexo: " << inquilino.getSexo() << "\n";
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
  out << "Tempo de aluguel: " << inquilino.tempoDeAluguel << " meses\n";
  out << "Aluguel final: R$" <<inquilino.calculaAluguelFinal() << "\n";

  return out;
}

bool Inquilino::operator==(const Inquilino &outroInquilino) const {
  if(this->aluguel != outroInquilino.aluguel) {
    return false;
  }

  if(this->tempoDeAluguel != outroInquilino.tempoDeAluguel) {
    return false;
  }

  if(this->calculaAluguelFinal() != outroInquilino.calculaAluguelFinal()) {
    return false;
  }

  if(this->anosDeContribuicao != outroInquilino.anosDeContribuicao) {
    return false;
  }

  return true;
}

bool Inquilino::operator!=(const Inquilino &outroInquilino) const {
  return !(*this == outroInquilino);
}

Inquilino& Inquilino::operator=(const Inquilino &outroInquilino) {
  *static_cast <Inquilino *> (this) = static_cast <Inquilino> (outroInquilino);

  return *this;
}

Inquilino& Inquilino::operator!() {
    this->tempoDeAluguel -= 1;

    return *this;
}