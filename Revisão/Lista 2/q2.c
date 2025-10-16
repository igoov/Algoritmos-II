#include <stdio.h>

int main() {
    int matriz[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    
    int encontrado = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int menor_linha = 1;
            int maior_coluna = 1;
            
            for(int k = 0; k < 3; k++) {
                if(matriz[i][k] < matriz[i][j]) {
                    menor_linha = 0;
                    break;
                }
            }
            
            for(int k = 0; k < 3; k++) {
                if(matriz[k][j] > matriz[i][j]) {
                    maior_coluna = 0;
                    break;
                }
            }
            
            if(menor_linha && maior_coluna) {
                printf("Ponto de sela encontrado: %d\n", matriz[i][j]);
                printf("Posição: linha %d, coluna %d\n", i, j);
                encontrado = 1;
            }
        }
    }
    
    if(!encontrado) {
        printf("Não existe um ponto de sela na matriz.\n");
    }
    
    return 0;
}