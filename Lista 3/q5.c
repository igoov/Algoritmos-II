#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char mensagem[256];
    char mensagemCriptografada[256];
    int chave, i;

    printf("Digite a mensagem: ");
    fgets(mensagem, sizeof(mensagem), stdin);
    mensagem[strcspn(mensagem, "\n")] = 0;

    printf("Digite a chave: ");
    scanf("%d", &chave);

    for (i = 0; mensagem[i] != '\0'; i++) {
        char ch = mensagem[i];

        if (islower(ch)) {
            // Lógica para letras minúsculas
            ch = 'a' + (ch - 'a' + chave) % 26;
             if (ch < 'a') { // Garante que o resultado permaneça no alfabeto
                ch += 26;
            }
        } else if (isupper(ch)) {
            // Lógica para letras maiúsculas
            ch = 'A' + (ch - 'A' + chave) % 26;
            if (ch < 'A') { // Garante que o resultado permaneça no alfabeto
                ch += 26;
            }
        }
        // Números, espaços e símbolos não são alterados
        mensagemCriptografada[i] = ch;
    }
    mensagemCriptografada[i] = '\0'; // Adiciona o terminador nulo

    printf("Mensagem criptografada: %s\n", mensagemCriptografada);

    return 0;
}