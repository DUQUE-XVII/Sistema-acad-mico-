#ifndef _DISCIPLINA_H_
#define _DISCIPLINA_H_
#include "Departamento.h"
#include "Alunos.h"
#include "Laluno.h"
#include "ElDisciplina.h"

class Disciplina
{
    private:
        int id;
        char nome[150];
        char area_conhecimento[150];

        ElAluno *pElAlunoPrim;
        ElAluno *pElAlunoAtual;
        int max_alunos;
        int n_alunos;

        Departamento* pDeptoAssociado;


    public:
        Disciplina (int na = 45,char* ac = "" );
        ~Disciplina ( );



        void setId(int n);
        int getId();
        void setNomeDisc ( char* n );
        char* getNomeDisc ( );

        void setDepartamento ( Departamento* pdpto );
        Departamento* getDepartamento();

        void setAlunos(Aluno* pAluno);
        void Listealunos();
};
#endif

