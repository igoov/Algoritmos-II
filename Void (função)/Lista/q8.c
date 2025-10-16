#include <stdio.h>
#include <string.h>
#include <ctype.h>

void criar_espelho(char *entrada, char separador) {
    int len = strlen(entrada);
    for (int i = 0; i < len; i++) {
        char c = entrada[i];
        char espelho;

        if (islower(c)) {
            espelho = 'a' + 'z' - c;
        } else if (isupper(c)) {
            espelho = 'A' + 'Z' - c;
        } else if (isdigit(c)) {
            espelho = '0' + '9' - c;
        } else {
            espelho = c;
        }

        printf("%c%c", c, espelho);
        if (i < len - 1) {
            printf("%c", separador);
        }
    }
    printf("\n");
}

int main() {
    char string[] = "abc 12";
    char separador = '-';

    criar_espelho(string, separador);

    return 0;
}