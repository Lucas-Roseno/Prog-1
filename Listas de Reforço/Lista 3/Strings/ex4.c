#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

void string_minuscula(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = tolower(string[i]);
    }
}

int main()
{
    char string[TAM] = {""}, palavra[TAM] = {""};

    printf("Digite uma frase: ");
    fgets(string, TAM, stdin);
    string[strlen(string) - 1] = '\0';
    string_minuscula(string);

    printf("Digite uma frase: ");
    fgets(palavra, TAM, stdin);
    palavra[strlen(palavra) - 1] = '\0';
    string_minuscula(palavra);


    int cont_palavra = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        int cont = i;
        for (int j = 0; j < strlen(palavra); j++)
        {
            if (string[cont] == palavra[j])
            {
                cont++;
                continue;
            }
            else
            {
                cont = i;
                break;
            }
        }
        if (cont != i)
        {
            cont_palavra++;
        } 
    }
    printf("A quantidade de de vezes que a palavra %s aparece na frase é %d \n", palavra, cont_palavra);

    return 0;
}