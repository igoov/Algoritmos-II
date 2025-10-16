#include <stdio.h>

void encontraMinimax(int matriz[5][5]) {
    int maiorElemento = matriz[0][0];
    int linhaMaior = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j] > maiorElemento) {
                maiorElemento = matriz[i][j];
                linhaMaior = i;
            }
        }
    }

    int minimax = matriz[linhaMaior][0];
    int colunaMinimax = 0;
    for (int j = 1; j < 5; j++) {
        if (matriz[linhaMaior][j] < minimax) {
            minimax = matriz[linhaMaior][j];
            colunaMinimax = j;
        }
    }

    printf("Elemento minimax: %d\n", minimax);
    printf("Posicao: linha %d, coluna %d\n", linhaMaior, colunaMinimax);
}

int main() {
    int A[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    encontraMinimax(A);

    return 0;
}