#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define COMPRIMENTO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }
}

// Função para tentar posicionar um navio no tabuleiro
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                    int linhaInicial, int colunaInicial,
                    int direcaoLinha, int direcaoColuna) {
    // Verifica se o navio cabe e não colide com outro
    for (int i = 0; i < COMPRIMENTO_NAVIO; i++) {
        int linha = linhaInicial + i * direcaoLinha;
        int coluna = colunaInicial + i * direcaoColuna;

        if (linha < 0 || linha >= TAMANHO_TABULEIRO ||
            coluna < 0 || coluna >= TAMANHO_TABULEIRO ||
            tabuleiro[linha][coluna] == NAVIO) {
            return 0; // Não é possível posicionar
        }
    }

    // Posiciona o navio
    for (int i = 0; i < COMPRIMENTO_NAVIO; i++) {
        int linha = linhaInicial + i * direcaoLinha;
        int coluna = colunaInicial + i * direcaoColuna;
        tabuleiro[linha][coluna] = NAVIO;
    }

    return 1; // Sucesso
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("=== Tabuleiro de Batalha Naval ===\n\n");

    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = água | 3 = navio\n");
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Tenta posicionar alguns navios
    posicionarNavio(tabuleiro, 2, 4, 0, 1);   // Horizontal
    posicionarNavio(tabuleiro, 5, 7, 1, 0);   // Vertical
    posicionarNavio(tabuleiro, 0, 0, 1, 1);   // Diagonal ↘
    posicionarNavio(tabuleiro, 0, 9, 1, -1);  // Diagonal ↙

    exibirTabuleiro(tabuleiro);

    return 0;
}