// Inimigo.c

#include "game.h" // Cont�m raylib.h e math.h, tudo que precisamos.

// As outras fun��es (inicializarInimigos, desenharInimigos) n�o mudam.

/**
 * @brief Atualiza a l�gica dos inimigos (IA de persegui��o) SEM USAR RAYMATH.
 *
 * @param inimigos Array de inimigos.
 * @param totalInimigos A contagem de inimigos.
 * @param posJogador A posi��o atual do jogador.
 * @param matriz O mapa, para checagem de colis�o.
 */
void atualizarInimigos(Inimigo inimigos[], int totalInimigos, Vector2 posJogador, char matriz[A][L])
{
    for (int i = 0; i < totalInimigos; i++)
    {
        if (inimigos[i].active)
        {
            // --- In�cio da L�gica de Vetores Manual ---

            // 1. C�lculo da Dist�ncia (substituindo Vector2Distance)
            // Encontramos a diferen�a nos eixos x e y
            float deltaX = posJogador.x - inimigos[i].position.x;
            float deltaY = posJogador.y - inimigos[i].position.y;
            // Usamos a f�rmula de Pit�goras: a� + b� = c�
            float distancia = sqrtf(deltaX * deltaX + deltaY * deltaY);

            // A l�gica de persegui��o continua a mesma
            if (distancia < RAIO_DETECCAO_INIMIGO && distancia > inimigos[i].radius)
            {
                // 2. Normaliza��o do Vetor de Dire��o (substituindo Vector2Normalize)
                // Um vetor normalizado tem comprimento 1. O calculamos dividindo
                // seus componentes pelo seu comprimento (a dist�ncia).
                Vector2 direcao = {0, 0};
                if (distancia > 0) // Evita divis�o por zero se o inimigo e o jogador estiverem no mesmo ponto
                {
                    direcao.x = deltaX / distancia;
                    direcao.y = deltaY / distancia;
                }

                // 3. Mover o inimigo (substituindo Vector2Add e Vector2Scale)
                // Adicionamos � posi��o atual do inimigo o vetor de dire��o
                // multiplicado pela velocidade.
                Vector2 novaPos;
                novaPos.x = inimigos[i].position.x + direcao.x * VELOCIDADE_INIMIGO;
                novaPos.y = inimigos[i].position.y + direcao.y * VELOCIDADE_INIMIGO;

                // --- Fim da L�gica de Vetores Manual ---

                // A verifica��o de colis�o com a parede permanece a mesma
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
