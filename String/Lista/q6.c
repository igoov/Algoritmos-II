#include <stdio.h>

int main() {
    char nomeCompleto[200];
    int i = 0;
    int contador = 0;

    printf("Entrada: ");
    fgets(nomeCompleto, sizeof(nomeCompleto), stdin);

    // Percorre a string até o caractere nulo de terminação
    while (nomeCompleto[i] != '\0') {
        // Verifica se o caractere não é espaço nem quebra de linha
        if (nomeCompleto[i] != ' ' && nomeCompleto[i] != '\n') {
            contador++;
        }
        i++;
    }

    printf("Saida: %d\n", contador);

    return 0;
}