#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define A 20 // altura e largura da tela
#define L 80

#include "LerMapa.c"

#define FALSE 0
#define TRUE 1



#define VEL 300 // VELOCIDADE DO CARRO

#define ROT 0.0099 // ângulo de rotação gerado pelo movimento do carro

typedef struct{
    Texture2D texture; // textura do sprite.
    Rectangle dest_rect; // hitbox do sprite.
}Sprite;


void move_player(Sprite* player, float *angulo);
void LeMapa(char nome_arq[], char matrix[A][L]);




