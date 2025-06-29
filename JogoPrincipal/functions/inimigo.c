// Inimigo.c

#include "game.h" // Contém raylib.h e math.h, tudo que precisamos.

// As outras funções (inicializarInimigos, desenharInimigos) não mudam.

/**
 * @brief Atualiza a lógica dos inimigos (IA de perseguição) SEM USAR RAYMATH.
 *
 * @param inimigos Array de inimigos.
 * @param totalInimigos A contagem de inimigos.
 * @param posJogador A posição atual do jogador.
 * @param matriz O mapa, para checagem de colisão.
 */
void atualizarInimigos(Inimigo inimigos[], int totalInimigos, Vector2 posJogador, char matriz[A][L])
{
    for (int i = 0; i < totalInimigos; i++)
    {
        if (inimigos[i].active)
        {
            // --- Início da Lógica de Vetores Manual ---

            // 1. Cálculo da Distância (substituindo Vector2Distance)
            // Encontramos a diferença nos eixos x e y
            float deltaX = posJogador.x - inimigos[i].position.x;
            float deltaY = posJogador.y - inimigos[i].position.y;
            // Usamos a fórmula de Pitágoras: a² + b² = c²
            float distancia = sqrtf(deltaX * deltaX + deltaY * deltaY);

            // A lógica de perseguição continua a mesma
            if (distancia < RAIO_DETECCAO_INIMIGO && distancia > inimigos[i].radius)
            {
                // 2. Normalização do Vetor de Direção (substituindo Vector2Normalize)
                // Um vetor normalizado tem comprimento 1. O calculamos dividindo
                // seus componentes pelo seu comprimento (a distância).
                Vector2 direcao = {0, 0};
                if (distancia > 0) // Evita divisão por zero se o inimigo e o jogador estiverem no mesmo ponto
                {
                    direcao.x = deltaX / distancia;
                    direcao.y = deltaY / distancia;
                }

                // 3. Mover o inimigo (substituindo Vector2Add e Vector2Scale)
                // Adicionamos à posição atual do inimigo o vetor de direção
                // multiplicado pela velocidade.
                Vector2 novaPos;
                novaPos.x = inimigos[i].position.x + direcao.x * VELOCIDADE_INIMIGO;
                novaPos.y = inimigos[i].position.y + direcao.y * VELOCIDADE_INIMIGO;

                // --- Fim da Lógica de Vetores Manual ---

                // A verificação de colisão com a parede permanece a mesma
                int gridX = (int)(novaPos.x / TAMANHO_BLOCO);
                int gridY = (int)(novaPos.y / TAMANHO_BLOCO);

                if (gridX >= 0 && gridX < L && gridY >= 0 && gridY < A && matriz[gridY][gridX] != 'p')
                {
                    inimigos[i].position = novaPos;
                }
            }
        }
    }
}
