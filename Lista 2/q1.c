#include <stdio.h>
#include <stdlib.h>

int main () {
    int vetor [10];
    int novo [5];

    printf("Digite 10 numeros inteiros: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < 5; i++){
        novo[i] = vetor[i] + vetor[9 - i];
    }

    printf("Novo vetor: [");
    for (int i = 0; i < 5; i++){
        printf("%d", novo[i]);
        if (i < 4) {
            printf(",");
        }
        
    }
    
    printf("]\n");
    
    system("PAUSE");
    return 0;
    
}