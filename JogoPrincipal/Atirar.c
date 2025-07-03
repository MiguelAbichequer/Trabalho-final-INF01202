#include "game.h"
#include <math.h>

#define VELOCIDADE_TIRO 7.0f

void atirar(Shoot *tiro, int num_shoots, Jogador player, int *shootRate)
{
    if (IsKeyDown(KEY_SPACE)) {
        (*shootRate)++;

        if (*shootRate % 15 == 0) {
            for (int i = 0; i < num_shoots; i++) {
                if (!tiro[i].active) {

                    tiro[i].active = true;

                    tiro[i].rec.x = player.position.x;
                    tiro[i].rec.y = player.position.y;

                    tiro[i].speed.x = sin(player.rotation * DEG2RAD) * VELOCIDADE_TIRO;
                    tiro[i].speed.y = cos(player.rotation * DEG2RAD) * VELOCIDADE_TIRO;

                    break;
                }
            }
        }
    } else {
        *shootRate = 0;
    }
}
