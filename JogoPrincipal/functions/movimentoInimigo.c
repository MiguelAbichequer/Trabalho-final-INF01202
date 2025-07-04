#include "inimigo.h"

#define INIMIGO_MOVE_INTERVAL 0.3f

void movimentoInimigo(Inimigo *inimigo, char matriz[A][L])
{
    inimigo->moveTimer += GetFrameTime();

    if (inimigo->moveTimer >= INIMIGO_MOVE_INTERVAL)
    {
        inimigo->moveTimer = 0;

        int currentGridX = inimigo->position.x / TAMANHO_BLOCO;
        int currentGridY = inimigo->position.y / TAMANHO_BLOCO;
        int nextGridX = currentGridX;
        int nextGridY = currentGridY;

        int direction = rand() % 4; // direção aleatória: 0:Direita, 1:Esquerda, 2:Cima, 3:Baixo

        switch (direction)
        {
            case 0: nextGridX++; break;
            case 1: nextGridX--; break;
            case 2: nextGridY--; break;
            case 3: nextGridY++; break;
        }

        if (nextGridX >= 0 && nextGridX < L && nextGridY >= 0 && nextGridY < A)
        {
            // O inimigo só se move se o próximo bloco for um caminho livre
            if (matriz[nextGridY][nextGridX] == ' ' || matriz[nextGridY][nextGridX] == 'j')
            {
                inimigo->position.x = nextGridX * TAMANHO_BLOCO + TAMANHO_BLOCO / 2.0f;
                inimigo->position.y = nextGridY * TAMANHO_BLOCO + TAMANHO_BLOCO / 2.0f;
            }
        }
    }
    inimigo->rec.x = inimigo->position.x - TAMANHO_BLOCO / 2.0f;
    inimigo->rec.y = inimigo->position.y - TAMANHO_BLOCO / 2.0f;
}
