#ifndef _PROFESSOR_H
#define _PROFESSOR_H

#include "stdfx.h"
#include "Pessoa.h"
#include "Universidade.h"
class Professor : public Pessoa
    {
    private:
        Universidade* pUnivFiliado;
        Departamento* pDptoFiliado;
    public:
        Professor ( int diaNa, int mesNa, int anoNa, char* nome= "" );
        Professor ( );
        ~Professor ( );
        void setUnivFiliado ( Universidade* pu );
        void setDepartamento ( Departamento* pdpto);
        void OndeTrabalho ( );
        void QualDepartamentoTrabalho ( );
};

#endif // _PROFESSOR_H
