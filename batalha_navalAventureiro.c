#include <stdio.h>
#include <stdbool.h>
//Desafio nivel aventureiro 
#define TAM 10
#define AGUA 0
#define NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tab[TAM][TAM]) {
    printf("   ");
    for (int i = 0; i < TAM; i++) printf("%d ", i); // Cabeçalho colunas
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d  ", i); // Cabeçalho linhas
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para verificar se o posicionamento é válido (dentro do tabuleiro e sem sobreposição)
bool ehPosicaoValida(int tab[TAM][TAM], int l, int c) {
    if (l >= 0 && l < TAM && c >= 0 && c < TAM && tab[l][c] == AGUA) {
        return true;
    }
    return false;
}

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 1. Inicializar tabuleiro com 0 (Água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posicionar Quatro Navios (Valor 3)
    
    // --- NAVIO 1: Horizontal (Linha 2, Coluna 1 a 4) ---
    int hLinha = 2, hCol = 1;
    for (i = 0; i < 4; i++) {
        if (ehPosicaoValida(tabuleiro, hLinha, hCol + i)) {
            tabuleiro[hLinha][hCol + i] = NAVIO;
        }
    }

    // --- NAVIO 2: Vertical (Coluna 8, Linha 4 a 7) ---
    int vLinha = 4, vCol = 8;
    for (i = 0; i < 4; i++) {
        if (ehPosicaoValida(tabuleiro, vLinha + i, vCol)) {
            tabuleiro[vLinha + i][vCol] = NAVIO;
        }
    }

    // --- NAVIO 3: Diagonal Principal (Linha 0, Col 0 a 3) ---
    int d1Linha = 0, d1Col = 0;
    for (i = 0; i < 4; i++) {
        if (ehPosicaoValida(tabuleiro, d1Linha + i, d1Col + i)) {
            tabuleiro[d1Linha + i][d1Col + i] = NAVIO;
        }
    }

    // --- NAVIO 4: Diagonal Secundária (Linha 0, Col 9 a 6) ---
    int d2Linha = 0, d2Col = 9;
    for (i = 0; i < 4; i++) {
        if (ehPosicaoValida(tabuleiro, d2Linha + i, d2Col - i)) {
            tabuleiro[d2Linha + i][d2Col - i] = NAVIO;
        }
    }

    // 3. Exibir o Tabuleiro
    printf("--- Tabuleiro Batalha Naval 10x10 ---\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
