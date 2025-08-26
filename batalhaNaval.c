#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Cria o tabuleiro 10x10 e preenche com água
    int tabuleiro[TAMANHO][TAMANHO];

    for (int linha = 0; linha < TAMANHO; linha++) {
        for (int coluna = 0; coluna < TAMANHO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // Define a posição inicial do navio horizontal
    int inicioLinhaHorizontal = 2;
    int inicioColunaHorizontal = 4;

    // Define a posição inicial do navio vertical
    int inicioLinhaVertical = 5;
    int inicioColunaVertical = 7;

    // Verifica se o navio horizontal cabe no tabuleiro
    if (inicioColunaHorizontal + TAMANHO_NAVIO <= TAMANHO) {
        int podeColocar = 1;

        // Verifica se já tem navio nas posições desejadas
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[inicioLinhaHorizontal][inicioColunaHorizontal + i] == NAVIO) {
                podeColocar = 0;
                break;
            }
        }

        // Se estiver tudo certo, posiciona o navio horizontal
        if (podeColocar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[inicioLinhaHorizontal][inicioColunaHorizontal + i] = NAVIO;
            }
        }
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (inicioLinhaVertical + TAMANHO_NAVIO <= TAMANHO) {
        int podeColocar = 1;

        // Verifica se já tem navio nas posições desejadas
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[inicioLinhaVertical + i][inicioColunaVertical] == NAVIO) {
                podeColocar = 0;
                break;
            }
        }

        // Se estiver tudo certo, posiciona o navio vertical
        if (podeColocar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[inicioLinhaVertical + i][inicioColunaVertical] = NAVIO;
            }
        }
    }

    // Exibe o tabuleiro no console
    printf("=== Tabuleiro de Batalha Naval ===\n\n");

    for (int linha = 0; linha < TAMANHO; linha++) {
        for (int coluna = 0; coluna < TAMANHO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = água | 3 = navio\n");

    return 0;
}