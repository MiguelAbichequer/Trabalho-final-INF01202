#include "game.h"

int main(void)
{
    // --- INICIALIZA��O ---
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Jogo Finalizado e Estruturado");
    SetTargetFPS(60);

    // --- Vari�veis do Jogo ---
    char matriz[A][L];
    char mapa_arquivo[50] = {0};
    bool mapa_escolhido = false;
    Jogador jog;

    // <<--- �TIMO LUGAR PARA A INICIALIZA��O! --- >>
    // Inicializa o jogador uma �nica vez antes do jogo come�ar.
    // Recomendo mudar a fun��o para 'void iniciarJogador(Jogador *jog)'
    // e cham�-la com 'iniciarJogador(&jog);'
    jog = iniciarJogador(jog);

    // --- LOOP PRINCIPAL ---
    while (!WindowShouldClose())
    {
        // ==========================================================
        // === 1. ATUALIZA��O (L�GICA) ===
        // Aqui vai tudo que ATUALIZA o estado do jogo.
        // ==========================================================
        if (mapa_escolhido)
        {
            // Jogo est� rodando: processa o movimento do jogador.
            movimentoJogador(&jog);
        }
        else
        {
            // Menu est� ativo: checa se o jogador escolheu um mapa.
            if (menu(mapa_arquivo))
            {
                mapa_escolhido = true;
                LeMapa(mapa_arquivo, matriz);
                definirPosicaoInicial(matriz, &jog);

                // Se quisesse que o jogador come�asse em um ponto do mapa,
                // voc� poderia reiniciar a posi��o dele aqui.
                // ex: jog.position = AcharPosicaoInicial(matriz);
            }
        }

        // ==========================================================
        // === 2. DESENHO (GR�FICOS) ===
        // Aqui vai tudo que DESENHA o estado atual na tela.
        // ==========================================================
        BeginDrawing();

        ClearBackground(BLACK);

        if (mapa_escolhido)
        {
            // Jogo est� rodando: desenha o mapa e o jogador.
            desenhar_mapa(matriz, &jog);

            desenhar_jogador(jog);
        }
        else
        {
            // Menu est� ativo: desenha o menu.
            // A fun��o menu() provavelmente j� desenha o que precisa.
            // Se n�o, voc� pode adicionar comandos de desenho aqui.
            // Ex: DrawText("BEM-VINDO!", 250, 280, 50, WHITE);
        }

        EndDrawing();
    }

    // --- FINALIZA��O ---
    CloseWindow();
    return 0;
}
