#include "Proprietario.h"

#include <iostream>

using std::cout;


Proprietario::Proprietario()
:nacionalidade(""), numCasasAlugadas(0), ultimaCasaAlugada()
{

}

Proprietario::Proprietario(string nacionalidade, const Trabalhador &trabalhadorOut)
:Trabalhador(trabalhadorOut), nacionalidade(nacionalidade), numCasasAlugadas(0)
{

}

Proprietario::Proprietario(const Proprietario &outroProprietario)
:nacionalidade(outroProprietario.nacionalidade), numCasasAlugadas(outroProprietario.numCasasAlugadas)
{
  casasAlugadas.resize(outroProprietario.casasAlugadas.size());
  
	for(int i = 0; i < casasAlugadas.size(); i++) {
	  casasAlugadas[i] = new Casa(*outroProprietario.casasAlugadas[i]);
  }

  inquilinosCasas.resize(outroProprietario.inquilinosCasas.size());

  for(int i = 0; i < inquilinosCasas.size(); i++) {
	  inquilinosCasas[i] = new string(*outroProprietario.inquilinosCasas[i]);
  }
}

Proprietario::~Proprietario() {
  for(int i = 0; i < casasAlugadas.size(); i++) {
		delete casasAlugadas[i];
  }

  for(int i = 0; i < inquilinosCasas.size(); i++) {
		delete inquilinosCasas[i];
  }
}

void Proprietario::printCasasAlugadas() const {
  cout << "\n- Casas Alugadas -\n";
  for(int i = 0; i < casasAlugadas.size(); i++) {
    cout << "Casa [" << i + 1 << "]\n";
    cout << "Número de cômodos: " << casasAlugadas[i]->numComodos << "\n";
    cout << "Tipo de casa: " << casasAlugadas[i]->tipo << "\n";
    cout << "Comprimento: " << casasAlugadas[i]->comprimento << "m²\n";
    cout << "Altura: " << casasAlugadas[i]->altura << "m²\n";
    //cout << casasAlugadas[i]->calculaArea() << "\n";
  }
}

/*double Proprietario::calculaArea() {
    return comprimento * altura;
}*/

void Proprietario::adicionaCasa(const Casa &casaOut) {
  casasAlugadas.push_back(new Casa(casaOut));

  numCasasAlugadas++;
}

ostream &operator<<(ostream &out, const Proprietario &proprietario) {
    out << "Informações sobre o proprietário:\n";
    out << "Nacionalidade: " << proprietario.nacionalidade << "\n";
    out << "Quantidade de casas alugadas: " << proprietario.numCasasAlugadas << "\n";

    proprietario.printCasasAlugadas();
}

bool Proprietario::operator==(const Proprietario &outroProprietario) const {
  if(this-> casasAlugadas.size() != outroProprietario.casasAlugadas.size()) {
    return false;
  }

  return true;
}

bool Proprietario::operator!=(const Proprietario &outroProprietario) const {
  return !(*this == outroProprietario);
}