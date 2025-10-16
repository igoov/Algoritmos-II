#include <stdlib.h>
#include <stdio.h>

int main() {
    float num1, num2, resultado;
    int op;

    printf("Digite o primeiro numero real:\n");
    scanf("%f", &num1);

    printf("Digite o segundo numero real:\n");
    scanf("%f", &num2);

    printf("Escolha a opcao:\n");
    printf("1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("Soma\n");
            resultado = num1 + num2;
            printf("A soma de %.2f + %.2f = %.2f\n", num1, num2, resultado);
            break;

        case 2: 
            printf("Subtracao\n");
            resultado = num1 - num2;
            printf("A subtracao de %.2f - %.2f = %.2f\n", num1, num2, resultado);
            break;

        case 3: 
            printf("Multiplicacao\n");
            resultado = num1 * num2;
            printf("A multiplicacao de %.2f * %.2f = %.2f\n", num1, num2, resultado);
            break;

        case 4: 
            printf("Divisao\n");
            if (num2 == 0) {
                printf("Erro. Divisao por zero\n");
            } else {
                resultado = num1 / num2;
                printf("A divisao de %.2f / %.2f = %.2f\n", num1, num2, resultado);
            }
            break;

        default:
            printf("Opcao invalida!\n");
    }

    system("PAUSE");
    return 0;
}
