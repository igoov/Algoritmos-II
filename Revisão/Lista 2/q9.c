#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int matriz[N][M];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("Borda da matriz: ");
    
    for(int j = 0; j < M; j++) {
        printf("%d", matriz[0][j]);
        if(j < M-1 || N > 1) printf(", ");
    }
    
    for(int i = 1; i < N-1; i++) {
        printf("%d", matriz[i][M-1]);
        if(i < N-2 || M > 1) printf(", ");
    }
    
    if(N > 1) {
        for(int j = M-1; j >= 0; j--) {
            printf("%d", matriz[N-1][j]);
            if(j > 0 || N > 2) printf(", ");
        }
    }
    
    if(M > 1 && N > 2) {
        for(int i = N-2; i >= 1; i--) {
            printf("%d", matriz[i][0]);
            if(i > 1) printf(", ");
        }
    }
    
    printf("\n");
    
    return 0;
}