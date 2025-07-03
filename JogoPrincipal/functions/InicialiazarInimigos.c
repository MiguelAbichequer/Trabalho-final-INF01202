#include "game.h"

void iniciarInimigos(Inimigo inimigos[])
{
    for (int i = 0; i < MAX_INIMIGOS; i++)
    {
        inimigos[i].position = (Vector2){ 0, 0 };
        inimigos[i].speed = VELOCIDADE_INIMIGO;
        inimigos[i].size = 10.0f; // Raio do círculo
        inimigos[i].color = ORANGE;
        inimigos[i].active = false; // Começam inativos
    }
}
