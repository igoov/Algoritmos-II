#include <stdio.h>
#include <stdlib.h>

int main ( ){
    int n;
    int soma = 0;

    printf("Digite um numero ");
    scanf("%d", &n);

    for (int i = 1; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            soma += i;
        }
        
    }
    
    if (soma == n)
    {
        printf("E um numero perfeito\n");
    } else {
        printf("Nao e um numero perfeito\n");
    }

    system("PAUSE");
    return 0;
    
}