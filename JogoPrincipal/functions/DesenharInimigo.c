#include "game.h"


void desenharInimigos(Inimigo inimigos[], int totalInimigos)
{

    for (int i = 0; i < totalInimigos; i++)
    {

        if (inimigos[i].active)
        {
            // desenha o ret�ngulo do inimigo usando sua posi��o, tamanho e cor
            DrawRectangleRec(inimigos[i].rec, inimigos[i].color);
        }
    }
}
