#include "DefinirPosInicial.h"

void definirPosicaoInicial(char matriz[A][L], Jogador *player)
{
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < L; j++)
        {
            // procura pelo caractere do jogador
            if (matriz[i][j] == 'j')
            {
                player->position.x = j * TAMANHO_BLOCO + TAMANHO_BLOCO / 2.0f;
                player->position.y = i * TAMANHO_BLOCO + TAMANHO_BLOCO / 2.0f;
                return;
            }
        }
    }
}
