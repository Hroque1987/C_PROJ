
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "DATA.h"
#include "AUX.h"
#include "MENUS.h"

// ------------------------- ACRESCENTAR MEMBRO ----------------------

void acrescentarMembro(info *contagens, tipoMembro comunidade[MAX] )
{

    tipoMembro dados;
    int pos;


    if (contagens->membros == MAX)
    {
        printf("Impossivel acrescentar Membro");
    }
    else
    {

        dados = lerDadosMembro();
        pos = procuraMembro(comunidade, contagens->membros, dados.numUtente );
        if (pos == -1)
        {
            comunidade[contagens->membros] = dados;
            contagens->membros ++;
        }
        else
        {
            printf("Membro já existe. \n");
        }

    }


}

// ------------------------- LISTAR MEMBROS ----------------------


void listarMembros(info contagem, tipoMembro comunidade[])
{

    int i, option;

    if (contagem.membros == 0)
    {
        printf("\n Nao existem membros inseridos !");
    }

    else
    {

        printf("Selecione o filtro: \n ");

        char filtro[4][20] = {"Todos", "Docente", "Estudante", "Tecnico"};
        option = menuOpcoes(filtro, 4);

        for (i = 0; i < contagem.membros; i++)
        {
            if (option != 0)
            {
                if (stricmp(comunidade[i].tipMembro, filtro[option] ) == 0 )
                {
                    mostrarMembro (comunidade, i);
                }
                else
                {
                    printf("Nao existem membros deste tipo ! \n ");
                }
            }
            else
            {
                mostrarMembro(comunidade, i);
            }
        }
    }

}

//--------------Alterar estado vacina ---------------

void estadoVacina(info contagem, tipoMembro comunidade[] )
{
    int num, pos, option;
    printf("\t Registar / alterar estado vacina ");
    printf("Numero de Utente : ");
    num = lerInteiro(100000000,999999999);


    pos = procuraMembro(comunidade, contagem.membros, num);


    printf("Estado Vacina: \n ");
    char vacina[4][20] = {"Sem vacina", "Dose 1", "Dose 2", "Dose 3" };
    option = menuOpcoes(vacina, 4);
    strcpy(comunidade->estadoVacina, vacina[option]);
    if(option != 0)
    {
        printf("Data da ultima vacina: \n ");
        comunidade[pos].dataVacina = lerData();
    }
    else
    {
        comunidade[pos].dataVacina.ano = 0000;
        comunidade[pos].dataVacina.mes= 00;
        comunidade[pos].dataVacina.dia = 00;
    }
    limparEcran();


}

//--------------Alterar estado confinamento ---------------

void estadoConfinamento(info contagem, tipoMembro comunidade[] )
{

    int num, pos, option;
    printf("\t Alterar estado confinamento ");
    printf("Numero de Utente : ");
    num = lerInteiro(100000000,999999999);


    pos = procuraMembro(comunidade, contagem.membros, num);


    printf("Estado Confinamento: \n ");
    char confinamento[3][20] = {"Desconfinado", "Quarentena", "Isolamento"};
    option = menuOpcoes(confinamento, 3);
    strcpy(comunidade->estadoConfinamento, confinamento[option]);
    if (option !=0 )
    {

        comunidade[contagem.membros-1] = datConfinamento (comunidade[contagem.membros-1]);
    }
    else
    {
        comunidade[contagem.membros-1].dataConf.ano = 0000;
        comunidade[contagem.membros-1].dataConf.mes = 00;
        comunidade[contagem.membros-1].dataConf.dia = 00;
        comunidade[contagem.membros-1].durConf=0;
    }
    limparEcran();


}

// ------------------------- LISTAR Confinamentos ----------------------

void listarConfinamentos(info contagem, tipoMembro comunidade[])
{

    int i, option;

    if (contagem.membros == 0)
    {
        printf("\n Nao existem membros inseridos !");
    }

    else
    {

        printf("Selecione o filtro: \n ");

        printf("Estado Confinamento: \n ");
        char confinamento[3][20] = {"Desconfinado", "Quarentena", "Isolamento"};
        option = menuOpcoes(confinamento, 3);

        for (i = 0; i < contagem.membros; i++)
        {
            if (stricmp(comunidade[i].estadoConfinamento, confinamento[option] ) == 0 )
            {
                mostrarMembro (comunidade, i);
            }
            else
            {
                printf("Não existem membros neste estados. \n ");
            }
        }
    }

}

// ------------------------- AGENDAR TESTES ----------------------
tipoTeste *agendarTeste(info *contagens, tipoTeste *novoTeste, tipoMembro comunidade[])
{
    if (contagens->membros == 0)
    {
        printf("\t ERRO => Nao existem membros resgstados. \n");
    }
    else
    {
        tipoTeste *testes, dados;
        testes = novoTeste;
        int pos, posTeste = -1, opcaoProcura = 1;

        dados = lerDadosTeste();


        pos = procuraMembro(comunidade, contagens->membros, dados.numUtente);
        if (contagens->testes > 0)
        {
            posTeste = procuraTeste(testes, contagens->testes, dados.numteste, opcaoProcura);
        }
        printf("\t ERRO => %d \n", posTeste);

        if (pos == -1 || posTeste != -1  )
        {
            if (posTeste != -1)
            {
                printf("\t ERRO => Numero teste ja registado. \n");
            }
            if (pos == -1)
            {
                printf("\t ERRO => Membro inexistente \n");
            }

        }
        else
        {
            novoTeste = realloc(novoTeste,(contagens->testes+1)*sizeof(tipoTeste));
            if (novoTeste == NULL)
            {
                printf ("\t ERRO => Impossivel Agendar teste");
                novoTeste = novoTeste;
            }
            else
            {
                novoTeste[contagens->testes]= dados;
                contagens->testes ++;
            }
        }
        return novoTeste;

    }

}


//--------------Registar Resultado Teste ---------------

void ResultadoTeste(info contagem, tipoTeste *testes )
{
    int num, pos, option;
    printf("\t Registar / alterar Resultado Teste ");
    printf("Numero de Teste : ");
    num = lerInteiro(1000,9999);


    pos = procuraTeste(testes, contagem.testes, num, 1);


    printf("Resultado do Teste: \n ");
    char resultado[3][20] = {"Positivo", "Negativo", "Inconclusivo"};
    option = menuOpcoes(resultado, 3);
    strcpy(testes->resultado, resultado[option]);

    printf("Hora do Teste: \n ");
    testes[pos].horaColheita = lerHora();

    printf("Duracao do Teste: \n ");
    testes[pos].duracao = lerDuracao();

    limparEcran();


}

// ------------------------- LISTAR Testes----------------------

void listarTestes(info contagem, tipoTeste *testes)
{

    int i, option;

    if (contagem.testes == 0)
    {
        printf("\n Nao existem Testes !\n");
    }

    else
    {

        printf("Selecione o filtro: \n ");

        char filtro[2][20] = {"PCR", "Antigenio"};
        option = menuOpcoes(filtro, 2);

        for (i = 0; i < contagem.testes; i++)
        {
            if (stricmp(testes[i].tipTeste, filtro[option] ) == 0 )
            {
                mostrarTeste (testes, i);
            }
            else
            {
                printf("Não existem testes deste tipo ! \n ");
            }
        }
    }

}
