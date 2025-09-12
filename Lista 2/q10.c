#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int matriz[N][N];
    int centro = (N-1)/2;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i <= centro && j >= centro - i && j <= centro + i) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}