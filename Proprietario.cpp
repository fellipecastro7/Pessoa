#include "Proprietario.h"

#include <iostream>

using std::cout;
using std::cin;

Proprietario::Proprietario()
:nacionalidade(""), numCasasAlugadas(0), numCasasPossuidas(0), anosDeContribuicao(0)
{

}

Proprietario::Proprietario(string nome, string sobrenome, string sexo, string nacionalidade1, int numCasasPossuidas1, const Data &dataOut)
:Trabalhador(nome, sobrenome, sexo, dataOut), nacionalidade(nacionalidade1), numCasasAlugadas(0), numCasasPossuidas(numCasasPossuidas1), anosDeContribuicao(0)
{

}

Proprietario::Proprietario(const Proprietario &outroProprietario)
:Trabalhador(outroProprietario), nacionalidade(outroProprietario.nacionalidade), numCasasAlugadas(outroProprietario.numCasasAlugadas), numCasasPossuidas(outroProprietario.numCasasPossuidas), anosDeContribuicao(outroProprietario.anosDeContribuicao)
{
  casasAlugadas.resize(outroProprietario.casasAlugadas.size());
  
	for(int i = 0; i < casasAlugadas.size(); i++) {
	  casasAlugadas[i] = new Casa(*outroProprietario.casasAlugadas[i]);
  }

  inquilinos.resize(outroProprietario.inquilinos.size());

  for(int i = 0; i < inquilinos.size(); i++) {
	  inquilinos[i] = new Inquilino(*outroProprietario.inquilinos[i]);
  }
}

Proprietario::~Proprietario() {
  for(int i = 0; i < casasAlugadas.size(); i++) {
		delete casasAlugadas[i];
  }

  for(int i = 0; i < inquilinos.size(); i++) {
		delete inquilinos[i];
  }
}

void Proprietario::printCasasAlugadas() const {
  cout << "- Casas alugadas e seus respectivos inquilinos-\n";

  if(casasAlugadas.size() != 0) {
    for(int i = 0; i < casasAlugadas.size(); i++) {
      cout << "Casa [" << i + 1 << "]\n";
      cout << "\t> Número de cômodos: " << casasAlugadas[i]->numComodos << "\n";
      cout << "\t> Tipo de casa: " << casasAlugadas[i]->tipo << "\n";
      cout << "\t> Comprimento: " << casasAlugadas[i]->comprimento << "m²\n";
      cout << "\t> Altura: " << casasAlugadas[i]->altura << "m²\n";
      cout << "\t> Área: " << casasAlugadas[i]->getArea() << "m²\n";
      cout << "Inquilino [" << i + 1 << "]\n";
      cout << "\t> Nome: " << inquilinos[i]->getNomeCompleto() << "\n";
      cout << "\t> Sexo: " << inquilinos[i]->getSexo() << "\n";
      cout << "\t> Aluguel: R$" << inquilinos[i]->getAluguel() << "\n";
      cout << "\t> Tempo: " << inquilinos[i]->getTempoDeAluguel() << " meses\n";
      cout << "\t> Aluguel final: R$" << inquilinos[i]->calculaAluguelFinal() << "\n";
    }
  }

  else {
    cout << "Não foi alugada nenhuma casa por este proprietário\n";
  }
}

void Proprietario::adicionaCasa(const Casa &casaOut) {
  if(casasAlugadas.size() < numCasasPossuidas) {
    casasAlugadas.push_back(new Casa(casaOut));

    numCasasAlugadas++;
  }

  else {
    cout << "Não é possível adicionar novas casas! Todas as casas possuídas pelo proprietário foram alugadas\n";
  }
}

void Proprietario::adicionaInquilino(const Inquilino &inquilinoOut) {
  if(inquilinos.size() < casasAlugadas.size()) {
    inquilinos.push_back(new Inquilino(inquilinoOut));
  }

  else {
    cout << "Não é possível adicionar novos inquilinos! Todas as casas possuídas pelo proprietário foram alugadas\n";
  }
}

void Proprietario::aposentar() {
  string opcao;

  cout << "\nDeseja se aposentar? [S/N] ";
  cin >> opcao;

  while(opcao != "S" && opcao != "s" && opcao != "N" && opcao != "n") {
    cout << "Deseja se aposentar? [S/N] ";
    cin >> opcao;
  }

  if(opcao == "n" || opcao == "N") {
    setAposentado(false);
  }

  if(opcao == "S" || opcao == "s") {
    if(calculaIdade() > 35) {
      if(calculaAnosDeContribuicao() < 35) {
        cout << "Não é possível se aposentar. Tempo de contribuição inferior a 35 anos\n";
        setAposentado(false);
      }

      else {
        cout << "Aposentado! tempo de contribuição: " << calculaAnosDeContribuicao() << " anos\n\n";
        setAposentado(true);
      }
    }

    else {
      cout << "Não é possível se aposentar. Tempo de contribuição inferior a 35 anos\n";
    }
  }
}

int Proprietario::calculaAnosDeContribuicao() {
  if(calculaIdade() < 18) {
    anosDeContribuicao = 0;

    return 0;
  }

  anosDeContribuicao = calculaIdade() - 18;

  return anosDeContribuicao;
}

double casa::getArea() const {
  return comprimento * altura;
}

ostream &operator<<(ostream &out, const Proprietario &proprietario) {
  out << "- INFORMAÇÕES SOBRE O PROPRIETÁRIO -\n";
  out << "Nome: " << proprietario.getNomeCompleto() << "\n";
  out << "Sexo: " << proprietario.getSexo() << "\n";
  out << "Idade: " << proprietario.calculaIdade() << " anos\n";
  out << "Possui vínculo empregatício? " << proprietario.getVinculoEmpregaticio() << "\n";
  out << "Profissão: " << proprietario.getProfissao() << "\n";
    
  if(proprietario.getVinculoEmpregaticio() == "Não") {
    out << "Salário: R$" << proprietario.getSalario() << "\n";
  }

  else {
    out << "Horas de trabalho mensais: " << proprietario.getHorasDeTrabalhoMensais() << " horas\n";
    out << "Horas de trabalho semanais: " << proprietario.getHorasDeTrabalhoSemanais() << " horas\n";
    out << "Salário: R$" << proprietario.getSalario() << "\n";
    out << "Salário por hora: R$" << proprietario.getSalarioPorHora() << "\n";
  }

  out << "Nacionalidade: " << proprietario.nacionalidade << "\n";
  out << "Anos de contribuição: " << proprietario.anosDeContribuicao << " anos\n";
  out << "Aposentado? " << (proprietario.getAposentado() ? "Sim" : "Não") << "\n";
  out << "Quantidade de casas em sua posse: " << proprietario.numCasasPossuidas << "\n";
  out << "Quantidade de casas alugadas: " << proprietario.numCasasAlugadas << "\n";
}

bool Proprietario::operator==(const Proprietario &outroProprietario) const {
  if(this->numCasasPossuidas != outroProprietario.numCasasPossuidas) {
    return false;
  }

  if(this->nacionalidade != outroProprietario.nacionalidade) {
    return false;
  }

  if(this-> casasAlugadas.size() != outroProprietario.casasAlugadas.size()) {
    return false;
  }

  if(this->numCasasAlugadas != outroProprietario.numCasasAlugadas) {
    return false;
  }

  if(this->anosDeContribuicao != outroProprietario.anosDeContribuicao) {
    return false;
  }

  return true;
}

bool Proprietario::operator!=(const Proprietario &outroProprietario) const {
  return !(*this == outroProprietario);
}

Proprietario& Proprietario::operator=(const Proprietario &outroProprietario) {
  *static_cast <Proprietario *> (this) = static_cast <Proprietario> (outroProprietario);

  return *this;
}

Proprietario& Proprietario::operator!() {
    this->numCasasPossuidas -= 1;

    return *this;
}