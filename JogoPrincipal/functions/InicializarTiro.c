#include "game.h"

void iniciarTiros(Shoot tiros[], Jogador player)
{
    for (int i = 0; i < NUM_SHOOTS; i++)
    {
        tiros[i].rec.x = player.position.x;
        tiros[i].rec.y = player.position.y;
        tiros[i].rec.width = 10;
        tiros[i].rec.height = 5;
        tiros[i].speed.x = 7;
        tiros[i].speed.y = 0;
        tiros[i].active = false;
        tiros[i].color = MAROON;
    }
}
