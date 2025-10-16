#include <stdio.h>

void imprimePares(int n) {
    printf("Os %d primeiros numeros pares sao: ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i * 2);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);
    if (n > 0) {
        imprimePares(n);
    }
    return 0;
}