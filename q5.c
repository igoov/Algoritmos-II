#include <stdio.h>
#include <stdlib.h>

int main() {
    int decimal, resto, octal = 0, posicao = 1;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &decimal);

    if (decimal <= 0) {
        printf("Erro! O numero deve ser positivo.");
        return 1;
    } 

    while (decimal > 0) {
        resto = decimal % 8;
        octal = resto * posicao + octal;
        decimal = decimal / 8;
        posicao = posicao * 10;
    }

    printf("Numero Octal: %d\n", octal);
    return 0;
}