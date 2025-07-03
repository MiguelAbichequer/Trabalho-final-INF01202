#include "game.h"

// Protótipos para funções que podem não estar em seus headers ainda
void desenhar_mapa(char matriz[][L], Jogador *player);
void desenhar_jogador(Jogador player);
int menu(char *mapa_arquivo); // Adicionei o protótipo da função menu

int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Jogo Finalizado e Estruturado");
    SetTargetFPS(60);


    char matriz[A][L];
    char mapa_arquivo[50] = {0};
    bool mapa_escolhido = false;
    Jogador jog;
    Shoot tiros[NUM_SHOOTS];
    int shootRate = 0;


    jog = iniciarJogador(jog);
    iniciarTiros(tiros, jog);


    while (!WindowShouldClose())
    {

        if (mapa_escolhido)
        {
            movimentoJogador(&jog);
            atirar(tiros, NUM_SHOOTS, jog, &shootRate);

            for (int i = 0; i < NUM_SHOOTS; i++)
            {
                if (tiros[i].active)
                {
                    tiros[i].rec.x += tiros[i].speed.x;
                    tiros[i].rec.y -= tiros[i].speed.y;
                }
            }
        }
        else
        {
            if (menu(mapa_arquivo))
            {
                mapa_escolhido = true;
                LeMapa(mapa_arquivo, matriz);
                definirPosicaoInicial(matriz, &jog);
            }
        }

        BeginDrawing();
            ClearBackground(BLACK);

            if (mapa_escolhido)
            {
                desenhar_mapa(matriz, &jog);
                desenhar_jogador(jog);

                for (int i = 0; i < NUM_SHOOTS; i++)
                {
                    if (tiros[i].active)
                    {
                        DrawRectangleRec(tiros[i].rec, tiros[i].color);
                    }
                }
            }
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
