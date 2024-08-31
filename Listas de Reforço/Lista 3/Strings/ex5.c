#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

void string_maiuscula(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = toupper(string[i]);
    }
}

int main()
{
    char string[TAM] = {""}, string_resultado[TAM] = {""};
    printf("Digite uma frase: ");
    fgets(string, TAM, stdin);
    string[strlen(string) - 1] = '\0';
    string_maiuscula(string);

    int cont = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == 'A' && string[i + 1] == 'L' && string[i + 2] == 'U' && string[i + 3] == 'N' && string[i + 4] == 'O')
        {
            strcat(string_resultado, "ESTUDANTE");
            i += 4;
            cont += 9;
        }
        else if (string[i] == 'E' && string[i + 1] == 'S' && string[i + 2] == 'C' && string[i + 3] == 'O' &&
                 string[i + 4] == 'L' && string[i + 5] == 'A')
        {
            strcat(string_resultado, "UNIVERSIDADE");
            i += 5;
            cont += 12;
        }else
        {
            string_resultado[cont] = string[i];
            cont++;
        }
    }
    printf("String resultante: %s\n", string_resultado);

    return 0;
}