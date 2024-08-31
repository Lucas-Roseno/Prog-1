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
        if (string[i] == 'T' && string[i + 1] == 'E' && string[i + 2] == 'C' && string[i + 3] == 'L' && 
        string[i + 4] == 'A' && string[i + 5] == 'D' && string[i + 6] == 'O')
        {
            strcat(string_resultado, "TECLADO OU MOUSE");
            i += 6;
            cont += 16;
        }else
        {
            string_resultado[cont] = string[i];
            cont++;
        }
    }
    printf("String resultante: %s\n", string_resultado);

    return 0;
}