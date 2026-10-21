#include"Departamento.h"
#include "Disciplinas.h"

Departamento::Departamento(char n[]){
    strcpy(nomeDepat,n);
    Discatual = NULL;
    Discprim = NULL;
}

Departamento::~Departamento(){
    ElDisciplina *paux1, *paux2;
    paux1 = Discprim;

    while(paux1 !=NULL){
        paux2 = paux1->prox;
        delete (paux1);
        paux1 = paux2;
    }

    Discatual = NULL;
    Discprim = NULL;
}

void Departamento::setNome(char n[]){
    strcpy(nomeDepat,n);
}

char* Departamento::getNome(){
    return nomeDepat;
}

void Departamento::setNomeUni(char n[]){
    strcpy(UniDepat,n);
}

char* Departamento::getNomeUni(){
    return UniDepat;
}

void Departamento::incluaDisciplina(Disciplina* pd){
    if( pd == NULL )
        return;

    ElDisciplina* paux = new ElDisciplina();
    paux->setDisc(pd);

    if(Discprim == NULL){
        Discprim = paux;
        Discatual = paux;
    }
    else{
        Discatual->prox = paux;
        paux->ant = Discatual;
        Discatual = paux;

    }
}

void Departamento::listeDisciplinas(){
    ElDisciplina* aux = Discprim;
    cout<<"Disciplinas de :"<<this->getNome()<<endl;
    while(aux !=NULL){
        cout<<aux->getNomeDisc()<<endl;
        aux = aux->prox;

    }
    cout<<endl;
}
