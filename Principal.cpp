#include"Principal.h"
#include<time.h>

Principal::Principal(){

    struct tm *local;
    time_t segundos;
    time(&segundos);
    local = localtime(&segundos);
// Retorna o dia.
    diaAtual = local->tm_mday;
// Retorna o mês.
    mesAtual = local->tm_mon + 1;
// Retorna o ano.
// É necessário acrescentar 1900, pois o sistema retorna a partir desse ano.
// Ao invés de 2009, retorna 109.
    anoAtual = local->tm_year + 1900;
    LAlunos.RecuperaAlunos();
    executar();
}

Principal::~Principal(){
}

void Principal::executar(){
    inicializaDpto();
    inicializaUNi();
    inicializaProf();
    inicializaAluno();
    inicializaDisc();

    incluiAlunos();
    incluiDisc();
    incluiDpto();
    incluiProf();

    menu();
}

void Principal::inicializaAluno(){
    Joao.inicializa(30,10,2007,"Joao Luiz Prado de Oliveira");
    Joao.CalcIdade(diaAtual,mesAtual,anoAtual);


}

void Principal::inicializaProf(){
    Simao.inicializa(3,10,1976,"Jean Simao");
    Simao.CalcIdade(diaAtual,mesAtual,anoAtual);

}

void Principal::inicializaUNi(){
    UTFPR.setNome("UTFPR");
}

void Principal::inicializaDpto(){
    DAINF.setNome("DAINF");
    MODA.setNome("MODAUTFPR");
    DAMAT.setNome("DAMAT");


}

void Principal::inicializaDisc(){

    tecProg_2026.setNomeDisc("Tecnicas de programacao");
    tecProg_2026.setId(102394);

    calculo.setNomeDisc("calculo");
    calculo.setId(123456);
}

void Principal::incluiAlunos(){

    Joao.setUnifiliado(&UTFPR);
    tecProg_2026.setAlunos(&Joao);
    calculo.setAlunos(&Joao);
}

void Principal::incluiProf(){
    Simao.setDepartamento(&DAINF);
    Simao.setUnivFiliado(&UTFPR);
    Simao.OndeTrabalho();
}

void Principal::incluiDisc(){

    tecProg_2026.setDepartamento(&DAINF);
    calculo.setDepartamento(&DAMAT);
    DAINF.incluaDisciplina(&tecProg_2026);
    DAMAT.incluaDisciplina(&calculo);
}

void Principal::incluiDpto(){
    UTFPR.setDepat(&DAINF);
    UTFPR.setDepat(&MODA);
    UTFPR.setDepat(&DAMAT);

}

void Principal::Listdpto(){
    DAINF.listeDisciplinas();
    DAMAT.listeDisciplinas();
    UTFPR.imprimeDpto();
}

void Principal::ListAlunos(){
   LAlunos.ListaAlunos();


}

void Principal::ListaUniver(){
    cout<< UTFPR.getNome()<<endl;
    LUniversidades.ListUni();

}

void Principal::cadUniversidade()
{
    char nome[80];

    cout << "Digite o nome da Universidade: ";
    cin >> nome;

    Universidade* pUni = new Universidade();

    pUni->setNome(nome);

    LUniversidades.inclueUni(pUni);
}

void Principal::cadAluno(){
    char nome[300];
    char nomeUni[80];
    int RA,diaNa,mesNa,AnoNa;

    cin.ignore(1000, '\n');
    cout << "Digite o nome da Universidade: ";
    cin.getline(nomeUni,80);

    Universidade* pUni = LUniversidades.localizaUni(nomeUni);
    if(pUni!=NULL){
        cin.ignore(1000, '\n');

        cout << "Digite o nome do Aluno: ";
        cin.getline(nome,300);
        cout<<endl;

        cout << "Digite o RA: ";
        cin >> RA;
        cout<<endl;


        cout << "Digite a data nascimento: ";
        cin >> diaNa;

        cout<<"/";


        cin >> mesNa;

        cout<<"/" ;


        cin >> AnoNa;

        Aluno* paux = new Aluno(diaNa,mesNa,AnoNa,nome);
        paux->setRA(RA);
        paux->setUnifiliado(pUni);
        LAlunos.inclueAlunos(paux);
    }
    else{
        cout<<"Universidade nao cadastrada"<<endl;
        getchar();
    }
}

void Principal::cadDepartamento()
{
    char nomeUni[80];
    char nomeDep[40];

    cout << "Digite o nome da Universidade: ";
    cin >> nomeUni;

    Universidade* pUni = LUniversidades.localizaUni(nomeUni);

    if(pUni != NULL)
    {
        cout << "Digite o nome do Departamento: ";
        cin >> nomeDep;

        Departamento* pDep = new Departamento();

        pDep->setNome(nomeDep);

        pUni->setDepat(pDep);
    }
    else
    {
        cout << "Universidade nao encontrada." << endl;
    }
}

void Principal::cadDisciplina()
{
    char nomeUni[80];
    char nomeDep[40];
    char nomeDisc[150];
    int id;

    cout << "Digite o nome da Universidade: ";
    cin >> nomeUni;

    Universidade* pUni = LUniversidades.localizaUni(nomeUni);

    if(pUni != NULL)
    {
        cout << "Digite o nome do Departamento: ";
        cin >> nomeDep;

        Departamento* pDep = pUni->localizaDepat(nomeDep);

        if(pDep != NULL)
        {
            cout << "Digite o nome da Disciplina: ";
            cin >> nomeDisc;

            cout << "Digite o ID da Disciplina: ";
            cin >> id;

            Disciplina* pDisc = new Disciplina();

            pDisc->setNomeDisc(nomeDisc);
            pDisc->setId(id);

            pDep->incluaDisciplina(pDisc);
        }
        else
        {
            cout << "Departamento nao encontrado." << endl;
        }
    }
    else
    {
        cout << "Universidade nao encontrada." << endl;
    }
}

void Principal::menu()
{
    int op = 0;

    while(op != 4)
    {
        system("cls");
        cout << "\n===== MENU =====" << endl;
        cout << "1 - Cadastro" << endl;
        cout << "2 - Execucao" << endl;
        cout << "3 - Gravar"   << endl;
        cout << "4 - Sair" << endl;
        cout << "Opcao: ";

        cin >> op;

        switch(op)
        {
            case 1:
                menuCad();
                break;

            case 2:
                ListaUniver();
                ListAlunos();
                system("pause");
                break;

            case 3:
                Gravar();
                break;

            case 4:
                cout << "Saindo..." << endl;
                break;

            default:
                cout << "Opcao invalida." << endl;
        }
    }
}

void Principal::menuCad()
{
    int op = 0;

    while(op != 6)
    {
        system("cls");
        cout << "\n===== CADASTRO =====" << endl;
        cout << "1 - Universidade" << endl;
        cout << "2 - Departamento" << endl;
        cout << "3 - Disciplina" << endl;
        cout << "4 - Aluno" << endl;
        cout << "5 - Professor" << endl;
        cout << "6 - Voltar" << endl;
        cout << "Opcao: ";

        cin >> op;

        switch(op)
        {
            case 1:
                cadUniversidade();
                break;

            case 2:
                cadDepartamento();
                break;

            case 3:
                cadDisciplina();
                break;

            case 4:
                cadAluno();
                break;
            /*
            case 5:
                cadProfessor();
                break;
                    */
            case 6:
                break;

            default:
                cout << "Opcao invalida." << endl;
        }
    }
}

void Principal::Gravar(){

    int op = 0;

    while(op != 2){
        system("cls");
        cout<<"escolha a opção que deseja salvar"<<endl;
        cout<<"1 gravar alunos"<<endl;
        cout<<"2 sair"<<endl;
        cin >> op;

        switch(op){
            case 1:
                LAlunos.GravaAlunos();
                break;
            case 2:
                break;
            default:
                cout << "Opcao invalida." << endl;

        }
    }
}
