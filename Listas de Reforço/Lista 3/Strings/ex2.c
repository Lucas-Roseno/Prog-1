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
    for (int i = 98; i < 123; i++)
    {
        if (i == 101 || i == 105 ||i == 111 || i == 117)
        {
            break;
        }
        cont_vogais++;
    }
    printf("A quantidade de consoantes na frase é %d\n", cont_vogais);

    return 0;
}