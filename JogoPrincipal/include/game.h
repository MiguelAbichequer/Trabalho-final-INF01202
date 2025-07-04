#include "raylib.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define A 20
#define L 80
#define TAMANHO_BLOCO 20
#define PLAYER_SPEED 300
#define NUM_SHOOTS 1000
#define MAX_INIMIGOS 10

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
    Rectangle rec;
    bool active;
    Color color;
    float moveTimer;
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
void movimentoJogador(Jogador *player, char matriz[A][L]);
Jogador iniciarJogador(Jogador player);
void definirPosicaoInicial(char matriz[A][L], Jogador *player);
void iniciarTiros(Shoot tiros[], Jogador player);
void atirar(Shoot *tiro, int num_shoots, Jogador player, int *shootRate);


// Funções dos Inimigos
void iniciarInimigos(char matriz[A][L], Inimigo inimigos[], int maxInimigos);
void atualizarInimigos(Inimigo inimigos[], int totalInimigos, Vector2 posJogador, char matriz[A][L]);
void desenharInimigos(Inimigo inimigos[], int totalInimigos);
void movimentoInimigo(Inimigo *inimigo, char matriz[A][L]);
