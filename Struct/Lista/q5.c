#include <stdio.h>

typedef struct {
    char nome[100];
    float voltas[3];
    float media;
} Piloto;

void calcularMedia(Piloto* p) {
    p->media = (p->voltas[0] + p->voltas[1] + p->voltas[2]) / 3.0;
}

void ordenarPilotos(Piloto pilotos[], int n) {
    Piloto temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pilotos[j].media > pilotos[j + 1].media) {
                temp = pilotos[j];
                pilotos[j] = pilotos[j + 1];
                pilotos[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Insira a quantidade de pilotos: ");
    scanf("%d", &n);

    Piloto pilotos[n];

    for (int i = 0; i < n; i++) {
        printf("\nPiloto %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", pilotos[i].nome);
        printf("Volta 1: ");
        scanf("%f", &pilotos[i].voltas[0]);
        printf("Volta 2: ");
        scanf("%f", &pilotos[i].voltas[1]);
        printf("Volta 3: ");
        scanf("%f", &pilotos[i].voltas[2]);
        calcularMedia(&pilotos[i]);
    }

    ordenarPilotos(pilotos, n);

    printf("\n--- Tabela ---\n");
    for (int i = 0; i < n; i++) {
        printf("Pos: %d\n", i + 1);
        printf("Nome: %s\n", pilotos[i].nome);
        printf("Media: %f\n", pilotos[i].media);
    }

    return 0;
}