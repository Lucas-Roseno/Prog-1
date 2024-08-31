#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

void string_maiusculo (char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = toupper(string[i]);
    }
}

int main()
{
    char string[TAM] = {""}, apoio[TAM] = {""};

    printf("Digite uma frase: ");
    fgets(string, TAM, stdin);
    string[strlen(string) - 1] = '\0';
    string_maiusculo(string);

    for (int i = 0; i < strlen(string);)
    {
        if (strncmp(&string[i], "TECLADO", 7) == 0)
        {
            strcat(apoio, "TECLADO OU MOUSE");
            i+=7;
        }else{
            char char_atual[2] = {string[i], '\0'};
            strcat(apoio, char_atual);
            i++;
        }
    }
    printf("%s\n", apoio);
    return 0;
}