#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define EFEITO 5
#define TAM_HAB 5

// Inicializa o tabuleiro com água
void limparTabuleiro(int mapa[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            mapa[i][j] = AGUA;
}

// Tenta colocar um navio no tabuleiro
int colocarNavio(int mapa[TAM][TAM], int lin, int col, int dirLin, int dirCol) {
    for (int k = 0; k < 3; k++) {
        int x = lin + k * dirLin;
        int y = col + k * dirCol;

        if (x < 0 || x >= TAM || y < 0 || y >= TAM || mapa[x][y] == NAVIO)
            return 0;
    }

    for (int k = 0; k < 3; k++) {
        int x = lin + k * dirLin;
        int y = col + k * dirCol;
        mapa[x][y] = NAVIO;
    }

    return 1;
}

// Exibe o tabuleiro no console
void mostrarTabuleiro(int mapa[TAM][TAM]) {
    printf("\n=== Batalha Naval ===\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", mapa[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = água | 3 = navio | 5 = habilidade\n");
}

// Cria matriz em formato de cone
void gerarCone(int mat[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            mat[i][j] = (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i) ? 1 : 0;
        }
    }
}

// Cria matriz em formato de cruz
void gerarCruz(int mat[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            mat[i][j] = (i == TAM_HAB / 2 || j == TAM_HAB / 2) ? 1 : 0;
        }
    }
}

// Cria matriz em formato de octaedro (losango)
void gerarOctaedro(int mat[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int dist = abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2);
            mat[i][j] = (dist <= TAM_HAB / 2) ? 1 : 0;
        }
    }
}

// Aplica uma habilidade no tabuleiro
void aplicarEfeito(int mapa[TAM][TAM], int hab[TAM_HAB][TAM_HAB], int centroX, int centroY) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int x = centroX - TAM_HAB / 2 + i;
            int y = centroY - TAM_HAB / 2 + j;

            if (x >= 0 && x < TAM && y >= 0 && y < TAM && hab[i][j] == 1 && mapa[x][y] == AGUA)
                mapa[x][y] = EFEITO;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    limparTabuleiro(tabuleiro);

    // Posiciona alguns navios
    colocarNavio(tabuleiro, 2, 4, 0, 1);   // horizontal
    colocarNavio(tabuleiro, 5, 7, 1, 0);   // vertical
    colocarNavio(tabuleiro, 0, 0, 1, 1);   // diagonal ↘
    colocarNavio(tabuleiro, 0, 9, 1, -1);  // diagonal ↙

    // Gera habilidades
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplica efeitos no tabuleiro
    aplicarEfeito(tabuleiro, cone, 3, 3);
    aplicarEfeito(tabuleiro, cruz, 6, 6);
    aplicarEfeito(tabuleiro, octaedro, 8, 2);

    // Mostra resultado final
    mostrarTabuleiro(tabuleiro);

    return 0;
}