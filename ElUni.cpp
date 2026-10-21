#include "ElUni.h"

Eluni::Eluni(){
    UniAtual = NULL;
    UniPrim = NULL;
}

Eluni::~Eluni(){
    ListaUni* paux1, *paux2;
    paux1 = UniPrim;
    while(paux1!=NULL){
        paux2 = paux1->prox;
        delete(paux1);
        paux1 = paux2;
    }
}

void Eluni::inclueUni(Universidade* pUni){
    if(pUni == NULL)
        return;
    ListaUni* paux = new ListaUni();
    paux->setUniLista(pUni);
    if(UniPrim == NULL){
        UniPrim = paux;
        UniAtual = paux;
    }
    else{
        UniAtual->prox = paux;
        paux->ant = UniAtual;
        UniAtual = paux;
    }
}

Universidade* Eluni::localizaUni(char* nome)
{
    ListaUni* paux = UniPrim;

    while(paux != NULL)
    {
        if(strcmp(paux->getUniLoc()->getNome(), nome) == 0)
        {
            return paux->getUniLoc();
        }

        paux = paux->prox;
    }

    return NULL;
}

void Eluni::ListUni(){
     ListaUni* paux1;
    paux1 = UniPrim;

    while(paux1!=NULL){
        cout<<paux1->getUniLoc()->getNome()<<endl;
        paux1 = paux1->prox;
    }
}
