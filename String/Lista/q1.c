#include <stdio.h>
#include <string.h> 

int main () {
    char str1[100], str2[100];
    //para contar o alfabeto de 0 a 26 letras
    int contagem[26] = {0}; 
    int i;

    //leitura de strinh
    printf("string1: ");
    scanf("%s", str1);

    printf("string2: ");
    scanf("%s", str2);

    // verifica se as string tem o msm tamanho
    if (strlen(str1) != strlen(str2)) {
        printf("%s e %s nao sao anagramas!\n", str1, str2);
        return 0;
    }

    // adiona a letra na primeira string adicionando
    for (i = 0; str1[i] != '\0'; i++) {
        contagem[str1[i] - 'a']++;
    }

    // remove a letra da segunda string adicionanda 
    for (i = 0; str2[i] != '\0'; i++) {
        contagem[str2[i] - 'a']--;
    }

    // Verifica se o resultado da contagem e zero para todas as letras.
    // Se algum valor for diferente de zero, as strings nao sao anagramas.
    for (i = 0; i < 26; i++) {
        if (contagem[i] != 0){
            printf("%s e %s nao sao anagramas!\n", str1, str2);
            return 0;
        }
    }
    
    // Se o programa passou por todas as verificacoes, as strings sao anagramas.
    printf("%s e %s sao anagramas!\n", str1, str2);
    
    return 0;
}