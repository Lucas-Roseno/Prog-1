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
    char string[40] = {""}, string_vogais[] = "aeiou";

    printf("Digite uma frase: ");
    fgets(string, 30, stdin);
    string[strlen(string) - 1] = '\0';
    string_minuscula(string);

    int cont_vogais = 0;
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < strlen(string_vogais); j++)
        {
            if (string[i] == string_vogais[j])
            {
                cont_vogais++;
            }   
        }
    }

    printf("\nA quantidade de vogais na frase é %d\n", cont_vogais);

    return 0;
}