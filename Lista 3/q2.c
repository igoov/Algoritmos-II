#include <stdio.h>
#include <string.h>

// Programa que substitui todas as ocorrências de uma palavra em uma frase.
int main (){
    char frase[512];
    char palavra_alvo[100];
    char palavra_substituta[100];
    
    // Buffer temporário para armazenar cada palavra lida da frase.
    char palavra_atual[100];
    int i = 0, j = 0;

    // Leitura das entradas do usuário.
    printf("frase: ");
    fgets(frase,sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0'; 

    printf("palavra-alvo: ");
    scanf("%s", palavra_alvo);

    printf("palavra-substituta: ");
    scanf("%s", palavra_substituta);

    printf("SAIDA: \n");

    // Percorre a frase original, caractere por caractere.
    while (frase[i] != '\0') {
        
        // Se encontrar um espaço, apenas o imprime para manter a formatação.
        if (frase[i] == ' ') {
            printf("%c", frase[i]);
            i++;
        } else {
            // Se não for um espaço, extrai a palavra completa para o buffer 'palavra_atual'.
            j = 0;
            while (frase[i] != ' ' && frase[i] != '\0') {
                palavra_atual[j] = frase[i];
                i++;
                j++;
            }
            palavra_atual[j] = '\0';
            
            // Compara a palavra extraída com a palavra-alvo para decidir o que imprimir.
            if (strcmp(palavra_atual, palavra_alvo) == 0) {
                printf("%s", palavra_substituta);
            } else {
                printf("%s", palavra_atual);
            }
        }
    }
    
    printf("\n"); 

    return 0;
}