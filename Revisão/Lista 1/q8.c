#include <stdio.h>
#include <stdlib.h>

int main ( ){
    float altura,peso;
    int imc = 0;

    printf("Digite o seu peso: ");
    scanf("%f", &peso);

    printf("Digite a sua altura: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);
    printf("imc: ",imc);

    if (imc < 18.5)
    {
        printf("Abaixo do peso\n");
    } else if (imc < 25)
    {
        printf("Peso normal\n");
    } else if (imc < 30)
    {
        printf("Sobrepeso\n");
    } else {
         printf("Obesidade\n");
    }
    
    system("PAUSE");
    return 0;
}