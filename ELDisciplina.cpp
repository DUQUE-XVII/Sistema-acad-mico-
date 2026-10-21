#include "ElDisciplina.h"
#include "Disciplinas.h"

ElDisciplina::ElDisciplina(){

    prox = NULL;
    ant = NULL;
    pDisc = NULL;

}

ElDisciplina::~ElDisciplina(){
}

void ElDisciplina::setDisc(Disciplina* disc){
    pDisc = disc;

}

Disciplina* ElDisciplina::getDisciplina(){
    return pDisc;
}

char* ElDisciplina::getNomeDisc(){
    return pDisc->getNomeDisc();
}
