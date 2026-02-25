#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    
    // Inicializa o tabuleiro com 0 (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    int navio[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais (podem ser alteradas aqui)
    int hLinha = 2, hColuna = 2; // Navio Horizontal
    int vLinha = 5, vColuna = 5; // Navio Vertical

    // 1. Posicionamento do Navio Horizontal
    if (hColuna + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[hLinha][hColuna + j] = navio[j];
        }
    }

    // 2. Posicionamento do Navio Vertical com validação de sobreposição
    int sobreposicao = 0;
    if (vLinha + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[vLinha + i][vColuna] != 0) sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[vLinha + i][vColuna] = navio[i];
            }
        }
    }


        // 3. Exibição do Tabuleiro
     printf("TABULEIRO BATALHA NAVAL\n");
     printf("A B C D E F G H I J \n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    } 
    return 0;
}
