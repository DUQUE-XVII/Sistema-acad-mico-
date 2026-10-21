#ifndef _ELUNI_H
#define _ELUNI_H

#include "stdfx.h"
#include "ListaUni.h"
#include "Universidade.h"

class Eluni{
    private:

    public:
        ListaUni* UniPrim;
        ListaUni* UniAtual;

        Eluni();
        ~Eluni();
        void inclueUni(Universidade* pUni);
        void ListUni ();
        Universidade* localizaUni(char* nome = "");

};
#endif // _ELUNI_H
