#include "Universidade.h"
#include "ElDepat.h"

Universidade::Universidade(char n[]){
    strcpy(nome,n);
    DepatPrim = NULL;
    DepatAtual = NULL;
}

Universidade::~Universidade(){
    Eldepat* paux = DepatPrim;

    while (paux != NULL) {
        Eldepat* prox = paux->Dprox;
        delete paux;
        paux = prox;
    }

    DepatPrim = NULL;
    DepatAtual = NULL;

}

void Universidade::setNome(char n[]){
    strcpy(nome,n);
}

char* Universidade::getNome(){
    return nome;
}
void Universidade::setDepat(Departamento* n){
    if(n == NULL)
        return;
    Eldepat* paux = NULL;
    paux = new Eldepat();
    paux->setDepat(n);
    if(DepatPrim == NULL){
        DepatPrim = paux;
        DepatAtual = paux;
    }
    else{
        DepatAtual->Dprox = paux;
        paux->Dant = DepatAtual;
        DepatAtual = paux;
    }

}

void Universidade::imprimeDpto(){
    cout<<" Lista de departamentos da "<<nome<<endl;
    Eldepat* paux = DepatPrim;
    while(paux !=NULL){
        cout<<  paux->getNomeDepat()<<endl;
        paux = paux->Dprox;
    }

    cout<<endl;
}

Departamento* Universidade::localizaDepat(char* nome)
{
    Eldepat* paux = DepatPrim;

    while(paux != NULL)
    {
        if(strcmp(paux->getNomeDepat(), nome) == 0)
            return paux->getDepat();

        paux = paux->Dprox;
    }

    return NULL;
}
