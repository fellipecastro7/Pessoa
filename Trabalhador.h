#ifndef TRABALHADOR_H
#define	TRABALHADOR_H

#include "Pessoa.h"

class Trabalhador:public Pessoa {
    public:
        Trabalhador();
        Trabalhador(string, string, string, const Data & = Data(5, 7, 2015));
        Trabalhador(const Trabalhador &);
        ~Trabalhador();

        void setProfissao(string);
        void setSalario(float);
        void setAposentado(bool);
        string getProfissao() const;
        float getSalario() const;
        float getSalarioPorHora() const;
        int getHorasDeTrabalhoMensais() const;
        int getHorasDeTrabalhoSemanais() const;
        string getVinculoEmpregaticio() const;
        int getAnosDeContribuicao() const;
        bool getAposentado() const;
        float calculaSalarioPorHora(float);
        int calculaHorasDeTrabalhoMensais(int);
        void perguntaVinculoEmpregaticio();
        void aposentar();
        int calculaAnosDeContribuicao();

    private:
        string profissao;
        float salario;
        float salarioPorHora;
        int horasDeTrabalhoMensais;
        int horasDeTrabalhoSemanais;
        string vinculoEmpregaticio;
        int anosDeContribuicao;
        bool aposentado;
};

#endif