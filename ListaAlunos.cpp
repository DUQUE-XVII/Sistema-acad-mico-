#include    "ListaAlunos.h"
#include    <string>
listalun::listalun(){
    ALUNOATUAL = NULL;
    ALUNOPRIM = NULL;

}

listalun::~listalun(){

}


void listalun::inclueAlunos(Aluno* pAlu){
    if(pAlu == NULL)
        return;
    ElAluno* paux = new ElAluno();
    paux->setAluno(pAlu);
    if(ALUNOPRIM == NULL){
        ALUNOATUAL = paux;
        ALUNOPRIM = paux;
    }
    else{
        ALUNOATUAL->pProx = paux;
        paux->pAnte = ALUNOATUAL;
        ALUNOATUAL = paux;
    }

}

void listalun::GravaAlunos(){
    ofstream GravadorAlunos ( "alunos.bin", ios::binary |ios::out );
    if ( !GravadorAlunos )
    {
        cerr << " Arquivo não pode ser aberto " << endl;
        system("pause");
        return;
    }
    ElAluno* pauxElAluno;
    pauxElAluno = ALUNOPRIM;

    while ( pauxElAluno != NULL)
    {
        Aluno* pauxAluno;
        pauxAluno = pauxElAluno->getAluno();

        int RA = pauxAluno->getRA();
        char nome[300];
        char UNIF[300];
        strcpy(nome,pauxAluno->getNome());
        strcpy(UNIF,pauxAluno->getUnifiliado());


        GravadorAlunos.write((char*) &RA, sizeof(RA) );
        GravadorAlunos.write((char*) &nome, sizeof(nome) );
        GravadorAlunos.write((char*) &UNIF, sizeof(UNIF) );
        pauxElAluno = pauxElAluno->pProx;
    }
GravadorAlunos.close ();

}

void listalun::RecuperaAlunos(){
    ifstream RecuperadorAlunos("alunos.bin", ios::binary|ios::in);
    if(!RecuperadorAlunos){
        cerr << " Arquivo não pode ser aberto " << endl;
        system("pause");
        return;
    }
    while (true)
    {
        int RA;
        char nome[300];
        char UNIF[300];

        if (!RecuperadorAlunos.read((char*)&RA, sizeof(RA)))
                break;

        RecuperadorAlunos.read(nome, sizeof(nome));
        RecuperadorAlunos.read(UNIF, sizeof(UNIF));

        if (!RecuperadorAlunos)
            break;

        Aluno* paux = new Aluno(0, 0, 0, nome);

        paux->setRA(RA);
        paux->setUniNome(UNIF);

        inclueAlunos(paux);
    }



    RecuperadorAlunos.close();

}


void listalun::ListaAlunos(){
    ElAluno* paux = ALUNOPRIM;
    while(paux != NULL){
        cout<<paux->getNome()<<endl;
        paux = paux->pProx;
    }

}
