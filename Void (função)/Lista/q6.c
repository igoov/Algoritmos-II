#include <stdio.h>
#include <string.h>

void rotacao_minima(char *str) {
    int n = strlen(str);
    char menor_rotacao[n + 1];
    strcpy(menor_rotacao, str);

    char temp_str[n + 1];
    strcpy(temp_str, str);

    for (int i = 1; i < n; i++) {
        char primeiro_char = temp_str[0];
        for (int j = 0; j < n - 1; j++) {
            temp_str[j] = temp_str[j + 1];
        }
        temp_str[n - 1] = primeiro_char;
        temp_str[n] = '\0';

        if (strcmp(temp_str, menor_rotacao) < 0) {
            strcpy(menor_rotacao, temp_str);
        }
    }
    printf("%s\n", menor_rotacao);
}

int main() {
    char str[] = "bca";
    rotacao_minima(str);
    return 0;
}