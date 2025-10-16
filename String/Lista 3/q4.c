#include <stdio.h>
#include <string.h>

int main() {
    char frase[256];
    int i;
    int inicio_palavra = 0; // Índice que marca o começo da palavra atual.
    int len;

    // Leitura da frase digitada pelo usuário.
    printf("Frase digitada: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0'; // Remove o '\n' do final

    len = strlen(frase);

    // Percorre a string inteira. O laço vai até 'len' para incluir o caractere nulo '\0'
    // como um sinal de que a última palavra terminou.
    for (i = 0; i <= len; i++) {
        
        // Se encontrar um espaço ou o final da string, significa que uma palavra terminou.
        if (frase[i] == ' ' || frase[i] == '\0') {
            
            // Os limites da palavra são 'inicio_palavra' e 'i - 1'.
            int esquerda = inicio_palavra;
            int direita = i - 1;

            // Laço para inverter os caracteres dentro dos limites da palavra.
            while (esquerda < direita) {
                // Troca o caractere da esquerda pelo da direita.
                char temp = frase[esquerda];
                frase[esquerda] = frase[direita];
                frase[direita] = temp;

                // Move os índices para o centro da palavra.
                esquerda++;
                direita--;
            }

            // Atualiza o índice para o início da próxima palavra.
            inicio_palavra = i + 1;
        }
    }

    // Exibe o resultado final.
    printf("Frase invertida: %s\n", frase);

    return 0;
}