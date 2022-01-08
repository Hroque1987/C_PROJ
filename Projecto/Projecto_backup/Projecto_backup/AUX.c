
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "DATA.h"
#include "AUX.h"
#include "MENUS.h"


// --------------------------LER HORA---------------
tipoHora lerHora (void)
{
    tipoHora hora;

    printf("Insira as horas do teste: \n ");
    hora.hora = lerInteiro(0, 23);
    printf("Insira os minutos do teste: \n ");
    hora.minuto = lerInteiro(0, 59);

    return hora;
}

//--------------------------LER DATA------------
tipoData lerData (void)
{
    tipoData data;
    int diaMax;
    printf("Insira o ano: \n ");
    data.ano = lerInteiro(ANO_MIN, ANO_MAX);
    printf("Insira o mes: \n ");
    data.mes = lerInteiro(1, 12);

    int days_in_month[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if(data.mes = 2)
    {
        if (data.ano % 400 == 0 || (data.ano % 4 == 0 && data.ano % 100 != 0))
        {
            days_in_month[2] = 29;
        }
        else
        {
            days_in_month[2] = 28;
        }
    }


    diaMax = days_in_month[data.mes];
    printf("Insira o dia: \n ");
    data.dia = lerInteiro(1, diaMax);

    return data;
}


//-----------------------------------------------------LER STRING -------------------


void lerString(char vetor[80], int maxNome)
{
    int tamanhoString;

    do
    {
        fgets(vetor, maxNome, stdin);
        tamanhoString = strlen(vetor);
    }
    while (tamanhoString == 1);

    if (vetor[tamanhoString-1] != '\n')
    {
        limparBuffer();
    }
    else
    {
        vetor[tamanhoString-1] ='\0';
    }

}

//-----------------------------------------------------------------LER INTEIRO----
int lerInteiro (int limMin, int limMax)
{
    int num, res;


    do
    {
        res = scanf("%d", &num);
        limparBuffer();

        if (res != 1)
        {
            printf("\n Valor inserido tem de ser inteiro\n");
        }
        else
        {
            if (num < limMin || num > limMax)
            {
                printf("\n Valor tem de pertencer ao intervalo [%d, %d].\n", limMin, limMax);
            }
        }

    }
    while (num < limMin || num > limMax || res != 1);

    return num;
}


//-------------------------------------------- LER FLOAT ---------------------------

float lerFloat (float limMin, float limMax)
{
    float num;
    int res;


    do
    {

        res = scanf("%f", &num);
        limparBuffer();

        if (res != 1)
        {
            printf("\n Valor inserido tem de ser um numero. \n");
        }
        else
        {
            if (num < limMin || num > limMax)
            {
                printf("\n Valor tem de pertencer ao intervalo [%.2f, %.2f].\n", limMin, limMax);
            }
        }

    }
    while (num < limMin || num > limMax || res != 1);

    return num;
}


//-----------------------------------------LIMPA BUFFER --------------------------------------------

void limparBuffer (void)
{
    char lixo;

    do
    {
        lixo = getchar();

    }
    while (lixo != '\n' && lixo != EOF);
}

// ---------------------------------- LIMPA ECRA-----------------


void limparEcran (void)
{
#ifdef __APPLE__
    system("clear");
    //printf("Mac");
#endif

#ifdef _WIN32
    system("cls");
    //printf("win");
#endif

}

// ---------------------------------- Ler dados membro -----------------

tipoMembro lerDadosMembro (void)
{

    tipoMembro dadosMembro;
    int option;

    printf("Numero de Utente : ");
    dadosMembro.numUtente = lerInteiro(100000000,999999999);

    printf("Nome: ");
    lerString(dadosMembro.nome,50);

    printf("Tipo membro: \n ");
    char tiposMemb[3][20] = {"Estudante", "Docente", "Tecnico"};
    option = menuOpcoes (tiposMemb, 3);
    strcpy(dadosMembro.tipMembro, tiposMemb[option]);


    printf("Ano nacimento: ");
    dadosMembro.anoNascimento = lerInteiro(1950,2000);

    printf("Estado Confinamento: \n ");
    char confinamento[3][20] = {"Desconfinado", "Quarentena", "Isolamento"};
    option = menuOpcoes(confinamento, 3);
    strcpy(dadosMembro.estadoConfinamento, confinamento[option]);
    if (option !=0 )
    {
        dadosMembro = datConfinamento ( dadosMembro);
    }
    else
    {
        dadosMembro.dataConf.ano = 0000;
        dadosMembro.dataConf.mes = 00;
        dadosMembro.dataConf.dia = 00;
    }


    printf("Estado Vacina: \n ");
    char vacina[4][20] = {"Sem vacina", "Dose 1", "Dose 2", "Dose 3" };
    option = menuOpcoes(vacina, 4);
    strcpy(dadosMembro.estadoVacina, vacina[option]);

    if(option != 0)
    {
        printf("Data da ultima vacina: \n ");
        dadosMembro.dataVacina = lerData();
    };
    limparEcran ();

    return dadosMembro;

}

// ---------------------------------- Procurar membro -----------------

int procuraMembro (tipoMembro comunidade[], int total, int numUtente)
{
    int i, pos;

    pos = -1;
    for ( i=0; i < total ; i++)
    {
        if ( comunidade[i].numUtente == numUtente)
        {
            pos = i;
            i = total;
        }
    }

    return pos;
}


// ---------------------------------- Mostrar membro -----------------


void mostrarMembro (tipoMembro comunidade[], int indice)
{
    printf("\t Num. Utente: %d \n", comunidade[indice].numUtente);
    printf("\t Nome : %s \n", comunidade[indice].nome);
    printf("\t Tipo membro : %s \n\n", comunidade[indice].tipMembro);
    printf("\t Estado vacina : %s \n\n", comunidade[indice].estadoVacina);
    printf("\t Estado confinamento : %s \n\n", comunidade[indice].estadoConfinamento);
    printf("\t Data confinamento : %d-%d-%d  \n\n", comunidade[indice].dataConf.ano, comunidade[indice].dataConf.mes, comunidade[indice].dataConf.dia );
    printf("\t Dias de confinamento : %d \n\n", comunidade[indice].durConf );
    printf("\t Data ultima vacina : %d-%d-%d  \n\n", comunidade[indice].dataVacina.ano, comunidade[indice].dataVacina.mes, comunidade[indice].dataVacina.dia );

}


// ---------------------------------- Data / duração confinamento -----------------

tipoMembro datConfinamento (tipoMembro membro)
{
    printf("\t Data / duração confinamento\n");

    printf(" Insira a data de confinamento:\n");
    membro.dataConf = lerData ();
    printf("\n Insira a duracao do confinamento (dias):");
    membro.durConf = lerInteiro (7, 14);

    return membro;



}


// ---------------------------------- Ler dados teste -----------------

tipoTeste lerDadosTeste (void)
{

    tipoTeste dadosTeste;
    int option;


    printf("Numero de Teste : ");
    dadosTeste.numteste = lerInteiro(1000,9999);

    printf("Numero de Utente : ");
    dadosTeste.numUtente = lerInteiro(100000000,999999999);

    printf("Tipo Teste: \n ");
    char tiposTeste[2][20] = {"PCR", "Antigenio"};
    option = menuOpcoes (tiposTeste, 2);
    strcpy(dadosTeste.tipTeste, tiposTeste[option]);


    printf("Data do Teste: ");
    dadosTeste.dataTeste = lerData();

    return dadosTeste;

}

// ---------------------------------- Procurar teste -----------------
// Opção 1: Procura teste por numero de teste
// Opção 2: Procura teste por numero utente

int procuraTeste (tipoTeste teste[], int total, int num, int option)
{
    int i, pos;

    pos = -1;
    for ( i=0; i < total ; i++)
    {
        if (option == 1)
        {
            if ( teste[i].numteste == num)
            {
                pos = i;
                i = total;
            }
        }
        else if (option == 2)
        {
            if ( teste[i].numUtente == num)
            {
                pos = i;
                i = total;
            }
        }


    }

    return pos;
}
// --------------------------LER Duração Teste---------------
int lerDuracao (void)
{
    int duracao;

    duracao = lerInteiro(0, 60);

    return duracao;
}

// ---------------------------------- Mostrar Teste -----------------


void mostrarTeste (tipoTeste *testes, int indice)
{
    printf("\t Num. Utente: %d \n", testes[indice].numUtente);
    printf("\t Numero Teste : %d \n", testes[indice].numteste);
    printf("\t Tipo de Teste : %s \n\n", testes[indice].tipTeste);
    printf("\t Resultado Teste : %s \n\n", testes[indice].resultado);
}

