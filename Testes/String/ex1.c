#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string1[30] = "", string2[30] = "";
    printf("Digite a primeira string: ");
    fgets(string1, 30, stdin);
    string1[strlen(string1) - 1] = '\0';
    printf("Digite a segunda string: ");
    fgets(string2, 30, stdin);
    string2[strlen(string2) - 1] = '\0';
    printf("Primeira string = '%s' ", string1);
    printf("\nSegunda string = '%s' \n", string2);
    return 0;
}