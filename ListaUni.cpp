#include "ListaUni.h"

ListaUni::ListaUni(){
    prox = NULL;
    ant = NULL;
    uni = NULL;
}

ListaUni::~ListaUni(){
    prox = NULL;
    ant = NULL;
    uni = NULL;

}

void ListaUni::setUniLista(Universidade* pUni){
    uni = pUni;
}

Universidade* ListaUni::getUniLoc(){
    return uni;
}
