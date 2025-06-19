#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define A 20
#define L 80 // altura e largura da tela

typedef struct{
    Texture2D texture; // textura do sprite.
    Rectangle dest_rect; // hitbox do sprite.
}Sprite;


void move_player(Sprite* player);
void LeMapa(char nome_arq[], char matrix[A][L]);


