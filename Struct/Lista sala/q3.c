#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[100];
    int tentativas;
} Jogador;

int main() {
    srand(time(NULL));

    Jogador player;
    player.tentativas = 0;
    
    int numero_secreto = (rand() % 100) + 1;
    int palpite;

    printf("Digite o nome do jogador: ");
    scanf(" %[^\n]", player.nome);

    printf("Tente adivinhar o numero (entre 1 e 100)\n");

    do {
        printf("Seu palpite: ");
        scanf("%d", &palpite);
        player.tentativas++;

        if (palpite > numero_secreto) {
            printf("Seu palpite foi maior que o numero sorteado! Tente novamente.\n");
        } else if (palpite < numero_secreto) {
            printf("Seu palpite foi menor que o numero sorteado! Tente novamente.\n");
        } else {
            printf("Parabens, %s! Voce acertou o numero em %d tentativas.\n", player.nome, player.tentativas);
        }

    } while (palpite != numero_secreto);

    return 0;
}