#include"stdfx.h"
#ifndef _PESSOA_H_
#define _PESSOA_H_
#include "Universidade.h"
#include "Departamento.h"
class Pessoa
{
    private:
        int idadeP;
        int diaP;
        int mesP;
        int anoP;
        char nomeP[300];
    protected:
        Universidade *UniFiliado;
        Departamento *Depatfiliado;
    public:
        Pessoa(int diaNa, int mesNa, int anoNa=0, const char nome[] = "");
        Pessoa();

        void inicializa(int diaNa, int mesNa, int anoNa, const char* nome = "");
        void CalcIdade(int diaAt, int mesAt, int anoAt);
        char* getNome();

        int getIdade();
        void setUnifiliado(Universidade* pu);
        char* OndeEstuda();


};
#endif // _PESSOA_H_
