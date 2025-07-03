#include "raylib.h"
#include "game.h"

void desenhar_jogador(Jogador player)
{
    float shipHeight;

    shipHeight = TAMANHO_BLOCO;


    Vector2 v1 = { player.position.x + sinf(player.rotation*DEG2RAD)*(shipHeight), player.position.y - cosf(player.rotation*DEG2RAD)*(shipHeight) };
    Vector2 v2 = { player.position.x - cosf(player.rotation*DEG2RAD)*(TAMANHO_BLOCO/2), player.position.y - sinf(player.rotation*DEG2RAD)*(TAMANHO_BLOCO/2) };
    Vector2 v3 = { player.position.x + cosf(player.rotation*DEG2RAD)*(TAMANHO_BLOCO/2), player.position.y + sinf(player.rotation*DEG2RAD)*(TAMANHO_BLOCO/2) };
    DrawTriangle(v1, v2, v3, MAROON);
}
