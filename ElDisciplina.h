#ifndef _ELDISCIPLINA_H
#define _ELDISCIPLINA_H

#include "stdfx.h"


class Disciplina;

class ElDisciplina{
    private:
        Disciplina* pDisc;


    public:



        ElDisciplina();
        ~ElDisciplina();
        void setDisc(Disciplina* disc);

        ElDisciplina* prox;
        ElDisciplina* ant;

        Disciplina* getDisciplina();
        char* getNomeDisc();

};
#endif // _ELDISCIPLINA_H
