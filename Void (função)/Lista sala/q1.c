#include <stdio.h>

void preencherMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int verificarEsparsa(int linhas, int colunas, int matriz[linhas][colunas]) {
    int contador_zeros = 0;
    int total_elementos = linhas * colunas;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == 0) {
                contador_zeros++;
            }
        }
    }

    double percentual_zeros = ((double)contador_zeros / total_elementos) * 100.0;
    printf("Percentual de zeros: %.2f%%\n", percentual_zeros);

    if (percentual_zeros > 50.0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int linhas, colunas;

    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    int matriz[linhas][colunas];

    preencherMatriz(linhas, colunas, matriz);

    int resultado = verificarEsparsa(linhas, colunas, matriz);

    if (resultado == 1) {
        printf("A matriz e esparsa.\n");
    } else {
        printf("A matriz nao e esparsa.\n");
    }

    return 0;
}