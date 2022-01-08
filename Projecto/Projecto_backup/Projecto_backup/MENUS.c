
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "DATA.h"
#include "MENUS.h"
#include "AUX.h"


// ----------------------- MENUS -------------------------


// ---------------------MENU PRINCIPAL -----------------
int menu(info contagens)
{

    int opcao;

    printf("Membros : ");
    printf("%d \n", contagens.membros);
    printf("Testes agendados : ");
    printf("%d \n", contagens.testes);
    printf("Testes realizados : ");
    printf("%d \n", contagens.testesRealizados);
    printf("Vacinados : ");
    printf("%d \n\n", contagens.vacinados);




    printf("GESTAO COVID 19 \n");
    printf("\t 1- Membros \n");
    printf("\t 2- Testes \n");
    printf("\t 3- Estatistica \n");
    printf("\t 4- Armazenamento \n");
    printf("\t 0- Sair \n");



    opcao = lerInteiro(0, 4);
    limparEcran();

    return opcao;
}

// ----------------------MEMBROS--------------------
int menuMenbros(void)
{
    int opcao;

    printf("GESTAO DE MEMBROS DA COMUNIDADE \n");
    printf("\t 1- Inserir Membros \n");
    printf("\t 2- Listar Membros \n");
    printf("\t 3- Registar/actulizar vacinacao \n");
    printf("\t 4- Registar/actulizar confinamento \n");
    printf("\t 5- Listar confinamentos \n");
    printf("\t 0- Sair \n");



    opcao = lerInteiro(0, 5);
    limparEcran();

    return opcao;
}

//-------------------------------MENU TESTES -------------------
int menuTestes(void)
{
    int opcao;

    printf("GESTAO DE TESTES \n");
    printf("\t 1- Agendar teste \n");
    printf("\t 2- Registar resultado do teste \n");
    printf("\t 3- Ver teste \n");
    printf("\t 4- Alterar data do teste \n");
    printf("\t 5- Listar testes \n");
    printf("\t 0- Sair \n");


    opcao = lerInteiro(0, 5);
    limparEcran();

    return opcao;
}

// ---------------------MENU ESTATISTICAS------------
int menuEstatisticas(void)
{
    int opcao;

    printf("ESTATISTICAS \n");
    printf("\t 1- Quantidade de membros por tipo \n");
    printf("\t 2- Tempo medio de duracao do teste \n");
    printf("\t 3- Percentagem de testes iconclusivos \n");
    printf("\t 4- Membros da comunidade com menor numero de testes realizados \n");
    printf("\t 5- Teste mais recente \n");
    printf("\t 0- Sair \n");

    opcao = lerInteiro(0, 5);
    limparEcran();

    return opcao;
}

// -------------------MENU ARMAZENAMENTO -------------
int menuArmazenamento(void)
{
    int opcao;

    printf(" ARMAZENAMENTO \n");
    printf("\t 1- Guardar no ficheiro \n");
    printf("\t 2- Ler do ficheiro \n");
    printf("\t 0- Sair \n");

    opcao = lerInteiro(0, 2);
    limparEcran();

    return opcao;
}

//---------------------MENU SIM/NAO ------------

int menuSimNAO(char msg[10])
{
    int opcao;

    printf("%s \n", msg);
    printf("\t 1- NAO \n");
    printf("\t 2- SIM \n");

    opcao = lerInteiro(1, 2);
    limparEcran();

    return opcao;
}

//---------------------MENU OPÇOES ------------

int menuOpcoes(char selecao[5][20], int numOpt)
{
    int opcao, i;
    for (i=0 ; i < numOpt; i++){
        printf("\t %d -", i+1);
        puts(selecao[i]);
    }

    opcao = lerInteiro(1, numOpt);
    opcao --;

    return opcao;
}
