#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED


tipoHora lerHora (void);
tipoData lerData (void);
void lerString(char vetor[50], int maxNome);
int lerInteiro (int limMin, int limMax);
float lerFloat (float limMin, float limMax);
void limparBuffer (void);
void limparEcran (void);
tipoMembro lerDadosMembro (void);
int procuraMembro (tipoMembro membros[],int totalMembros, int numUtente);
void mostrarMembro (tipoMembro comunidade[], int indice);
tipoMembro datConfinamento (tipoMembro membro);
tipoTeste lerDadosTeste (void);
int procuraTeste (tipoTeste teste[], int total, int num, int option);
int lerDuracao (void);
void mostrarTeste (tipoTeste *testes, int i);

#endif
