#include "game.h"

void LeMapa(char nome_arq[], char matrix[A][L]);
{
    FILE *arq;

    int i;
    int j;

    arq = fopen(nome_arq, "r");
    if(arq == NULL)
    {
        printf("ERRO");
    }
    else
    {

        for(i = 0; i < A; i++)
        {
            for(j = 0; j < L; j++)
            {

                fgetc(matrix[i][j], 1, arq); // copiar caracteres do mapa para a matriz

            }
        }
    }
}

