#include <stdio.h>

int main() {
    float a, b, c;
    int x, negativos = 0;
    int primeiro = 1;

    printf("Digite o coeficiente a: ");
    scanf("%f", &a);
    printf("Digite o coeficiente b: ");
    scanf("%f", &b);
    printf("Digite o coeficiente c: ");
    scanf("%f", &c);

    printf("Valores de x com y positivo: ");

    for(x = -10; x <= 10; x++) {
        float y = a * x * x + b * x + c;
        
        if(y > 0) {
            if(!primeiro) {
                printf(", ");
            }
            printf("%d", x);
            primeiro = 0;
        }
        
        if(y < 0) {
            negativos++;
        }
    }

    printf("\nQuantidade de valores negativos de y: %d\n", negativos);

    return 0;
}