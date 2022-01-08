
#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

void acrescentarMembro(info *contagens, tipoMembro comunidade[]);
void listarMembros(info contagem, tipoMembro comunidade[]);
void estadoVacina(info contagem, tipoMembro comunidade[]);
void estadoConfinamento(info contagem, tipoMembro comunidade[]);
void listarConfinamentos(info contagem, tipoMembro comunidade[]);
tipoTeste *agendarTeste(info *contagens, tipoTeste *novoTeste, tipoMembro comunidade[]);
void ResultadoTeste(info contagem, tipoTeste *testes );
void listarTestes(info contagem, tipoTeste *testes);


#endif
