#include"Laluno.h"
#include"stdfx.h"

ElAluno::ElAluno(){
    pAl = NULL;
    pProx = NULL;
    pAnte = NULL;
}

ElAluno::~ElAluno(){
    pAl = NULL;
    pProx = NULL;
    pAnte = NULL;
}

void ElAluno::setAluno ( Aluno *pa ) {
    pAl = pa;
}

Aluno* ElAluno::getAluno ( ) {
    return pAl;
}

char* ElAluno::getNome ( ) {
    return pAl->getNome ( );
}
