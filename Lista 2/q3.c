#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int vetor[N], resultado[N];
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }
    
    int pos_par = 0;
    for(int i = 0; i < N; i++) {
        if(vetor[i] % 2 == 0) {
            resultado[pos_par++] = vetor[i];
        }
    }
    
    for(int i = 0; i < N; i++) {
        if(vetor[i] % 2 != 0) {
            resultado[pos_par++] = vetor[i];
        }
    }
    
    printf("[");
    for(int i = 0; i < N; i++) {
        printf("%d", resultado[i]);
        if(i < N-1) printf(", ");
    }
    printf("]\n");
    
    return 0;
}