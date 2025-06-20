void LeMapa(char nome_arq[], char matrix[A][L])
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
                matrix[i][j] = fgetc(arq); // copiar caracteres do mapa para a matriz
            }
        }

        fclose(arq);
    }
}
