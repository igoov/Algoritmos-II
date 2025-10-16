#include <stdio.h>

void formaN(int n, int matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", matriz[i][0]);
    }
    
    for (int i = 1; i < n - 1; i++) {
        printf("%d ", matriz[i][i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", matriz[i][n - 1]);
    }
    printf("\n");
}

int main() {
    int matriz1[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    formaN(5, matriz1);

    int matriz2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    formaN(3, matriz2);

    return 0;
}