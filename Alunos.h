#ifndef _ALUNOS_H
#define _ALUNOS_H

#include    "Pessoa.h"
#include    "stdfx.h"
#include    "Universidade.h"

class ElDisciplina;

class Aluno: public Pessoa{
    private:
        int RA;
        Universidade* UniFiliado;
        char Uni[80];
    public:
        Aluno( int diaNa =0, int mesNa =0, int anoNa =0, char* nome = "");
        ~Aluno();

        Aluno* prox;
        Aluno* ant;

        void setRA(int i);
        int getRA();
        char* getUnifiliado();
        void setUniNome(char* nome);

};

#endif // _ALUNOS_H
