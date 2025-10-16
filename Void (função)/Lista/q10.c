#include <stdio.h>

void calcularSequencia(int N, int M) {
    printf("Sequência: ");
    for (int i = 0; i < M; i++) {
        long long int n_atual = N + i;
        long long int numerador = (n_atual * n_atual) + 1;
        long long int denominador = n_atual + 3;

        printf("%lld/%lld", numerador, denominador);
        if (i < M - 1) {
            printf("+");
        }
    }
    printf("\n");
}

int main() {
    int N = 1;
    int M = 3;
    
    calcularSequencia(N, M);

    return 0;
}