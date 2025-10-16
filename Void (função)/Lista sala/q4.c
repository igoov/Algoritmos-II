#include <stdio.h>

void verificarTriangulo(float x, float y, float z) {
    if (x < y + z && y < x + z && z < x + y) {
        if (x == y && y == z) {
            printf("Triangulo Equilatero.\n");
        } else if (x == y || x == z || y == z) {
            printf("Triangulo Isosceles.\n");
        } else {
            printf("Triangulo Escaleno.\n");
        }
    } else {
        printf("Os valores informados nao podem formar um triangulo.\n");
    }
}

int main() {
    float x, y, z;

    printf("Digite o valor do lado X: ");
    scanf("%f", &x);
    printf("Digite o valor do lado Y: ");
    scanf("%f", &y);
    printf("Digite o valor do lado Z: ");
    scanf("%f", &z);

    verificarTriangulo(x, y, z);

    return 0;
}