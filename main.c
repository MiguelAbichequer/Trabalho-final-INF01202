#include "raylib.h"

#include "game.h"

int main()
{

    InitWindow(1200, 800, "Hello_World");

    Image imagem = GenImageColor(10, 5, RED); // gerar provisoriamente uma imagem como textura.

    Texture2D texture_player = LoadTextureFromImage(imagem); // um png será carregado como textura para o jogador.

    Sprite player;

    Rectangle retangulo;

    float angulo;

    // Variáves para a seleção e construção do mapa:

    int mapa_escolhido = FALSE;
    int mapa;
    char nome_arquivo_mapa[100];
    char matrix[A][L];
    int i, j, k;



    player.texture = texture_player;

    retangulo.x = 10.0;
    retangulo.y = 10.0;
    retangulo.width = 30;
    retangulo.height = 40;

    player.dest_rect = retangulo; // a hitbox do jogador será o retângulo informado acima.

    Rectangle source_rect = {10.0f, 10.0f, (float)player.texture.width, (float)player.texture.height}; // passagem das dimensões do retangulo de player para um vetor
    Vector2 origin = {0.0f, 0.0f}; // vetor que armazena a origem do player, sera atualizado conforme o mapa carregado.

    angulo = 0.0; // o ângulo de rotação começa com 0.0

    while (!WindowShouldClose())
    {

        // ATUALIZAÇÃO

        if (mapa_escolhido == FALSE) // ESTAMOS NO MENU
        {
            // Lógica do menu: verificar se uma tecla foi pressionada
            if (IsKeyDown(KEY_KP_1) || IsKeyDown(KEY_ONE))
            {

                mapa_escolhido = TRUE; // Muda para o estado de "jogando"

                strcpy(nome_arquivo_mapa, "mapa1.txt");

            }
            if (IsKeyDown(KEY_KP_2) || IsKeyDown(KEY_TWO))
            {

                mapa_escolhido = TRUE;

                strcpy(nome_arquivo_mapa, "mapa2.txt");

            }
            if (IsKeyDown(KEY_KP_3) || IsKeyDown(KEY_THREE))
            {

                mapa_escolhido = TRUE;

                strcpy(nome_arquivo_mapa, "mapa3.txt");
            }
        }
        else // ESTAMOS JOGANDO
        {

            move_player(&player, &angulo);

        }


        // DESENHO

        BeginDrawing();
        ClearBackground(SKYBLUE);

        if (mapa_escolhido == FALSE) // DESENHANDO O MENU
        {
            DrawText("SELECIONE UM MAPA", 20, 20, 40, DARKGREEN);
            DrawText("1 - Mapa Facil", 20, 70, 30, DARKGREEN);
            DrawText("2 - Mapa Medio", 20, 110, 30, DARKGREEN);
            DrawText("3 - Mapa Dificil", 20, 150, 30, DARKGREEN);
        }
        else // DESENHANDO O JOGO
        {

            LeMapa(nome_arquivo_mapa, matrix);

            for(i = 0; i < A; i++)
            {
                for(j = 0; j < L; j++)
                {
                    if(matrix[i][j] == 'p')
                    {
                        DrawTexture(texture_player, j*30,i*40, GREEN);
                    }
                }

            }

            DrawTexturePro(player.texture, source_rect, player.dest_rect, origin, angulo, RAYWHITE);


        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
