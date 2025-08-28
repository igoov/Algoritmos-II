#include <stdlib.h>
#include <stdio.h>

float nota;

int main ( ) {

    printf("Digite sua nota(0 a 10):\n");
    scanf ("%f", &nota);

    if (nota >= 9 && nota <= 10){
        printf("Conceito A");
    } else if (nota >= 7 && nota < 8.9){
        printf ("Conceito B");
    } else if (nota >= 5 && nota < 6.9){
        printf("Conceito C");
    } else if (nota >= 0 && nota < 5)
    {
        printf("Conceito D");
    }
    
    system ("PAUSE");
    return 0;
}