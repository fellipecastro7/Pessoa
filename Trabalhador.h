#ifndef TRABALHADOR_H
#define	TRABALHADOR_H

#include "Pessoa.h"

class Trabalhador:public Pessoa {
    friend ostream &operator<<(ostream &, const Trabalhador &);

    public:
        Trabalhador();
        Trabalhador(const Pessoa &);
        Trabalhador(const Trabalhador &);
        ~Trabalhador();

        void setProfissao(string);
        string getProfissao() const;
        void setSalario(float);
        float getSalario() const;
        float getSalarioPorHora() const;
        int getHorasDeTrabalhoMensais() const;
        int getHorasDeTrabalhoSemanais() const;
        string getVinculoEmpregaticio() const;
        float calculaSalarioPorHora(float);
        int calculaHorasDeTrabalhoMensais(int);
        void perguntaVinculoEmpregaticio();

        bool operator==(const Trabalhador &) const;
        bool operator!=(const Trabalhador &) const;

    private:
        string profissao;
        float salario;
        float salarioPorHora;
        int horasDeTrabalhoMensais;
        int horasDeTrabalhoSemanais;
        string vinculoEmpregaticio;
};

#endif