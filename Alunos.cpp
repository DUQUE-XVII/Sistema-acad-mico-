#include"Alunos.h"

Aluno::Aluno(int diaNa, int mesNa, int anoNa, char* nome):
Pessoa(diaNa,mesNa,anoNa,nome){
    prox = NULL;
    ant = NULL;
    RA = -1;
    strcpy(Uni,"");

}

Aluno::~Aluno()
{
    prox = NULL;
    ant = NULL;
}

void Aluno::setRA(int i){
    RA = i;
}

int Aluno::getRA(){
    return RA;
}

char* Aluno::getUnifiliado(){
    return OndeEstuda();

}

void Aluno::setUniNome(char* nome){
    strcpy(Uni,nome);
    Universidade* paux = new Universidade();

    paux->setNome(nome);
    this->setUnifiliado(paux);
}
