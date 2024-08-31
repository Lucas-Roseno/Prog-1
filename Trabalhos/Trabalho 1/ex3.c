// Exercício 3: O Código Secreto de Avalon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 100

char *verificar_palindromo(char *string)
{
    char string_reversa[TAM] = {""};
    int cont = 0;
    for (int i = 0; i < strlen(string); i++)
    {

        if (isalnum(string[i]))
        {
            string[cont] = tolower(string[i]);
            cont++;
        }
    }
    string[cont] = '\0';

    for (int i = 0; i < strlen(string); i++)
    {
        string_reversa[i] = string[strlen(string) - (i + 1)];
    }

    if (strcmp(string, string_reversa) == 0)
    {
        return "True";
    }
    return "False";
}

int main()
{
    char frase[TAM] = {""};
    printf("Exercício 3: O Código Secreto de Avalon\n\nDigite a frase: ");
    fgets(frase, 100, stdin);
    frase[strlen(frase) - 1] = '\0';
    verificar_palindromo(frase);
    printf("%s\n", verificar_palindromo(frase));
    return 0;
}