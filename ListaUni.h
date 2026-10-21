#ifndef _LISTAUNI_H
#define _LISTAUNI_H

#include "stdfx.h"
#include "Universidade.h"

class ListaUni{
    private:
        Universidade* uni;

    public:
        ListaUni();
        ~ListaUni();

        ListaUni* prox;
        ListaUni* ant;

        void setUniLista(Universidade* pUni);
        Universidade* getUniLoc();
};
#endif // _LISTAUNI_H
