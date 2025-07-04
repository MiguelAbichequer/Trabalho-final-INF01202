#include "MovimentoJogador.h"

void movimentoJogador(Jogador *player, char matriz[A][L])
{
    if (IsKeyDown(KEY_LEFT)) player->rotation -= 5;
    if (IsKeyDown(KEY_RIGHT)) player->rotation += 5;

    player->speed.x = sin(player->rotation * DEG2RAD) * PLAYER_SPEED; // é a direção seno do movmento
    player->speed.y = cos(player->rotation * DEG2RAD) * PLAYER_SPEED; // é a direção cosseno do movimento

    if (IsKeyDown(KEY_UP)) {
        if (player->acceleration < 1) player->acceleration += 0.04f;
    } else {
        if (player->acceleration > 0) player->acceleration -= 0.04f;
        else if (player->acceleration < 0) player->acceleration = 0;
    }
    if (IsKeyDown(KEY_DOWN)) {
        if (player->acceleration > 0) player->acceleration -= 0.06f;
        else if (player->acceleration < 0) player->acceleration = 0;
    }

    Vector2 proximaPosicao = player->position;
    proximaPosicao.x += (player->speed.x * player->acceleration * GetFrameTime());
    proximaPosicao.y -= (player->speed.y * player->acceleration * GetFrameTime());

    int gridX = proximaPosicao.x / TAMANHO_BLOCO;
    int gridY = proximaPosicao.y / TAMANHO_BLOCO;

    if (gridX >= 0 && gridX < L && gridY >= 0 && gridY < A && matriz[gridY][gridX] != 'p')
    {
        player->position = proximaPosicao;
    }
    else
    {
        player->acceleration = 0;
    }
    player->collider.x = player->position.x;
    player->collider.y = player->position.y;
}
