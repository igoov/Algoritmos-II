#include <stdio.h>

void transformar_matriz(int M, int N, int matriz[M][N]) {
    if (N < 2) {
        printf("A matriz precisa ter pelo menos 2 colunas.\n");
        return;
    }

    int nova_matriz[M][N];

    for (int i = 0; i < M; i++) {
        if (N >= 2) {
            nova_matriz[i][0] = matriz[i][N - 2] * matriz[i][N - 1];
        }

        nova_matriz[i][N - 1] = matriz[i][0] + matriz[i][1];

        for (int j = 1; j < N - 1; j++) {
            nova_matriz[i][j] = matriz[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", nova_matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int M = 3, N = 4;
    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    transformar_matriz(M, N, matriz);

    return 0;
}