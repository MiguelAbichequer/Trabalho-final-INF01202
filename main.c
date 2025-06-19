#include "raylib.h"

#include "game.h"

int main()
{

    InitWindow(600, 400, "Hello_World");

    Image imagem = GenImageColor(10, 5, RED); // gerar provisoriamente uma imagem como textura.

    Texture2D texture_player = LoadTextureFromImage(imagem); // um png será carregado como textura para o jogador.

    Sprite player;

    Rectangle retangulo;

    float angulo; // ângulo de rotação do carro. Esse valor muda conforme o movimento dele.



    player.texture = texture_player;

    retangulo.x = 10.0;
    retangulo.y = 10.0;
    retangulo.width = 100;
    retangulo.height = 100;

    player.dest_rect = retangulo; // a hitbox do jogador será o retângulo informado acima.

    Rectangle source_rect = {10.0f, 10.0f, (float)player.texture.width, (float)player.texture.height}; // passagem das dimensões do retangulo de player para um vetor
    Vector2 origin = {0.0f, 0.0f}; // vetor que armazena a origem do player, sera atualizado conforme o mapa carregado.

    angulo = 0.0; // o ângulo de rotação começa com 0.0

    while(!WindowShouldClose())
    {
        // atualizar

        move_player(&player, &angulo);



        // desenhar

        BeginDrawing();

        ClearBackground(SKYBLUE);


        // player.texture: A textura a ser desenhada.
        // source_rect: A parte da textura original a ser usada.
        // player.dest_rect: Onde e com que tamanho desenhar na tela (já atualizado pelo move_player).
        // origin: Ponto de referência para rotação.
        // 0.0f: Ângulo de rotação.
        // RAYWHITE: Cor de tingimento (mantém as cores originais).

        DrawTexturePro(player.texture, source_rect, player.dest_rect, origin, angulo, RAYWHITE);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
