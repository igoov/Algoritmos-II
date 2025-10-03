#include <stdio.h>

int main (){
    char str1 [100];
    char str2 [100];

    printf("string 1: ");
    scanf("%s", str1);

    printf("string 2: ");
    scanf("%s", str2);

    for (int i = 0; ;i++) {
        if (str1[i] != str2[i]) {
            printf("Duas strings sao diferentes.\n");
            break;
        }

        if (str1[i] == '\0')
        {
            printf("As duas strings sao iguais.\n");
            break;
        }     
    }

    return 0;
}