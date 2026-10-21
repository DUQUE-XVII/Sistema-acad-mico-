#include"Pessoa.h"
#include"stdfx.h"

Pessoa::Pessoa(int diaNa, int mesNa, int anoNa, const char nome[]){
    inicializa(diaNa,mesNa,anoNa,nome);
}
Pessoa::Pessoa(){
    inicializa(0,0,0);
}

void Pessoa::inicializa(int diaNa, int mesNa, int anoNa, const char* nome){
    diaP = diaNa;
    mesP = mesNa;
    anoP = anoNa;
    strcpy(nomeP,nome);
    idadeP = -1;
}

void Pessoa::CalcIdade(int diaAt, int mesAt, int anoAt)
{
    idadeP = anoAt - anoP;
    if(mesAt < mesP || (mesAt == mesP && diaAt < diaP))
        idadeP --;
}

int Pessoa::getIdade()
    { return idadeP;  }

char* Pessoa::getNome()
    { return nomeP;  }

void Pessoa::setUnifiliado(Universidade* pu){
    UniFiliado = pu;
}
char* Pessoa::OndeEstuda(){
   return UniFiliado->getNome();
}



