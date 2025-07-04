#include "inimigo.h"

void iniciarInimigos(char matriz[A][L], Inimigo inimigos[], int maxInimigos)
{
    int inimigoCount = 0;
    for (int i = 0; i < maxInimigos; i++)
    {
        inimigos[i].active = false;
    }

    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < L; j++)
        {
            if (matriz[i][j] == 'i' && inimigoCount < maxInimigos)
            {
                inimigos[inimigoCount].active = true;
                inimigos[inimigoCount].position.x = j * TAMANHO_BLOCO + TAMANHO_BLOCO / 2.0f;
                inimigos[inimigoCount].position.y = i * TAMANHO_BLOCO + TAMANHO_BLOCO / 2.0f;
                inimigos[inimigoCount].rec.width = TAMANHO_BLOCO;
                inimigos[inimigoCount].rec.height = TAMANHO_BLOCO;
                inimigos[inimigoCount].color = GREEN;
                inimigos[inimigoCount].moveTimer = 0.0f;
                inimigoCount++;
            }
        }
    }
}
