#include "InicializarJogador.h"

Jogador iniciarJogador(Jogador player)
{
    float shipHeight;

    shipHeight = TAMANHO_BLOCO;

    player.position = (Vector2){0, 0};
    player.speed = (Vector2){0, 0};
    player.acceleration = 0;
    player.rotation = 0;
    player.collider = (Vector3){player.position.x + sin(player.rotation*DEG2RAD)*(shipHeight/2.5f), player.position.y - cos(player.rotation*DEG2RAD)*(shipHeight/2.5f), 12};
    player.color = LIGHTGRAY;

    return player;

}
