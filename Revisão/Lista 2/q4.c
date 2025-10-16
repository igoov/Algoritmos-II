#include <stdio.h>

int main() {
    int nA, nB;
    scanf("%d", &nA);
    int A[nA];
    for(int i = 0; i < nA; i++) scanf("%d", &A[i]);
    
    scanf("%d", &nB);
    int B[nB];
    for(int i = 0; i < nB; i++) scanf("%d", &B[i]);
    
    int C[nA + nB];
    int i = 0, j = 0, k = 0;
    
    while(i < nA && j < nB) {
        if(A[i] < B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }
    
    while(i < nA) C[k++] = A[i++];
    while(j < nB) C[k++] = B[j++];
    
    printf("[");
    for(int i = 0; i < nA + nB; i++) {
        printf("%d", C[i]);
        if(i < nA + nB - 1) printf(", ");
    }
    printf("]\n");
    
    return 0;
}