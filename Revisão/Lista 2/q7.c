#include <stdio.h>

int main() {
    int vetor[5], S;
    printf("Digite os 5 elementos do vetor: ");
    for(int i = 0; i < 5; i++) scanf("%d", &vetor[i]);
    
    printf("Digite a soma alvo: ");
    scanf("%d", &S);
    
    int soma_linha = 0;
    for(int i = 0; i < 5; i++) soma_linha += vetor[i];
    
    int linhas = (S + soma_linha - 1) / soma_linha;
    if(linhas <= 0) linhas = 1;
    
    int soma_total = linhas * soma_linha;
    
    printf("Matriz gerada:\n");
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d ", vetor[j]);
        }
        printf("\n");
    }
    
    printf("Número de linhas: %d\n", linhas);
    printf("Soma total: %d\n", soma_total);
    
    return 0;
}