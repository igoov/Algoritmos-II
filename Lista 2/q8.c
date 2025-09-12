#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    if(N <= 0 || M <= 0) {
        printf("Erro: matriz vazia\n");
        return 1;
    }
    
    int matriz[N][M];
    int max = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
            if(matriz[i][j] < 0 || matriz[i][j] > 100) {
                printf("Erro: número fora do intervalo\n");
                return 1;
            }
            if(matriz[i][j] > max) max = matriz[i][j];
        }
    }
    
    int contagem[max+1];
    for(int i = 0; i <= max; i++) contagem[i] = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            contagem[matriz[i][j]]++;
        }
    }
    
    printf("Matriz lida:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("Contagens:\n");
    for(int i = 0; i <= max; i++) {
        if(contagem[i] > 0) {
            printf("[%d] : %d\n", i, contagem[i]);
        }
    }
    
    return 0;
}