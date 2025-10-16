#include <stdio.h>
#include <string.h>
#include <ctype.h>

void processar_palavras(char palavras[][20], int N) {
    printf("Palavras modificadas: ");
    for (int i = 0; i < N; i++) {
        char palavra[20];
        strcpy(palavra, palavras[i]);
        int len = strlen(palavra);
        char original[20];
        strcpy(original, palavra);

        if (len > 1 && tolower(palavra[0]) == tolower(palavra[len - 1])) {
            for (int j = 1; j < len - 1; j++) {
                palavra[j] = toupper(palavra[j]);
            }
        } 
        else if (len > 5) {
            for (int j = 0; j < len; j++) {
                char c = tolower(palavra[j]);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    palavra[j] = '*';
                }
            }
        } 
        else if (len < 3) {
            strcat(palavra, original);
        }
        
        printf("%s", palavra);
        if (i < N - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    char palavras[4][20] = {"level", "algorithm", "hi", "wow"};
    int N = 4;
    
    processar_palavras(palavras, N);

    return 0;
}