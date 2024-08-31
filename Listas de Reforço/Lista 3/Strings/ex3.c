#include <stdio.h>
#include <string.h>
#include <ctype.h>

void string_minuscula (char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = tolower(string[i]);
    }
}

int main()
{
    char string[40] = {""};

    printf("Digite uma frase: ");
    fgets(string, 30, stdin);
    string[strlen(string) - 1] = '\0';
    string_minuscula(string);

    int cont_aula = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == 'a' && string[i + 1] == 'u' && string[i + 2] == 'l' && string[i + 3] == 'a')
        {
            cont_aula++;
        }
    }
    printf("A quantidade de de vezes que a palavra aula aparece na frase é %d \n", cont_aula);

    return 0;
}