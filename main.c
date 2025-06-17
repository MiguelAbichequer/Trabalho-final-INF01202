#include "raylib.h"
#include "game.h"

int main()
{

    InitWindow(600, 400, "Hello_World");
    
    Texture2D texture_player = LoadTexture("path_file.png"); // um png será carregado como textura para o jogador.
    
    Sprite player; // a estrutura sprite é definida no cabeçalho. Possui dois campos: textura e "hitbox".
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
        
        DrawTexture(player.texture, {0,0,16,16}, {0.0}, 0.0, RAYWHITE);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
