#include <stdio.h>

int main() {
    int nA, nB;
    printf("Digite o tamanho do vetor A: ");
    scanf("%d", &nA);
    int A[nA];
    printf("Digite os elementos do vetor A: ");
    for(int i = 0; i < nA; i++) scanf("%d", &A[i]);
    
    printf("Digite o tamanho do vetor B: ");
    scanf("%d", &nB);
    int B[nB];
    printf("Digite os elementos do vetor B: ");
    for(int i = 0; i < nB; i++) scanf("%d", &B[i]);
    
    int intersecao[nA < nB ? nA : nB];
    int k = 0;
    
    for(int i = 0; i < nA; i++) {
        for(int j = 0; j < nB; j++) {
            if(A[i] == B[j]) {
                int duplicado = 0;
                for(int l = 0; l < k; l++) {
                    if(intersecao[l] == A[i]) {
                        duplicado = 1;
                        break;
                    }
                }
                if(!duplicado) {
                    intersecao[k++] = A[i];
                }
                break;
            }
        }
    }
    
    printf("Vetor interseção: ");
    for(int i = 0; i < k; i++) {
        printf("%d ", intersecao[i]);
    }
    printf("\n");
    
    return 0;
}