#include "Menu.h"

int menu(char nome_arquivo_mapa[])
{
    DrawText("SELECIONE UM MAPA", 20, 20, 40, DARKGREEN);
    DrawText("1 - Mapa Facil",    20, 70, 30, DARKGREEN);
    DrawText("2 - Mapa Medio",    20, 110, 30, DARKGREEN);
    DrawText("3 - Mapa Dificil",  20, 150, 30, DARKGREEN);

    if (IsKeyPressed(KEY_KP_1) || IsKeyPressed(KEY_ONE)) {
        strcpy(nome_arquivo_mapa, "mapa1.txt");
        return true;
    } else if (IsKeyPressed(KEY_KP_2) || IsKeyPressed(KEY_TWO)) {
        strcpy(nome_arquivo_mapa, "mapa2.txt");
        return true;
    } else if (IsKeyPressed(KEY_KP_3) || IsKeyPressed(KEY_THREE)) {
        strcpy(nome_arquivo_mapa, "mapa3.txt");
        return true;
    }
}
