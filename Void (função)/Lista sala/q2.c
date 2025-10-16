#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rolarDados() {
    int dado1 = (rand() % 6) + 1;
    int dado2 = (rand() % 6) + 1;
    int soma = dado1 + dado2;
    printf("Soma dos dados %d + %d = %d\n", dado1, dado2, soma);
    return soma;
}

int main() {
    srand(time(NULL));

    int soma_atual;
    int ponto = 0;
    int status_jogo = 0;

    soma_atual = rolarDados();

    switch (soma_atual) {
        case 7:
        case 11:
            status_jogo = 1;
            break;
        case 2:
        case 3:
        case 12:
            status_jogo = 2;
            break;
        default:
            ponto = soma_atual;
            printf("O ponto e %d\n", ponto);
            break;
    }

    while (status_jogo == 0) {
        soma_atual = rolarDados();
        if (soma_atual == ponto) {
            status_jogo = 1;
        } else if (soma_atual == 7) {
            status_jogo = 2;
        }
    }

    if (status_jogo == 1) {
        printf("O jogador ganhou :)\n");
    } else {
        printf("O jogador perdeu :(\n");
    }

    return 0;
}