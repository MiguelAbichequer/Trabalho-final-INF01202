#include "raylib.h"

#include "game.h"

int main()
{

    InitWindow(600, 400, "Hello_World");

    Image imagem = GenImageColor(20, 20, RED); // gerar provisoriamente uma imagem como textura.

    Texture2D texture_player = LoadTextureFromImage(imagem); // um png será carregado como textura para o jogador.

    Sprite player;
    Rectangle retangulo;

    player.texture = texture_player;

    retangulo.x = 10.0;
    retangulo.y = 10.0;
    retangulo.width = 100;
    retangulo.height = 100;

    player.dest_rect = retangulo; // a hitbox do jogador será o retângulo informado acima.


    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(SKYBLUE);

        DrawTexturePro(player.texture, {0,0, 16,16), player.dest_rect, {0,0}, 0.0f, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
