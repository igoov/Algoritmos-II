#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int vetor[N], resultado[N];
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }
    
    for(int i = 0; i < N; i++) {
        resultado[i] = vetor[i] - vetor[N-1-i];
    }
    
    printf("[");
    for(int i = 0; i < N; i++) {
        printf("%d", resultado[i]);
        if(i < N-1) printf(", ");
    }
    printf("]\n");
    
    return 0;
}