#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include    "Pessoa.h"
#include    "Universidade.h"
#include    "Departamento.h"
#include    "Professor.h"
#include    "Disciplinas.h"
#include    "Alunos.h"
#include    "ElUni.h"
#include    "ListaAlunos.h"

class Principal{
    private:
        Aluno Joao;
        Professor Simao;

        int diaAtual;
        int mesAtual;
        int anoAtual;

        Universidade UTFPR;
        Departamento DAINF,MODA,DAMAT;

        Disciplina tecProg_2026,calculo;
        Eluni LUniversidades;
        listalun LAlunos;


    public:
        Principal();
        ~Principal();

        void inicializaUNi();
        void inicializaProf();
        void inicializaAluno();
        void inicializaDpto();
        void inicializaDisc();

        void executar();

        void incluiAlunos();
        void incluiDpto();
        void incluiDisc();
        void incluiProf();

        void calCulidadep();
        void DptoTrabalha();
        void Listdpto();
        void ListAlunos();
        void ListaUniver();

        void menu();
        void menuCad();
        void menuGravar();
        void menuRecuperar();

        void cadUniversidade();
        void cadDepartamento();
        void cadDisciplina();
        void cadAluno();
        void cadProfessor();

        void Gravar();


};
#endif
