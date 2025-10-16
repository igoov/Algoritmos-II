#include <stdio.h>
#include <stdlib.h>

int main (){
    int n;
    int resultado;

    printf("Digite um numero: ");
    scanf("%d", &n);

    for (int i = n; i >= 0; i--)
    {
        resultado = n - i;
        printf("%d - %d = %d\n", n, i, resultado);
    } 
    
    system("PAUSE");
    return 0;
    
}