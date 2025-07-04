#include "game.h"


void desenharInimigos(Inimigo inimigos[], int totalInimigos)
{

    for (int i = 0; i < totalInimigos; i++)
    {

        if (inimigos[i].active)
        {
            // desenha o retângulo do inimigo usando sua posição, tamanho e cor
            DrawRectangleRec(inimigos[i].rec, inimigos[i].color);
        }
    }
}
