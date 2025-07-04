#include "game.h"

int main(void)
{
    int screenWidth = 1200;
    int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Jogo com Colisoes");
    SetTargetFPS(60);
    srand(time(NULL));

    char matriz[A][L];
    char mapa_arquivo[50] = {0};
    bool mapa_escolhido = false;
    Jogador jog;
    Shoot tiros[NUM_SHOOTS];
    Inimigo inimigos[MAX_INIMIGOS];
    int shootRate = 0;
    int score = 0;
    bool gameOver = false;

    Camera2D camera = { 0 };

    jog = iniciarJogador(jog);
    iniciarTiros(tiros, jog);

    while (!WindowShouldClose() && !gameOver)
    {
        if (mapa_escolhido)
        {
            movimentoJogador(&jog, matriz);

            camera.target = jog.position;

            atirar(tiros, NUM_SHOOTS, jog, &shootRate);

            for (int i = 0; i < NUM_SHOOTS; i++)
            {
                if (tiros[i].active)
                {
                    tiros[i].rec.x += tiros[i].speed.x;
                    tiros[i].rec.y -= tiros[i].speed.y;
                }
            }
            for (int i = 0; i < MAX_INIMIGOS; i++)
            {
                if (inimigos[i].active)
                {
                    movimentoInimigo(&inimigos[i], matriz);
                }
            }
            for (int i = 0; i < NUM_SHOOTS; i++) {
                if (tiros[i].active) {
                    for (int j = 0; j < MAX_INIMIGOS; j++) {
                        if (inimigos[j].active && CheckCollisionRecs(tiros[i].rec, inimigos[j].rec)) {
                            tiros[i].active = false;
                            inimigos[j].active = false;
                            score += 100;
                        }
                    }
                }
            }
            for (int i = 0; i < MAX_INIMIGOS; i++) {
                if (inimigos[i].active && CheckCollisionCircleRec((Vector2){ jog.collider.x, jog.collider.y }, jog.collider.z, inimigos[i].rec)) {
                    gameOver = true;
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
                iniciarInimigos(matriz, inimigos, MAX_INIMIGOS);

                camera.target = jog.position;
                camera.offset = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };
                camera.rotation = 0.0f;
                camera.zoom = 1.0f;
            }
        }

        BeginDrawing();
            ClearBackground(SKYBLUE);

            BeginMode2D(camera);

                if (mapa_escolhido)
                {
                    desenhar_mapa(matriz, &jog);
                    desenhar_jogador(jog);
                    desenharInimigos(inimigos, MAX_INIMIGOS);

                    for (int i = 0; i < NUM_SHOOTS; i++)
                    {
                        if (tiros[i].active)
                        {
                            DrawRectangleRec(tiros[i].rec, tiros[i].color);
                        }
                    }
                }

            EndMode2D();

            if(mapa_escolhido)
            {
                DrawText(TextFormat("SCORE: %i", score), 20, 10, 20, DARKGRAY);
            }
            else
            {
                menu(mapa_arquivo);
            }

            if (gameOver)
            {
                DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.8f));
                DrawText("GAME OVER", screenWidth/2 - MeasureText("GAME OVER", 40)/2, screenHeight/2 - 20, 40, RED);
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
