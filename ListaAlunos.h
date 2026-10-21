#ifndef _LISTAALUN_H
#define _LISTAALUN_H

#include    "Laluno.h"
#include    "Alunos.h"
#include    "stdfx.h"

class listalun{
    private:

    public:
        ElAluno* ALUNOPRIM;
        ElAluno* ALUNOATUAL;

        listalun();
        ~listalun();


        void inclueAlunos(Aluno* pAlu);
        void GravaAlunos();
        void RecuperaAlunos();
        void ListaAlunos();

};
#endif // _ELALUNO_H
