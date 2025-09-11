#include <stdio.h>
#include <stdlib.h>

int main () {
    int numero, soma = 0;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Erro! Digite um numero positivo.");
        return 1;
    }

    for (int i = 2; i <= numero; i+=2)
    {
        soma += i;
    }
    
    printf("\nA soma dos numeros pares ate %d e %d\n", numero, soma);
    system("PAUSE");
    return 0;
}