// game.h

#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include <stdio.h>
#include <math.h> // Essencial para a função sqrtf()
#include <string.h>

#define A 20
#define L 80
#define TAMANHO_BLOCO 20
#define PLAYER_SPEED 30
#define NUM_SHOOTS 1000

// --- Constantes dos Inimigos ---
#define MAX_INIMIGOS 10
#define VELOCIDADE_INIMIGO 100
#define RAIO_DETECCAO_INIMIGO 250.0f

// STRUCTS

typedef struct Player {
    Vector2 position;
    Vector2 speed;
    float acceleration;
    float rotation;
    Vector3 collider;
    Color color;
} Jogador;


typedef struct Inimigo {
    Vector2 position;
    float speed;
    float size;
    bool active;
    Color color;
} Inimigo;

typedef struct {
    Rectangle rec;
    Vector2 speed;
    bool active;
    Color color;
} Shoot;


//funcoes jogo
int LeMapa(char nome_arq[], char matrix[A][L]);
int menu(char nome_arquivo_mapa[]);
void desenhar_mapa(char matriz[][L], Jogador *player);


// funcoes jogador

void desenhar_jogador(Jogador player);
void movimentoJogador(Jogador *player);
Jogador iniciarJogador(Jogador player);
void definirPosicaoInicial(char matriz[A][L], Jogador *player);
void iniciarTiros(Shoot tiros[], Jogador player);
void atirar(Shoot *tiro, int num_shoots, Jogador player, int *shootRate);


// Funções dos Inimigos
void inicializarInimigos(char matriz[A][L], Inimigo inimigos[], int *totalInimigos);
void atualizarInimigos(Inimigo inimigos[], int totalInimigos, Vector2 posJogador, char matriz[A][L]);
void desenharInimigos(Inimigo inimigos[], int totalInimigos);

#endif // GAME_H
