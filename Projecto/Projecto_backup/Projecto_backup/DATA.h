
#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED


/** ------------------------ Constantes ----------------------- **/
#define MAX 10
#define MAXTESTES 15
#define MAX_MEMBROS 200
#define ANO_MIN 2000
#define ANO_MAX 2500

#define CONTRIBUITE_MIN 111111111
#define CONTRIBUITE_MAX 999999999



//-----------------------STRUCTS---------------------

typedef struct
{
    int hora;
    int minuto;
} tipoHora;


typedef struct
{
    int dia;
    int mes;
    int ano;
} tipoData;


typedef struct
{
    int numUtente;
    char nome[50];
    char tipMembro[15];
    int anoNascimento;
    char estadoConfinamento[30];
    char estadoVacina[30];
    tipoData dataVacina;
    tipoData dataConf;
    int durConf;
} tipoMembro;


typedef struct
{
    int numteste;
    char tipTeste[50];
    tipoData dataTeste;   //<--- max 15 testes
    int numUtente;
    char resultado[30];
    tipoHora horaColheita;
    tipoHora horaResultado;  //<----------
    int duracao;

} tipoTeste;

typedef struct
{
    int membros;
    int testes;
    int testesRealizados;
    int vacinados;
} info;


#endif
