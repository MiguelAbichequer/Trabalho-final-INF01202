#include "MovimentoJogador.h"

void movimentoJogador(Jogador *player)
{
    if (IsKeyDown(KEY_LEFT)) player->rotation -= 5;
    if (IsKeyDown(KEY_RIGHT)) player->rotation += 5;

    player->speed.x = sin(player->rotation * DEG2RAD) * PLAYER_SPEED;
    player->speed.y = cos(player->rotation * DEG2RAD) * PLAYER_SPEED;

    if (IsKeyDown(KEY_UP))
    {
        if (player->acceleration < 1) player->acceleration += 0.02f;
    }
    else
    {
        if (player->acceleration > 0) player->acceleration -= 0.02f;
        else if (player->acceleration < 0) player->acceleration = 0;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        if (player->acceleration > 0) player->acceleration -= 0.04f;
        else if (player->acceleration < 0) player->acceleration -= 0.04f;
    }

    player->position.x += (player->speed.x * player->acceleration);
    player->position.y -= (player->speed.y * player->acceleration);
}
