#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <string.h>

#include "DATA.h"
#include "AUX.h"
#include "MENUS.h"
#include "FUNC.h"


int main()
{

    info contagens;
    contagens.membros =0;
    contagens.testes=0;
    contagens.testesRealizados=0;
    contagens.vacinados=0;

    tipoMembro comunidade[MAX_MEMBROS];

    int optionMenu;

    tipoTeste *testes;
    testes = NULL;

    do
    {

        optionMenu = menu(contagens);
        int subOption;
        switch (optionMenu)

        {
        case 1:
            {


            subOption = menuMenbros();
            switch (subOption)
            {
            case 1:
            {
                acrescentarMembro(&contagens, comunidade);
                break;

            }
            case 2:
            {
                listarMembros(contagens, comunidade);
                break;

            }
            case 3:
            {
                estadoVacina(contagens, comunidade);
                break;

            }
            case 4:
            {
                estadoConfinamento(contagens, comunidade);
                break;

            }
            case 5:
            {
                listarConfinamentos(contagens, comunidade);
                break;

            }

            }
             break;
             }

        case 2:
            {


            subOption = menuTestes();
            switch (subOption)
            {
            case 1:
            {
                testes = agendarTeste(&contagens, testes, comunidade);
                break;
            }
            case 2:
            {
                ResultadoTeste(contagens, testes);
                break;

            }
            case 5:
            {
                listarTestes(contagens,testes);
                break;

            }

            }
        break;
        }

    }
    }
while (optionMenu != 0);

   /*case 3:
            {
            estadoVacina(contagens, comunidade);
            break;

            }
             case 4:
            {
            estadoConfinamento(contagens, comunidade);
            break;

            }
             case 5:
            {
            listarConfinamentos(contagens, comunidade);
            break;

            }
            */


/*a = menuMembros();
a = menuTestes();
a = menuEstatisticas();
a = menuArmazenamento();
a = menuSimNAO(b);*/


free(testes);
return 0;
}
