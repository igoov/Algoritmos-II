#include <stdio.h>
#include <string.h>

union Dados {
    int inteiro;
    float real;
    char texto[4];
};

int main() {
    union Dados d;

    // Atribuindo inteiro
    d.inteiro = 100;
    printf("Apos atribuir inteiro:\n");
    printf("inteiro = %d\n", d.inteiro);
    printf("real = %f\n", d.real);
    printf("texto = %s\n\n", d.texto);

    // Atribuindo real
    d.real = 5.5;
    printf("Apos atribuir real:\n");
    printf("inteiro = %d\n", d.inteiro);
    printf("real = %.2f\n", d.real);
    printf("texto = %s\n\n", d.texto);
    
    // Atribuindo texto
    strcpy(d.texto, "ABC");
    printf("Apos atribuir texto:\n");
    printf("inteiro = %d\n", d.inteiro);
    printf("real = %f\n", d.real);
    printf("texto = %s\n", d.texto);

    return 0;
}