#include"Disciplinas.h"

Disciplina::Disciplina(int na,char* ac){
    pDeptoAssociado = NULL;
    pElAlunoAtual = NULL;
    pElAlunoPrim = NULL;
    strcpy(area_conhecimento,ac);
    max_alunos = na;
    n_alunos = 0;

}

Disciplina::~Disciplina(){
    ElAluno *paux1, *paux2;
    paux1 = pElAlunoPrim;

    while(paux1!=NULL){
        paux2 = paux1->pProx;
        delete (paux1);
        paux1 = paux2;

    }

    pDeptoAssociado = NULL;

}

char* Disciplina::getNomeDisc(){
   return nome;

}
void Disciplina::setNomeDisc(char* n){
    strcpy(nome,n);
}

void Disciplina::setId(int n){
    id = n;
}

int Disciplina::getId(){
    return id;
}

void Disciplina::setDepartamento(Departamento* pdpto){
    pDeptoAssociado = pdpto;
}

Departamento* Disciplina::getDepartamento(){
    return pDeptoAssociado;
}

void Disciplina::setAlunos(Aluno* pAluno){
        ElAluno* paux = NULL;
        paux = new ElAluno();
        paux->setAluno(pAluno);

        if(pAluno == NULL)
            return;
    if(max_alunos> n_alunos && pElAlunoPrim == NULL){
        pElAlunoPrim = paux;
        pElAlunoAtual = paux;
        cout<<pAluno->getNome()<<" incluido em: "<<this->getNomeDisc()<<endl;
        n_alunos++;
    }
    else if(max_alunos> n_alunos){
        pElAlunoAtual->pProx = paux;
        paux->pAnte = pElAlunoAtual;
        pElAlunoAtual = paux;
        cout<<pAluno->getNome()<<" incluido em: "<<this->getNomeDisc()<<endl;
        n_alunos++;
    }
    else
        cout<<"turma cheia"<<endl;
}

void Disciplina::Listealunos()
{
    ElAluno* paux;
    paux = pElAlunoPrim;
    while ( paux != NULL )
    {
        printf(" Aluno %s matriculado na Disciplina %s \n", paux->getNome(), nome);
        paux = paux->pProx;
    }
}
