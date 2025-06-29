#include "DesenharMapa.h"

void desenhar_mapa(char matriz[][L], Jogador *player)
{
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < L; j++)
        {
            int x = j * TAMANHO_BLOCO;
            int y = i * TAMANHO_BLOCO;

            switch (matriz[i][j])
            {
                case 'p':
                    DrawRectangle(x, y, TAMANHO_BLOCO, TAMANHO_BLOCO, GRAY);
                    DrawRectangleLines(x, y, TAMANHO_BLOCO, TAMANHO_BLOCO, DARKGRAY);
                    break;
                case 'i':
                    break;
                case 'j':
                    break; //outra funcao devera desenhar o jogador na tela
                case ' ':
                    DrawRectangle(x, y, TAMANHO_BLOCO, TAMANHO_BLOCO, LIGHTGRAY);
                    break;
                default:
                    break;
            }
        }
    }
}
// a função deverá desenhar o mapa correspondente.
