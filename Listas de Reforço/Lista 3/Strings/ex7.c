#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void string_maiusculo (char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = toupper(string[i]);
    }
    
}

int main () 
{
    char string[100] = {""}, string_cripto[100] = {""};
    printf("Digite a string que deseja criptografar: ");
    fgets(string, 100, stdin);
    string[strlen(string) - 1] = '\0';
    string_maiusculo(string);

    for (int i = 0; i < strlen(string); i++)
    {
        string_cripto[i] = string[strlen(string) - (i+1)];
    }

    printf("A string cripitografada é: \n%s\n", string_cripto);

    return 0;
}