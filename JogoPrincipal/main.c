#include "game.h"

int main(void)
{
    // --- INICIALIZAÇÃO ---
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Jogo Finalizado e Estruturado");
    SetTargetFPS(60);

    // --- Variáveis do Jogo ---
    char matriz[A][L];
    char mapa_arquivo[50] = {0};
    bool mapa_escolhido = false;
    Jogador jog;

    // <<--- ÓTIMO LUGAR PARA A INICIALIZAÇÃO! --- >>
    // Inicializa o jogador uma única vez antes do jogo começar.
    // Recomendo mudar a função para 'void iniciarJogador(Jogador *jog)'
    // e chamá-la com 'iniciarJogador(&jog);'
    jog = iniciarJogador(jog);

    // --- LOOP PRINCIPAL ---
    while (!WindowShouldClose())
    {
        // ==========================================================
        // === 1. ATUALIZAÇÃO (LÓGICA) ===
        // Aqui vai tudo que ATUALIZA o estado do jogo.
        // ==========================================================
        if (mapa_escolhido)
        {
            // Jogo está rodando: processa o movimento do jogador.
            movimentoJogador(&jog);
        }
        else
        {
            // Menu está ativo: checa se o jogador escolheu um mapa.
            if (menu(mapa_arquivo))
            {
                mapa_escolhido = true;
                LeMapa(mapa_arquivo, matriz);
                definirPosicaoInicial(matriz, &jog);

                // Se quisesse que o jogador começasse em um ponto do mapa,
                // você poderia reiniciar a posição dele aqui.
                // ex: jog.position = AcharPosicaoInicial(matriz);
            }
        }

        // ==========================================================
        // === 2. DESENHO (GRÁFICOS) ===
        // Aqui vai tudo que DESENHA o estado atual na tela.
        // ==========================================================
        BeginDrawing();

        ClearBackground(BLACK);

        if (mapa_escolhido)
        {
            // Jogo está rodando: desenha o mapa e o jogador.
            desenhar_mapa(matriz, &jog);

            desenhar_jogador(jog);
        }
        else
        {
            // Menu está ativo: desenha o menu.
            // A função menu() provavelmente já desenha o que precisa.
            // Se não, você pode adicionar comandos de desenho aqui.
            // Ex: DrawText("BEM-VINDO!", 250, 280, 50, WHITE);
        }

        EndDrawing();
    }

    // --- FINALIZAÇÃO ---
    CloseWindow();
    return 0;
}
