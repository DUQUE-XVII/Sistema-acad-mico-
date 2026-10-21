#include "ElDepat.h"

Eldepat::Eldepat(){
    pelDepto = NULL;
     Dprox = NULL;
     Dant = NULL;

}

Eldepat::~Eldepat(){

}

void Eldepat::setDepat(Departamento* Dpto){
    pelDepto = Dpto;

}

void Eldepat::setNomeUni(char* n){
    pelDepto->setNomeUni(n);
}

Departamento* Eldepat::getDepat(){
    if(pelDepto==NULL)
        cout<< "Sem departamento"<<endl;
    return pelDepto;
}

char* Eldepat::getNomeDepat(){
    if(pelDepto==NULL)
        cout<< "Sem departamento"<<endl;
    return pelDepto->getNome();
}
