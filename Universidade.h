#ifndef _UNIVERSIDADE_H
#define _UNIVERSIDADE_H

#include "stdfx.h"
#include "Departamento.h"
#include "ElDepat.h"

class ListaUni;

class Universidade{
    private:
        char nome[80];

    public:
        Universidade(char n[] = "");
        ~Universidade();

        Eldepat* DepatPrim;
        Eldepat* DepatAtual;

        void setDepat(Departamento* n);
        void setNome(char* n);

        char* getNome();

        void imprimeDpto();
        Departamento*localizaDepat(char* nome);

};
#endif // _UNIVERSIDADE_H
