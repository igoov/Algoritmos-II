#include <stdio.h>
#include <stdlib.h>

int main ( ) {

    int valor;
    int n100, n50, n20, n10, n5;

    printf("Digite o valor: ");
    scanf("%d", &valor);

    if (valor <= 0) {
        printf("Erro! Digite um valor positivo.");
    } else if (valor % 5 != 0) {
        printf("Erro.");
    } else
    {
        n100 = valor / 100;
        valor = valor % 100;

        n50 = valor / 50;
        valor = valor % 50;

        n20 = valor / 20;
        valor = valor % 20;

        n10 = valor / 10;
        valor = valor % 10;

        n5 = valor / 5;

        printf("Notas de 100: %d\n", n100);
        printf("Notas de 50: %d\n", n50);
        printf("Notas de 20: %d\n", n20);
        printf("Notas de 10: %d\n", n10);
        printf("Notas de 5: %d\n", n10);
    }
    
    system("PAUSE");
    return 0;
    
}