#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char* valor;
    char* naipe;
} Carta;

void criarBaralho(Carta baralho[]) {
    char* valores[] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
    char* naipes[] = {"Paus", "Ouros", "Copas", "Espadas"};
    int index = 0;
    for (int n = 0; n < 4; n++) {
        for (int v = 0; v < 13; v++) {
            baralho[index].valor = valores[v];
            baralho[index].naipe = naipes[n];
            index++;
        }
    }
}

void exibirBaralho(Carta baralho[]) {
    for (int i = 0; i < 52; i++) {
        printf("%s de %s\n", baralho[i].valor, baralho[i].naipe);
    }
}

void embaralharBaralho(Carta baralho[]) {
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

int main() {
    Carta meuBaralho[52];
    int opcao;

    do {
        printf("\nMenu Inicial:\n");
        printf("1 - Exibir Baralho em Ordem\n");
        printf("2 - Exibir Baralho Aleatoriamente\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarBaralho(meuBaralho);
                printf("\n--- Baralho em Ordem ---\n");
                exibirBaralho(meuBaralho);
                break;
            case 2:
                criarBaralho(meuBaralho);
                embaralharBaralho(meuBaralho);
                printf("\n--- Baralho Embaralhado ---\n");
                exibirBaralho(meuBaralho);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}