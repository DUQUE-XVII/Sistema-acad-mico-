#ifndef _LALUNO_H_
#define _LALUNO_H_
#include "Alunos.h"



class ElAluno {
    private:
        Aluno* pAl;
    public:
        ElAluno ( );
        ~ElAluno ( );
        ElAluno *pProx;
        ElAluno *pAnte;
        void setAluno( Aluno* pa );
        Aluno* getAluno ( );
        char* getNome ( );
};
#endif

