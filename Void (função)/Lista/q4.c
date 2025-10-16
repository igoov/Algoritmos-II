#include <stdio.h>

#define TAMANHO 10

void preencherVetor(int vetor[TAMANHO]) {
    printf("Digite os %d valores do vetor:\n", TAMANHO);
    for (int i = 0; i < TAMANHO; i++) {
        scanf("%d", &vetor[i]);
    }
}

int buscarValorAnterior(int vetor[TAMANHO], int n) {
    for (int i = TAMANHO - 1; i >= 0; i--) {
        if (vetor[i] == n) {
            if (i == 0) {
                return -1;
            }
            return vetor[i - 1];
        }
    }
    return 0;
}

int main() {
    int vetor[TAMANHO];
    int n;

    preencherVetor(vetor);

    printf("Digite o numero N a ser buscado: ");
    scanf("%d", &n);

    int resultado = buscarValorAnterior(vetor, n);

    printf("Resultado: %d\n", resultado);

    return 0;
}