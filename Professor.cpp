#include"Professor.h"

Professor::Professor ( int diaNa, int mesNa, int anoNa, char* nome) :Pessoa ( diaNa, mesNa, anoNa, nome)
{
    pUnivFiliado = NULL; pDptoFiliado = NULL;
}

Professor::Professor ( ) :
Pessoa ( )
{
    pUnivFiliado = NULL;
    pDptoFiliado = NULL;
}
Professor::~Professor ( )
{
    pUnivFiliado = NULL;
    pDptoFiliado = NULL;
}
void Professor::setUnivFiliado ( Universidade* pu)
{
    pUnivFiliado = pu;
}
void Professor::setDepartamento ( Departamento* pdpto)
{
    pDptoFiliado = pdpto;
}
void Professor::OndeTrabalho ( )
{
    cout << this->getNome() << "trabalha para a " << pUnivFiliado->getNome() << endl;
}
void Professor::QualDepartamentoTrabalho()
{
    cout << this->getNome()  << " trabalha para a " << pUnivFiliado->getNome()
    <<" " << pDptoFiliado->getNome()
    << endl;
}
