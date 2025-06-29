#include "game.h"

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

    jog = iniciarJogador(jog);


    while (!WindowShouldClose())
    {

        if (mapa_escolhido)
        {

            movimentoJogador(&jog);
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
        }
        else
        {

        }

        EndDrawing();
    }

    // --- FINALIZAÇÃO ---
    CloseWindow();
    return 0;
}
