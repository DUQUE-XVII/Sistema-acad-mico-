#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "stdfx.h"
#include "ElDisciplina.h"

class Disciplina;
class Universidade;

class Departamento{
    private:
        char nomeDepat[40];
        char UniDepat[40];

        ElDisciplina *Discprim;
        ElDisciplina *Discatual;

    public:
        Departamento(char n[]= "");
        ~Departamento();

        void setNome( char n[]);
        char* getNome();

        void setNomeUni(char n[]);
        char* getNomeUni();

        void incluaDisciplina ( Disciplina* pd );
        void listeDisciplinas ( );


};

#endif // _DEPARTAMENTO_H
