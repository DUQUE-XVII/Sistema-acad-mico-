#ifndef _ELDEPAT_H
#define _ELDEPAT_H

#include "Departamento.h"
#include "stdfx.h"

class Eldepat{
    private:
        Departamento* pelDepto;
    public:
        Eldepat();
        ~Eldepat();

        void setDepat(Departamento* Dpto);
        void setNomeUni(char* n);
        Departamento* getDepat();


        Eldepat* Dprox;
        Eldepat* Dant;

        char* getNomeDepat();

};
#endif // _ELDEPAT_H
